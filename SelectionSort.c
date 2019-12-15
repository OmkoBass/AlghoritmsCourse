#include <stdio.h>

void print(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *px, int *py)
{
    int temp = *px;
    *px = *py;
    *py = temp;
}

int minIndex(int arr[], int n, int pocetak)
{
    int min = arr[0];
    int index;
    for(pocetak = 0; pocetak < n; pocetak++)
    {
        if(min > arr[pocetak])
        {
            min = arr[pocetak]; index = pocetak;
        }
    }
    return index;
}

void selectionSort(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        int x = minIndex(arr, n, i);
        swap(&arr[x], &arr[i]);
    }
}

int main()
{
    int arr[] = {3, 4, 2, 5, 6};
    selectionSort(arr, 6);
    print(arr, 6);

    return 0;
}