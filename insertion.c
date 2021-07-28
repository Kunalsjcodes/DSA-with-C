#include<stdio.h>
void main()
{
    int a[5] ,i,j,t;
    printf("\n Enter 5 elements: \n");
    for(i=0;i<=4;i++)
    {
        scanf("%d", &a[i]);
            for(j=0;j<=i-1;j++)
            {
                if(a[i]<a[j])
                {
                    t=a[i];
                    a[i]=a[j];
                    a[j]=t;
                }
            }
    }
    printf("After Sorting :\n\t");
    for(i=0;i<=4;i++)
    {
        printf("%d\t", a[i]);
    }
}


/*

i=  0,1,2,3,4
j=  0,1||0,1 ||0, 1,2||0,1,2,3||0,1,2,3,4

1 2 6 7 8


2 8 1 6 7


*/