/*
COMPLETE DOUBLE LINKED LIST 
*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *pre, *next;
};
struct node *head = NULL;
void insert(int);
void insertAtBeg(int);
void insertAtLoc(int, int);
void delete ();
void deleteBeg();
void deleteloc(int);
void display();
int countNode();
void main()
{
    int ch, val, loc;
    while (1)
    {
        printf("\nEnter your choice:\n\t1. Insert At Beginning\t\t2. Insert At Specific Location\t\t3. Insert At Last\n\t4. Delete From Front\t\t5. Delete From Specific Location\t6. Delete From Last\n\t7. Count Nodes\t\t\t8. Display\t\t\t\t0. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter a value: ");
            scanf("%d", &val);
            insertAtBeg(val);
            break;
        case 2:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            printf("Enter location: ");
            scanf("%d", &loc);
            insertAtLoc(val, loc);
            break;
        case 3:
            printf("Enter a value : ");
            scanf("%d", &val);
            insert(val);
            break;
        case 4:
            deleteBeg();
            break;
        case 5:
            printf("Enter the location of node you want to delete:  ");
            scanf("%d", &loc);
            deleteloc(loc);
            break;
        case 6:
            delete ();
            break;
        case 7:
            printf("\nTotal nodes in LL: %d", countNode());
            break;
        case 8:
            display();
            break;
        case 0:
            exit(0);
            break;

        default:
            printf("Enter a valid choice:::!!!");
            break;
        }
    }
}
void insertAtBeg(int a)
{
    struct node *ptr, *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = a;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        temp->pre = NULL;
    }
    else
    {
        temp->next = head;
        head->pre = temp;
        head = temp;
    }
    display();
}

void insertAtLoc(int n, int l)
{
    struct node *temp, *ptr;
    int i;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    if (head == NULL)
    {
        temp->pre = temp->next = NULL;
        head = temp;
        printf("Value inserted!!!\n");
        display();
    }
    else if (l <= countNode())
    {
        if (l == 1)
        {
            insertAtBeg(n);
            printf("Value inserted!!!\n");
            display();
        }
        else
        {
            i = 2;
            ptr = head;
            while (i < l && ptr->next != NULL)
            {
                i++;
                ptr = ptr->next;
            }
            temp->pre = ptr;
            temp->next = ptr->next;
            ptr->next = temp;
        }
        printf("Value inserted!!!\n");
        display();
    }
    else if (l == (countNode()) + 1)
    {
        insert(n);
        printf("Value inserted!!!\n");
        display();
    }
    else
    {
        printf("Location not found!!!");
    }
}

void insert(int a)
{
    struct node *ptr, *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = a;
    temp->next = NULL;
    if (head == NULL)
    {
        temp->pre = NULL;
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
        temp->pre = ptr;
    }
    display();
}

void deleteBeg()
{
    struct node *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("nothing to delete !!");
    }
    else
    {
        if (head->next == head->pre) //head->next==NULL;
        {
            ptr = head;
            head = NULL;
            free(ptr);
            display();
        }
        else
        {
            ptr->next->pre = NULL;
            head = ptr->next;
            free(ptr);
            printf("Node deleted\n");
            display();
        }
        
    }
}

void deleteloc(int l)
{
    struct node *ptr, *f;
    int i;
    if (head == NULL)
    {
        printf("Nothing to delete");
    }
    else
    {
        if (l == 1)
        {
            deleteBeg();
            display();
        }
        else if (l < countNode())
        {
            i = 2;
            ptr = head;
            while (i < l && ptr->next != NULL)
            {
                i++;
                ptr = ptr->next;
            }
            f = ptr->next;
            ptr->next=ptr->next->next;
            ptr->next->pre=f->pre;
            free(f);
            display();
        }
        else if(l==countNode())
        {
            delete();   
        }
        else
        {
            printf("Desired Location not found");
        }
    }
}

void delete ()
{
    struct node *ptr, *f;
    ptr = head;

    if (head == NULL)
    {
        printf("Nothing to delete!!");
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        f = ptr;
        ptr->pre->next = NULL;
        free(f);
        printf("Node Deleted!!!\n");
        display();
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