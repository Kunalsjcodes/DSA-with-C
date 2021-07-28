#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void insert(int n);
void disp();
void search(int);
void main()
{
    int c, val;
    while (1)
    {
        printf("\nEnter your choice:\n1.Insert\n2.Display\n3.Search a value\n0.Exit\n\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &val);
            insert(val);
            break;
        case 2:
            disp();
            break;
        case 3:
            printf("Enter a value to search: ");
            scanf("%d", &val);
            search(val);
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("Enter valid choice!!!");
            break;
        }
    }
}
void insert(int n)
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
void disp()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("Nothing to display!!!");
    }
    else
    {
        ptr = head;
        while (ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
    }
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
