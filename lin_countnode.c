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
int countNode();


void main()
{
    int ch, val;
    while (1)
    {
        printf("\nEnter your choice\n1.Insert\n2.Display\n3.count the nodes\n0.Exit\n\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value you want to Insert:  ");
            scanf("%d", &val);
            insertAtLast(val);
            break;

        case 2:
            display();
            break;
        
        case 3:
            printf("\nTotal nodes in LL: %d", countNode());
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
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
}