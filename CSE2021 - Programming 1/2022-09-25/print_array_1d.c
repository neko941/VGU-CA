/// @file print_array_1d.c

#include <stdio.h>

/**
 * Print the given array
 * @param[in] arr[] the given array
 * @param[in] size the size of the array
 */
void print_array_1d_0(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    puts("");
}

/**
 * Print the given array
 * @param[in] *arr the given array
 * @param[in] size the size of the array
 */
void print_array_1d_1(int * arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    puts("");
}

/**
 * Main entry point of the program.
*/
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int size = sizeof(a)/sizeof(a[0]);

    print_array_1d_0(a, size);
    print_array_1d_1(a, size);
}
