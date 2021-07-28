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
void display();

void main()
{
    int ch, val, loc;
    while (1)
    {
        printf("\n\nEnter your choice:-\n\t1. Insert at front\t\t2. Insert at specific position\n\t3. Insert at last\t\t4. Display\n\t0.  Exit\n\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter Data:  ");
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
            printf("Enter Data:  ");
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
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = a;
    if (head == NULL)
    {
        head = temp;
        temp->next = head;
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
        {

            ptr = ptr->next;
        }
        temp->next = head;
        head = temp;
        ptr->next = head;
    }
    display();
}

void insertAtLoc(int n, int l)
{
    struct node *temp, *ptr;
    int i;
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
            insertBeg(n);
        }
        else
        {
            i = 2;
            ptr = head;
            while (i < l && ptr->next != head)
            {
                i++;
                ptr = ptr->next;
            }
            temp->next = ptr->next;
            ptr->next = temp;
        }
        printf("Inserted!!\n");
        display();
    }
}

void insertAtLast(int n)
{
    struct node *temp, *ptr;

    temp = (struct node *)malloc(sizeof(struct node));

    temp->data = n;

    if (head == NULL)
    {
        insertBeg(n);
    }

    else

    {
        ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->next = head;
        display();
    }
}

void display()
{
    struct node *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("Nothing to display");
    }
    else
    {
        printf("Showing the elements of LL:-\n\t");
        do
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        } while (ptr != head);
    }
}
