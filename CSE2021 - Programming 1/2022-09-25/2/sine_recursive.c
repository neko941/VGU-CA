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
 * Formula (Latex): sin(x) = (-1)^{n}\sum_{n=0}^{\infty}\frac{x^{(2n+1)}}{(2n+1)!} = 1 - \frac{x^{3}}{3!} + \frac{x^{5}}{5!} - \frac{x^{7}}{7!} + \frac{x^{9}}{9!} - ...
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
    double num;
    int loop;

    printf("Enter the number for sine: \n>> ");
    scanf("%lf", &num);
    printf("Enter the number of loop: \n>> ");
    scanf("%d", &loop);
    printf("sin(x=%f, loop=%d) = %f\n", num, loop, sine_recursive(num, loop));
}
