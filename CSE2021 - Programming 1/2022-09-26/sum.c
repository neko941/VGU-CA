/// @file sum.c

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Print the given array
 * @param[in] arr the given array
 * @param[in] size the size of the array
 */
void i_array_print_1d(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    puts("");
}

/**
 * Find maximum value in the given array
 * @param[in] arr the given array
 * @param[in] length the size of the array
 * @param[out] sum sum of the array
 */
int i_array_sum_1d(int arr[], int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += arr[i];
    }
    return sum;
}

/**
 * Create a new dynamic array with the given size
 * @param[in] n the size of the array
 * @param[out] _ array with given size
 */
int *i_array_new_1d(int n)
{
    return (int *)calloc(n, sizeof(int));
}

/**
 * Fill given array with random value in range [min, max]
 * @param[in] arr the given array
 * @param[in] n the size of the array
 * @param[in] min minimum value to be generated
 * @param[in] max maximum value to be generated
 */
int *i_array_random_1d(int *arr, int n, int min, int max)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

/**
 * Main entry point of the program.
 */
int main()
{
    // need this to change random value each time
    srand(time(NULL));

    // declare and initialize data
    int length = 12;
    int min_vlaue = -15;
    int max_value = 15;

    // create an array filled with 0
    int *arr = i_array_new_1d(length);

    // fill given array with random value within range [min_vlaue, max_value]
    i_array_random_1d(arr, length, min_vlaue, max_value);

    // display
    printf("The Array:\n\t");
    i_array_print_1d(arr, length);
    printf("Sum of the array: %d", i_array_sum_1d(arr, length));
}