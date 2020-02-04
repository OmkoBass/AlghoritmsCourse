#include <stdio.h>

void swap(int *px, int *py)
{
    int temp = *px;
    *px = *py;
    *py = temp;
}

void print(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void BubbleSort(int arr[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main()
{
    int arr[5] = {3, 1, 2, 5, 4};
    BubbleSort(arr, 5);
    print(arr, 5);
    
    return 0;
}