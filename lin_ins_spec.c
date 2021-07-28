/*
Insertion at specific position  
*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
void insertAtLoc(int n, int l);
void insertAtLast(int n);
void insertBeg(int a);
void display();

void main()
{
    int ch, val, loc;
    while (1)
    {
        printf("\nEnter your choice\n1.Insert at beggining\n2.Insert at specific position\n3.Insert at last\n4.Display\n0.Exit\n\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value you want to Insert:  ");
            scanf("%d", &val);
            insertBeg(val);
            break;
        case 2:
            printf("Enter the value you want to Insert:  ");
            scanf("%d", &val);
            printf("Enter location to insert: ");
            scanf("%d", &loc);
            insertAtLoc(val, loc);
            break;
        case 3:
            printf("Enter the value you want to Insert:  ");
            scanf("%d", &val);
            insertAtLast(val);
            break;
        case 4:
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

    temp = (struct node *)malloc(sizeof(struct node)); //****** important !!!! allocate memory for new node in run time!!

    temp->data = n; // asign data into data part of new node

    temp->next = NULL; // asign NULL to the next(address part) of new node

    if (head == NULL) // check if linked list is existed or not
    {
        head = temp; // when LL is not existed
    }

    else // when LL is already started
    {
        ptr = head;               //copy the address of first node of LL from head to ptr
        while (ptr->next != NULL) // check if the current value is NULL or not NULL
        {
            ptr = ptr->next; //If not NULL then asign *next(address part of node) address value to ptr [till loop condtion remains true ]
        }
        ptr->next = temp; // when loop terminates then this statement will add the new node in the last in our LL.
    }
}

void display()
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}
