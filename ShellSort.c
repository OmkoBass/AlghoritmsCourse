#include <stdio.h>

void swap(int *px, int *py)
{
    int temp = *px;
    *px = *py;
    *py = temp;
}

void print(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void shellSort(int arr[], int n)
{
    int i;
    for(int gap = n/2; gap > 0; gap = gap/2)
    {
        for(i = 0; i < n; i++)
        {
            if(arr[i] > arr[i+gap]) { swap(&arr[i], &arr[i+gap]); }
        }
    }
}

int main()
{
    int arr[5] = {3, 15, 23, 1, 4};
    print(arr, 5);
    shellSort(arr, 5);
    print(arr, 5);

    return 0;
}