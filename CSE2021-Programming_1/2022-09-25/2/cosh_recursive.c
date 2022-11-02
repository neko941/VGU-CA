/// @file cosh_recursive.c

#include <stdio.h>
#include <math.h>

/**
 * Calculates the factorial but it's recursive
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
 * Calculates the hyperbolic cosine but it's recursive
 * Formula (Latex): cosh(x) = \sum_{n=0}^{\infty}\frac{x^{2n}}{(2n)!} = 1 + \frac{x^{2}}{2!} + \frac{x^{4}}{4!} + \frac{x^{6}}{6!} + \frac{x^{8}}{8!} + ...
 * @param[in] x the number want to calculate
 * @param[in] n the number of loops
 * @param[out] sum hyperbolic cosine of x with n loops
 */
double hyperbolic_cosine_recursive(double x, int n)
{
   if (n >= 0)
        return pow(x, 2*n) / factorial(2*n) + hyperbolic_cosine_recursive(x, n-1);
    else
        return 0;
}

/**
 * Main entry point of the program.
*/
int main()
{
    double num;
    int loop;

    printf("Enter the number for hyperbolic cosine: \n>> ");
    scanf("%lf", &num);
    printf("Enter the number of loop: \n>> ");
    scanf("%d", &loop);
    printf("cosh(x=%f, loop=%d) = %f\n", num, loop, hyperbolic_cosine_recursive(num, loop));
}