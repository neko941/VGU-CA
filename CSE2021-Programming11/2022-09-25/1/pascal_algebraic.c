/// @file pascal_algebraic.c

#include <stdio.h>

/**
 * Calculates the factorial
 * Formula: n! = n * (n-1) * (n-2) * ... * 1
 * @param[in] n
 * @param[out] fac
 */
int factorial(int n)
{
    int fac = 1;

    for(; n > 1; n--)
        fac *= n;

    return fac;
}

/**
 * Calculates combination
 * Formula: nCr = n! / ((n-r)! * r!)
 * @param[in] n
 * @param[in] r
 * @param[out] _ combination 
 */
int nCr(int n, int r)
{
    return factorial(n) / (factorial(n-r) * factorial(r));
}

/**
 * Print the Pascal's Triangle with the given level
 * @param[in] n Pascal's Triangle up to n levels
 */
int pascal_algebraic(int n)
{
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n-i; j++)
            printf("  ");

        for(int j = 0; j <= i; j++)
            printf(" %3d", nCr(i, j));

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
    pascal_algebraic(level);
}