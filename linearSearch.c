#include <stdio.h>
void main()
{
    int a[5], i, j, t = 0;
    printf("Enter the elements:- \n");
    for (i = 0; i <= 4; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the value you want to search:- ");
    scanf("%d", &j);
    for (i = 0; i <= 4; i++)
    {
        if (j == a[i])
        {
            t = 1;
            break;
        }
    }
    if (t == 1)
    {
        printf("value found at %d ", i + 1);
    }
    else
    {
        printf("Value not found");
    }
}