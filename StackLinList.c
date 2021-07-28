/*  Last In First Out
    Insert at last + Delete from Last
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int);
void pop();
void display();

void main()
{
    int ch, val;
    while (1)
    {
        printf("\nEnter your Choice:\n\t1. Push(Insert)\t\t2. Pop(Delete)\n\t3. Display\t\t4.Exit\n\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("ENter a value to push: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;

        default:
            printf("Input a valid choice !!!!!");
            break;
        }
    }
}
void push(int a)
{
    struct node *temp, *ptr;
    
    temp = (struct node *)malloc(sizeof(struct node));       
    
    temp->data = a;                      
    
    temp->next = NULL;                   
    
    if (top == NULL)                    
    {
        top = temp;       
    }
    
    else    
                           
    {
        ptr = top;                 
        while (ptr->next != NULL)   
        {
            ptr = ptr->next;        
        }
        ptr->next = temp;             
    }
    printf("Inserted !!\n");
    display();
}
void pop()
{
    struct node *ptr, *f;
    if (top == NULL)
    {
        printf("Stack is Empty!!\n");
    }
    else
    {
        ptr = top;
        if (top->next == NULL)
        {
            f = top;
            top = NULL;
            free(f);
        }
        else
        {
            while (ptr->next->next != NULL)
            {
                ptr = ptr->next;
            }
            f = ptr->next;
            ptr->next = NULL;
            free(f);
        }
        printf("Deleted !!\n");
    }
    display();
}
void display()
{
    struct node *ptr;
    ptr=top;
    if(top==NULL)
    {
        printf("Nothing to display");
    }
    else
    {
        printf("Showing the elements in Stack:-\n\t");
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->next;
        } 
        printf("\n");  
    }
}