#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
void insertAtLast(int n);
void deleteBeg();
void dltSpc(int l);
void deleteLast();
int countNode();
void display();

void main()
{
    int ch, val, loc;
    while (1)
    {
        printf("\n\nEnter your choice:-\n\t1. Insert at last\t\t\t\t2. Delete from front\n\t3. Delete from specific position\t\t4. Delete from last\n\t5. Display\t\t\t\t\t0. Exit\n\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter Data:  ");
            scanf("%d", &val);
            insertAtLast(val);
            break;
        case 2:
            deleteBeg();
            break;
        case 3:
            printf("Enter location to remove node from LL: ");
            scanf("%d", &loc);
            dltSpc(loc);
            break;
        case 4:
            deleteLast();
            break;
        case 5:
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

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
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
        ptr->next = temp;
        temp->next = head;
    }
    display();
}

void deleteBeg()
{
    struct node *ptr, *f;
    if (head == NULL)
    {
        printf("Nothing to delete!!!");
    }
    else
    {
        f = ptr = head;
        head = ptr->next;
        free(f);
        printf("Node deleted from the front!!\n");
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
