#include <stdio.h>

void printArray(int *arr, int _size)
{
    for (int i = 0; i < _size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[] = {1, 10, 3, 9, 5};
    printArray(arr, sizeof(arr)/sizeof(arr[0]));
}