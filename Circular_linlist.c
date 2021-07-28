/*
COMPLETE CIRCULAR LINKED LIST
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
void display();

void main()
{
    int ch, val, loc;
    while (1)
    {
        printf("\n\nEnter your choice:-\n\t1. Insert at front\t\t2. Insert at specific position\t\t3. Insert at last\n\t4. Delete from Beginning\t5. Delete from specific location\t6. Delete from Last\n\t7. Count nodes\t\t\t8. Display\t\t\t\t0.Exit\n\n");
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
    printf("Inserted !!\n");
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
            printf("Inserted!!\n");
            display();
        }
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
        printf("Inserted !!\n");
        display();
    }
}

void deleteBeg()
{
    struct node *ptr, *f;
    if (head == NULL)
    {
        printf("Nothing to delete");
    }
    else
    {
        if (head->next == head)
        {
            head = NULL;
            free(head);
        }
        else
        {
            f = ptr = head;
            while (ptr->next != head)
            {

                ptr = ptr->next;
            }
            ptr->next = f->next;
            head = f->next;
            free(f);
            printf("Node Deleted\n");
        }

        display();
    }
}

void dltSpc(int l)
{
    struct node *ptr, *f;
    int i;
    if (head == NULL)
    {
        printf("Nothing to delete!!!");
    }
    else
    {
        if (l == 1)
        {
            deleteBeg();
        }
        else if (l <= countNode())
        {
            i = 2;
            ptr = head;
            while (i < l && ptr->next != head)
            {
                i++;
                ptr = ptr->next;
            }

            f = ptr->next;
            ptr->next = ptr->next->next;
            free(f);
            printf("One Node deleted!!!!\n");
            display();
        }
        else
        {
            printf("Desired location not found!! Try again!!\n");
            display();
        }
    }
}

void deleteLast()
{
    struct node *ptr, *f;
    if (head == NULL)
    {
        printf("Nothing to delete!!!");
    }
    else
    {
        ptr = head;
        if (head->next == head)
        {
            f = head;
            head = NULL;
            free(f);
        }
        else
        {
            while (ptr->next->next != head)
            {
                ptr = ptr->next;
            }
            f = ptr->next;
            ptr->next = head;
            free(f);
        }
        printf("Node deleted from the last!!\n");
        display();
    }
}

int countNode()
{
    struct node *ptr;
    int x = 0;
    ptr = head;
    do
    {
        ptr = ptr->next;
        x++;
    } while (ptr != head);

    return x;
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
