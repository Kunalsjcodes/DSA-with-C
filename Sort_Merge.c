/*
this sorting use the divide and conqure tech.
                                                8 6 5 1 3 

                                        8,6     5,1     3           //divide the main array into possible sub arrays

                                        6,8     1,5     3          //swap(sort) individualsub array

                                        1,5,6,8         3                //merge sub array into one array

                                        1   3   5   6   8           //finally merge all array into complete array
                                    
*/
#include <stdio.h>

int array[20];

void devidepass(int low, int high)
{
    int mid;
    if (low != high)
    {
        mid = (low + high) / 2;
        devidepass(low, mid);
        devidepass(mid + 1, high);
        merge(low, mid, high);
    }
} 

void merge(int low, int mid, int high)
{
    int temp[20];
    int i = low;
    int j = mid + 1;
    int k = low;

    while ((i <= mid) && (j <= high))
    {
        if (array[i] <= array[j])
        {
            // temp[k++] = array[i++];
            temp[k] = array[i];
            k++;
            i++;
        }
        else
        {
            // temp[k++] = array[j++];
            temp[k] = array[j];
            k++;
            j++;
        }
    } /*End of while*/
    while (i <= mid)
    {
        // temp[k++] = array[i++];
        temp[k] = array[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        // temp[k++] = array[j++];
        temp[k] = array[j];
        k++;
        j++;
    }

    for (i = low; i <= high; i++)
        array[i] = temp[i];
} /*End of merge()*/
void main()
{
    int i, n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Unsorted list is :\n");
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);

    devidepass(0, n - 1);

    printf("\nSorted list is :\n");
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
} /*End of main()*/