/*
5 4 8 7 2 3 1

1 2 3 4 5 7 8


*/
#include<stdio.h>
void main()
{
    int a[6]={2,3,4,6,7,8};
    int l,m,h,s,f=0;
    printf("Enter value you want to search: ");
    scanf("%d",&s);
    l=0;
    h=5;
    m=0;
    while(l<=h)
    {
        m=(l+h)/2;
        if(s==a[m])
        {
            f=1;
            break;
        }
        else
        {
            if(s>a[m])
            {
                l=m+1;
            }
            else
            {
                h=m-1;
            }
        }
    }
    if(f==1)
    {
        printf("Value found at %d",m+1);
    }
    else
    {
        printf("Not found");
    }
    
}