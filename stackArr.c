// #include <stdio.h>
// #include <stdlib.h>
// #include <conio.h>
// int st[5];
// int top = -1;

// void push(int);
// void pop();
// void display();

// void main()
// {
//     int ch, val;
//     while (1)
//     {
//         printf("\nEnter your Choice:\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
//         scanf("%d", &ch);

//         switch (ch)
//         {
//         case 1:
//             printf("ENter a value to push: ");
//             scanf("%d", &val);
//             push(val);
//             break;
//         case 2:
//             pop();
//             break;
//         case 3:
//             display();
//             break;
//         case 4:
//             exit(0);
//             break;

//         default:
//             printf("Input a valid choice !!!!!");
//             break;
//         }
//     }
// }
// void push(int a)
// {
//     if (top == 4)
//     {
//         printf("Stack is Full !!!!!!!!");
//     }
//     else
//     {
//         top++;
//         st[top] = a;
//         printf("Inserted !!!!!!");
//     }
// }
// void pop()
// {
//     if (top == -1)
//     {
//         printf("Stack is empty !!!!!!");
//     }
//     else
//     {
//         st[top] = 0;
//         top--;
//         printf("Deleted !");
//     }
// }
// void display()
// {
//     int i;
//     if (top == -1)
//     {
//         printf("Nothing to display!!!: %d",top);
//         // exit(0);
//     }
//     else
//     {

//         for (i = top; i >= 0; i--)
//         {
//             printf("%d\t", st[i]);
//         }
//     }
// }

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int st[5];
int top= -1;

void push(int);
void pop();
void display();

void main()
{
    int ch,val;
    while(1)
    {
        printf("\nEnter your choice\n1.Push\n2.pop\n3.Display\n4.Exit\n\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the value you want to push: ");
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
            printf("Enter a valid choice !!");
            break;
        }
    }
}

void push(int a)
{
    if(top==4)
    {
        printf("Stack is Overflow !!\n\n");
    }
    else
    {
        top++;
        st[top]=a;
        printf("Inserted !!\n\n");
    }
}

void pop()
{
    if(top==-1)
    {
        printf("Stack is Underflow !!\n\n");
    }
    else
    {
        st[top]=0;
        top--;
        printf("Deleted !!\n\n");
    }
}

void display()
{
    int i;
    if(top==-1)
    {
        printf("Nothing to display\n\n");
    }
    else
    {
        for(i=top;i>=0;i--)
        {
        printf("%d \t", st[i]);
        }
    }
}