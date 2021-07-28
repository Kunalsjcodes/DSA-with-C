/*  First In First Out
    Insert at last + Delete from front
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *rear;
};

struct node *front = NULL;

void enQueue(int);
void deQueue();
void display();

void main()
{
    int ch, val;
    while (1)
    {
        printf("\nEnter your choice\n\t1. EnQUeue(Insert)\t\t2. DeQueue(Delete)\n\t3. Display\t\t\t4. Exit\n\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value you want to EnQueue:  ");
            scanf("%d", &val);
            enQueue(val);
            break;

        case 2:
            deQueue();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Enter a valid choice !!");
            break;
        }
    }
}

void enQueue(int a)
{
    struct node *temp, *ptr;
    
    temp = (struct node *)malloc(sizeof(struct node));       
    
    temp->data = a;                      
    
    temp->rear = NULL;                   
    
    if (front == NULL)                    
    {
        front = temp;     
    }
    
    else    
                           
    {
        ptr = front;                 
        while (ptr->rear != NULL)   
        {
            ptr = ptr->rear;        
        }
        ptr->rear = temp;             
    }
    printf("Inserted !!\n");
    display();
}

void deQueue()
{
    struct node *ptr, *f;
    if (front == NULL)
    {
        printf("Queue is empty !!\n");
    }
    else
    {
        f = ptr = front;
        front = ptr->rear;
        free(f);
        printf("Deleted !!\n");
    }
    display();
}

void display()
{
    struct node *ptr;
    ptr=front;
    if(front==NULL)
    {
        printf("Nothing to display");
    }
    else
    {
        printf("Showing the elements in Queue:-\n\t");
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->rear;
        }   
        printf("\n");
    }
}











