#include <stdio.h>
#include <stdlib.h>

int i_array_print_1d (int *arr, int _size)
{
    for(int i=0; i<_size; i++)
        if (arr[i] != 0)
            printf("%3d ", arr[i]);
    puts("");
}

int* i_array_new_1d(int n)
{
    return (int*) calloc(n+1, sizeof(int));
}


int pascal_dynamic(int n)
{
    int* result = i_array_new_1d(n+1);
    result[0] = 1;
    for (int i=0; i<=n; i++)
    {
        for (int j=i; j>0; j--)
            result[j] += result[j - 1];
        for(int j = 0; j <= n-i; j++)
            printf("  ");
        i_array_print_1d(result, n+1);
    }
}

int main()
{
    pascal_dynamic(10);
}
