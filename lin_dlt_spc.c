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
void dltSpc(int);
int countNode();
void search(int);
void main()
{
    int c, val, loc, xx;
    while (1)
    {
        printf("\nEnter your choice:\n1.Insert\n2.Display\n3.Delete from specific location\n4.Count Nodes\n5.Search a value\n0.Exit\n\n");
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
            printf("Enter location to remove node from LL: ");
            scanf("%d", &loc);
            dltSpc(loc);
            break;
        case 4:
            printf("\nTotal nodes in LL: %d", countNode());
            break;
        case 5:
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
    disp();
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
void search(int a)
{
    struct node *ptr;
    int f = 0;
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        if (ptr->data == a)
        {
            f = 1;
            break;
        }
    }
    if (f == 1)
    {
        printf("value found ");
    }
    else
    {
        
            printf("Not found");
        
    }
}