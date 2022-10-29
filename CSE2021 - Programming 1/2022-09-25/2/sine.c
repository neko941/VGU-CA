/// @file sine.c

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
 * Calculates the sine of a number
 * Formula (Latex): sin(x) = (-1)^{n}\sum_{n=0}^{\infty}\frac{x^{(2n+1)}}{(2n+1)!} = 1 - \frac{x^{3}}{3!} + \frac{x^{5}}{5!} - \frac{x^{7}}{7!} + \frac{x^{9}}{9!} - ...
 * @param[in] x number you wanna calculate sine
 * @param[in] n number of loops
 * @param[out] result sine of x
 */
double sine(double x, int n)
{
    double result = 0;
    for (int i = 0; i <= n; i++)
        result += pow(-1, i) * pow(x, 2 * i + 1) / factorial(2 * i + 1);
    return result;
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
    printf("sin(x=%f, loop=%d) = %f\n", num, loop, sine(num, loop));
}
