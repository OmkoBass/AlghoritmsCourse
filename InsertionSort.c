#include <stdio.h>

void print(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n)
{
    int i,j;
    int key;
    for(i = 1; i < n; i++)
    {
        j = i - 1;
        key = arr[i];

        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int arr[6] = {4, 5, 6, 2, 9, 1};
    insertionSort(arr,6);
    print(arr,6);
    
    return 0;
}