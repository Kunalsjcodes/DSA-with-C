#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void enQueue(int);
void deQueue();
void display();
int front = -1, rear = -1, queue[5];

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
    if ((front == 0 && rear == 4) || (front == rear + 1))
    {
        printf("Queue is full!!!");
    }
    else
    {
        if (rear == 4 && front != 0)
        {
            rear = -1;
        }
        // queue[++rear] = a; //following 2 statements are same as this statement
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear]=a;
        printf("Inserted!!!!");
        
    }
}
void deQueue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty!!!");
    }
    else
    {
        queue[front] = 0;
        front++;
        if(front - 1 == rear)
        {
            front = rear = -1;
        }
        printf("Deleted!!!");
    }
}
void display()
{
    if (front == -1)
    {
        printf("Queue is Empty!!!");
    }
    else
    {
        int x = front;
        if (front <= rear)
        {
            while (x <= rear)
            {
                printf("%d\t", queue[x++]);
                // printf("%d\t",queue[x]);
                // x++;
            }
        }
        else
        {
            while (x <= 4)
            {
                printf("%d\t", queue[x++]);
            }
            x = 0;
            while (x <= rear)
            {
                printf("%d\t", queue[x++]);
            }
        }
    }
}