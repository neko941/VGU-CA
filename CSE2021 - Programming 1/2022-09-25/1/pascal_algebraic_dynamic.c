/// @file pascal_algebraic_dynamic.c

#include <stdio.h>
#include <stdlib.h>

/**
 * Create a new dynamic array with the given size
 * @param[in] n the size of the array
 * @param[out] _ array with given size
 */
int* i_array_new_1d(int n)
{
    return (int*) calloc(n, sizeof(int));
}

/**
 * Create a new dynamic array filled with factorial values up until the given number
 * @param[in] n the size of the array aka the maximum number you want to factorial
 * @param[out] result the array of factorial values
 */
int* factorial_dynamic(int n)
{
    int* result = i_array_new_1d(n);
    result[0] = 1;
    for (int i=1; i<=n; i++)
        result[i] = result[i-1] * i;
    return result;
}

/**
 * Print the Pascal's Triangle with the given level
 * @param[in] n Pascal's Triangle up to n levels
 */
void pascal_algebraic_dynamic(int n)
{
    int* factorial = factorial_dynamic(n);
    for (int i=0; i<=n; ++i)
    {
        for(int j = 0; j <= n-i; j++)
            printf("  ");
        for (int j=0; j<=i; j++)
            printf("%3d ", factorial[i] / (factorial[i-j] * factorial[j]));
        puts("");
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
    pascal_algebraic_dynamic(level);
}
