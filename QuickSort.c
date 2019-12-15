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

int partition(int arr[], int l, int h)
{
    int i,j;
    i = l+1;
    j = h-1;
    int pivot = arr[0];
    while(i <= j)
    {
        while(arr[i] < pivot) { i++; }
        while(arr[j] > pivot) { j++; }
        swap(&arr[i], &arr[j]);
    }
    swap(&arr[0], &arr[j]);
    return j;
}

int QuickSort(int arr[], int l, int h)
{
    int j;
    if(l < h)
    {
        j = partition(arr, l, h);     
        QuickSort(arr, l, j-1); 
        QuickSort(arr, j+1, h); 
    }
}

int main()
{
    int arr[9] = {3, 15, 23, 1, 3, 6, 120, 20, 71};
    print(arr, 9);
    QuickSort(arr, 0, 9);
    print(arr, 9);

    return 0;
}