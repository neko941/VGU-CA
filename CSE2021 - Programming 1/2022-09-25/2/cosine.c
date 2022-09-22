/// @file cosine.c

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
    double fac = 1;

    for(; n > 1; n--)
        fac *= n;

    return fac;
}

/**
 * Calculates the cosine of a number
 * @param[in] x number you wanna calculate cosine
 * @param[in] n number of loops
 * @param[out] result cosine of x
 */
double cosine(double x, int n)
{
    double result = 0;
    for (int i = 0; i <= n; i++)
        result += pow(-1, i) * pow(x, 2 * i) / factorial(2 * i);
    return result;
}

/**
 * Main entry point of the program.
*/
int main()
{
    printf("%f\n", cosine(3.14, 10));
}
