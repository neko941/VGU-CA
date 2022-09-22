/// @file sine_recursive.c

#include <stdio.h>
#include <math.h>

/**
 * Calculates the factorial
 * Formula: n! = n * (n-1) * (n-2) * ... * 1
 * @param[in] n
 * @param[out] fac
 */
double factorial(int n)
{
    if (n >= 1)
        return n*factorial(n-1);
    else
        return 1;
}

/**
 * Calculates the sine of a number but it is recursive
 * @param[in] x number you wanna calculate sine
 * @param[in] n number of loops
 * @param[out] result sine of x
 */
double sine_recursive(double x, int n)
{
   if (n >= 0)
        return pow(-1, n) * pow(x, 2*n+1) / (factorial(2*n+1)) + sine_recursive(x, n-1);
    else
        return 0;
}

/**
 * Main entry point of the program.
*/
int main()
{
    printf("%f\n", sine_recursive(3.14, 10));
}
