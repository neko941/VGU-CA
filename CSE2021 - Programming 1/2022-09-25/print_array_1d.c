#include <stdio.h>

void print_array_1d_0(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    puts("");
}

void print_array_1d_1(int * arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    puts("");
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int size = sizeof(a)/sizeof(a[0]);

    print_array_1d_0(a, size);
    print_array_1d_1(a, size);
}
