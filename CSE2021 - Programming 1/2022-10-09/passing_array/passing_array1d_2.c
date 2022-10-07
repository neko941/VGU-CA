#include <stdio.h>

#define MAX 5

void printArray(int arr[MAX])
{
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", *(arr + i));
    }
}

int main()
{
    int arr[] = {1, 10, 3, 9, 5};
    printArray(arr);
}