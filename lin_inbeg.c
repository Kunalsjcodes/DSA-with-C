/*
insert at the begning of the LL
*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
void insertAtLast(int n);
void display();
void insertBeg(int a);
void main()
{
    int ch, val;
    while (1)
    {
        printf("\nEnter your choice\n1.Insert\n2.Insert at the starting of LL\n3.Display\n0.Exit\n\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value you want to Insert:  ");
            scanf("%d", &val);
            insertAtLast(val);
            break;
        case 2:
            printf("Enter the value you want to Insert:  ");
            scanf("%d", &val);
            insertBeg(val);
            break;
   
        case 3:
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

void insertAtLast(int n)
{
    struct node *temp, *ptr;
    
    temp = (struct node *)malloc(sizeof(struct node));          //****** important !!!! allocate memory for new node in run time!!
    
    temp->data = n;                         // asign data into data part of new node
    
    temp->next = NULL;                      // asign NULL to the next(address part) of new node
    
    if (head == NULL)                       // check if linked list is existed or not
    {
        head = temp;                        // when LL is not existed
    }
    
    else                                    // when LL is already started
    {
        ptr = head;                         //copy the address of first node of LL from head to ptr
        while (ptr->next != NULL)           // check if the current value is NULL or not NULL
        {
            ptr = ptr->next;                //If not NULL then asign *next(address part of node) address value to ptr [till loop condtion remains true ]
        }
        ptr->next = temp;                   // when loop terminates then this statement will add the new node in the last in our LL.
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
void display()
{
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
}