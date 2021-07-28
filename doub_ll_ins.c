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
void display();
int countNode();
void main()
{
    int ch, val, loc;
    while (1)
    {
        printf("\nEnter your choice:\n1. Insert\t\t2.Display\t\t3. Insert at Beginning\t\t4. Insert at Specific Location\n0. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter a value : ");
            scanf("%d", &val);
            insert(val);
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Enter a valuee: ");
            scanf("%d", &val);
            insertAtBeg(val);

            break;
        case 4:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            printf("Enter location: ");
            scanf("%d", &loc);
            insertAtLoc(val, loc);
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
}
void insertAtBeg(int a)
{
    struct node *ptr, *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = a;
    temp->pre = NULL;
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
        printf("Nothing to display!!");
    }
    else
    {

        while (ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
    }
}