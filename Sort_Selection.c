#include<stdio.h>
void main()
{
    int a[5] ,i,j,t;
    printf("\n Enter 5 elements: \n");
    for(i=0;i<=4;i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Before Sorting :\n\t");
    for(i=0;i<=4;i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\nAfter Sorting :\n\t");
    for(i=0;i<=4;i++)
    {
        for(j=i+1;j<=4;j++)
        {
            if(a[i]>a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
        printf("%d\t", a[i]);
    }
}