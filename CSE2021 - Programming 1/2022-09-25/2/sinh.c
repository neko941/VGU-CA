/// @file sinh.c

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
 * Calculates the sine of a number
 * Formula (Latex): sinh(x) = \sum_{n=0}^{\infty}\frac{x^{2n}}{(2n)!} = x + \frac{x^{3}}{3!} + \frac{x^{5}}{5!} + \frac{x^{7}}{7!} + \frac{x^{9}}{9!} + ...
 * @param[in] x number you wanna calculate sine
 * @param[in] n number of loops
 * @param[out] result sine of x
 */
double hyperbolic_sine(double x, int n)
{
    double sum;

    for (int i = 0; i < n; i++)
        sum += pow(x, 2*i+1) / factorial(2*i+1);

    return sum;
}

/**
 * Main entry point of the program.
*/
int main()
{
    double num;
    int loop;

    printf("Enter the number for hyperbolic sine: \n>> ");
    scanf("%lf", &num);
    printf("Enter the number of loop: \n>> ");
    scanf("%d", &loop);
    printf("sinh(x=%f, loop=%d) = %f\n", num, loop, hyperbolic_sine(num, loop));
}
