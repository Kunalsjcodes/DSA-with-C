#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *pre, *next;
};
struct node *head = NULL;
void insert(int);
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
        printf("\nEnter your choice:\n1. Insert\t\t2.Display\t\t3. Delete from End\n4. count nodes\t\t5. Delete from Beg\t6. Delete form Specific Location\n0. Exit\n");
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
            delete ();
            break;
        case 4:
            printf("\nTotal nodes in LL: %d", countNode());
            break;
        case 5:
            deleteBeg();
            break;
        case 6:
            printf("Enter the location of node you want to delete");
            scanf("%d", &loc);
            deleteloc(loc);
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
            printf("Node deleted");
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
            display();  
        }
        else
        {
            printf("Desired Location not found");
        }
    }
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