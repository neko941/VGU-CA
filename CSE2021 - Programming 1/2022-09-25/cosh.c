/// @file cosh.c

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

    for (int i = 1; i <= n; i++)
        fac *= i;

    return fac;
}

/**
 * Calculates the hyperbolic cosine using for loop
 * Formula (Latex): cosh(x) = \sum_{n=0}^{\infty}\frac{x^{2n}}{(2n)!} = 1 + \frac{x^{2}}{2!} + \frac{x^{4}}{4!} + \frac{x^{6}}{6!} + \frac{x^{8}}{8!} + ...
 * @param[in] x the number want to calculate
 * @param[in] n the number of loops
 * @param[out] sum hyperbolic cosine of x with n loops
 */
double hyperbolic_cosine(double x, int n)
{
    double sum;

    for (int i = 0; i < n; i++)
        sum += pow(x, 2*i) / factorial(2*i);

    return sum;
}

/**
 * Main entry point of the program.
*/
int main()
{
    printf("%f\n", hyperbolic_cosine(3.14, 10));
}
