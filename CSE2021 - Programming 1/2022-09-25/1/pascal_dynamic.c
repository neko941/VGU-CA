/// @file pascal_dynamic.c

#include <stdio.h>
#include <stdlib.h>

/**
 * Print tje given array
 * @param[in] arr the array 
 * @param[out] _size size of the array
 */
void i_array_print_1d (int *arr, int _size)
{
    for(int i=0; i<_size; i++)
        if (arr[i] != 0)
            printf("%3d ", arr[i]);
    puts("");
}

/**
 * Create a new dynamic array with the given size
 * @param[in] n the size of the array
 * @param[out] _ array with given size
 */
int* i_array_new_1d(int n)
{
    return (int*) calloc(n+1, sizeof(int));
}

/**
 * Print the Pascal's Triangle with the given level
 * @param[in] n Pascal's Triangle up to n levels
 */
int pascal_dynamic(int n)
{
    int* result = i_array_new_1d(n+1); ///< array to save result
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

/**
 * Main entry point of the program.
*/
int main()
{
    int level;

    printf("Enter the level of Pascal's Triangle:\n>> ");
    scanf("%d", &level);
    pascal_dynamic(level);
}