/*
COMPLETE SINGLE LINKED LIST 
*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
void insertBeg(int a);
void insertAtLoc(int n, int l);
void insertAtLast(int n);
void deleteBeg();
void dltSpc(int l);
void deleteLast();
int countNode();
void sort();
void search(int);
void display();

void main()
{
    int ch, val, loc;
    while (1)
    {
        printf("\n\nEnter your choice:-\n\t1.  Insert at front\t\t2.  Insert at specific position\t\t3.  Insert at last\n\t4.  Delete from front\t\t5.  Delete from specific position\t6.  Delete from last\n\t7.  Count total nodes\t\t8.  Sorting the data\t\t\t9.  Searching an element\n\t10. Display\t\t\t0.  Exit\n\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter Data:  ");
            scanf("%d", &val);
            insertBeg(val);   
            break;

        case 2:
            printf("Enter Data:  ");
            scanf("%d", &val);
            printf("Enter location to insert:  ");
            scanf("%d", &loc);
            insertAtLoc(val, loc);
            break;
            
        case 3:
            printf("Enter Data:  ");
            scanf("%d", &val);
            insertAtLast(val);
            break;

        case 4:
            deleteBeg();
            break;
        
        case 5:
            printf("Enter location to remove node from LL: ");
            scanf("%d", &loc);
            dltSpc(loc);            
            break;
        
        case 6:
            deleteLast();
            break;
        
        case 7:
            printf("\nTotal nodes in LL: %d", countNode());
            break;

        case 8:
            sort();
            break;

        case 9:
            printf("Enter a value to search: ");
            scanf("%d", &val);
            search(val);
            break;
        
        case 10:
            display();
            break;
        
        case 0:
            exit(0);
            break;

        default:
            printf("Enter a valid choice !!");
            break;
        }
    }
}

void insertBeg(int a)
{
    struct node *temp,*ptr;
    temp= (struct node *)malloc(sizeof(struct node));
    temp->data=a;
    temp-> next=NULL;
    temp->next=head;
    head=temp;
}

void insertAtLoc(int n, int l)
{
    struct node *temp, *ptr;
    int i,c;
    if (head == NULL)
    {
        printf("Linked List is empty!!");
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = n;
        if (l == 1)
        {
            temp->next = NULL;
            head = temp;
        }
        else
        {
            i = 2;
            ptr=head;
            while (i < l && ptr->next != NULL)
            {
                i++;
                ptr = ptr->next;
            }
            temp->next = ptr->next;
            ptr->next = temp;
        }
    }
    printf("Inserted!!\n");
}

void insertAtLast(int n)
{
    struct node *temp, *ptr;
    
    temp = (struct node *)malloc(sizeof(struct node));       
    
    temp->data = n;                      
    
    temp->next = NULL;                   
    
    if (head == NULL)                    
    {
        head = temp;       
    }
    
    else    
                           
    {
        ptr = head;                 
        while (ptr->next != NULL)   
        {
            ptr = ptr->next;        
        }
        ptr->next = temp;             
    }
}

void deleteBeg()
{
    struct node *ptr, *f;
    if (head == NULL)
    {
        printf("LL is empty!!!");
    }
    else
    {
        f = ptr = head;
        head = ptr->next;
        free(f);
        printf("Node deleted from the front!!");
    }
}

void dltSpc(int l)
{
    struct node *ptr, *f;
    int i, flg = 0;
    if (head == NULL)
    {
        printf("Nothing to delete!!!");
    }
    else
    {
        if (l == 1)
        {
            f = head;
            head = f->next;
            free(f);
        }
        else if (l <= countNode())
        {
            i = 2;
            ptr = head;
            while (i < l && ptr->next != NULL)
            {
                i++;
                ptr = ptr->next;
            }

            f = ptr->next;
            ptr->next = ptr->next->next;
            free(f);
            printf("One Node deleted!!!!\n");
        }
        else
        {
            printf("Desired location not found!! Try again!!\n");
        }
    }
    printf("\n");
    display();
}

void deleteLast()
{
    struct node *ptr, *f;
    if (head == NULL)
    {
        printf("LL is empty!!!");
    }
    else
    {
        ptr = head;
        if (head->next == NULL)
        {
            f = head;
            head = NULL;
            free(f);
        }
        else
        {
            while (ptr->next->next != NULL)
            {
                ptr = ptr->next;
            }
            f = ptr->next;
            ptr->next = NULL;
            free(f);
        }
        printf("Node deleted from the last!!");
    }
}

int countNode()
{
    struct node *ptr;
    int x = 0;
    ptr = head;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        x++;
    }
    return x;
}

void sort()
{
    struct node *ptr,*q;
    int i,j,t,c;
    if(head==NULL)
    {
        printf("LL is empty!!!");
    }
    else
    {
        ptr=head;
        c=countNode();
        for(i=0;i<c;i++)
        {
            q=ptr->next;
            for(j=i+1;j<c;j++)
            {
                if(ptr->data>q->data)
                {
                        t=ptr->data;
                        ptr->data=q->data;
                        q->data=t;
                }
                q=q->next;
            }
            ptr=ptr->next;
        }
    }
    printf("\n");
    display();
    
}

void search(int a)
{
    struct node *ptr;
    int f = 0,i=1;
    if(head==NULL)
    {
        printf("Linked List is empty\nFirst insert some value\n");
    }
    else
    {
        ptr = head;
        while (ptr!= NULL)
        {
            if (ptr->data == a)
            {
                f = 1;
                break;
            }
            i++;
            ptr = ptr->next;

        }
        if (f == 1)
        {
            printf("value found at: %d",i);
        }
        else
        {
            printf("Not found");
        }
    }
}

void display()
{
    struct node *ptr;
    ptr=head;
    if(head==NULL)
    {
        printf("Nothing to display");
    }
    else
    {
        printf("Showing the elements of LL:-\n\t");
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->next;
        }   
    }
}
