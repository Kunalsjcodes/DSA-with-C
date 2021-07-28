#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void enQueue(int);
void deQueue();
void display();
int front = -1,rear = -1,queue[5];

void main()
{
    int ch, val;
    while (1)
    {
        printf("\nEnter your choice\n1.EnQUeue\n2.DeQueue\n3.Display\n4.Exit\n\n");
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
    if (rear == 4)
    {

        printf("Queue is full !\n\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        queue[++rear]=a;
        // rear++;
        // queue[rear] = a;
        printf("The value is enQueued !!\n\n");
    }
}

void deQueue()
{
    if (front == -1)
    {
        printf("Nothing to delete !\n\n");
    }
    else
    {
        queue[front] = 0;
        front++;
        if (front == rear)
        {
            front = rear = -1;
        }
        printf("The value is DeQueued from front !\n\n");
    }
}

void display()
{
    int i;
    if (front == -1)
    {
        printf("Nothing to display !\n\n");
    }
    else
    {
        for (i = front; i <= rear; i++)
        {
            printf("%d\t", queue[i]);
        }
    }
}








