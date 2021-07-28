/*

       values< pivot < value


p
7 6 5 3 1
7 3 1 4 2
---------
0 1 2 3 4
f       l
      i j
f=0
l=4
i=0,1,2,3,4
j=4
tempp
pivot =0   2 3 1 4 7       1 2 3 4 7
                           0 1 2 3 4              */


#include <stdio.h>
void display(int l[5])
{
    int i;
  
}
void quickSort(int list[5], int first, int last)
{
    int pivot, i, j, temp;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while (i < j)
        {
            while (list[i] <= list[pivot] && i < last)
            {
                i++;
            }
            while (list[j] > list[pivot])
            {
                j--;

            }
            if (i < j)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }

        temp = list[pivot];
        list[pivot] = list[j];
        list[j] = temp;
        quickSort(list, first, j - 1);
        quickSort(list, j + 1, last);

    }
    // display(list);
}

void main()
{
    int a[5],i;
    printf("Enter 5 elements: ");
    for (i = 0; i <= 4; i++)
    {
        scanf("%d", &a[i]);
    }


    printf("\nInputed Array:\n");
    for (i = 0; i <= 4; i++)
    {
        printf("\t%d", a[i]);
    }


    quickSort(a, 0, 4);
      printf("\nSorted Array:\n");
    for (i = 0; i <= 4; i++)
    {
        printf("\t%d", a[i]);
    }
}