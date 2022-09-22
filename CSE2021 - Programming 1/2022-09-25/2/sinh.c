#include <stdio.h>
#include <math.h>

double factorial(int n)
{
    double fac = 1;

    for (int i = 1; i <= n; i++)
        fac *= i;

    return fac;
}

double hyperbolic_sine(double x, int n)
{
    double sum;

    for (int i = 0; i < n; i++)
        sum += pow(x, 2*i+1) / factorial(2*i+1);

    return sum;
}

int main()
{
    printf("%f\n", hyperbolic_sine(3.14, 10));
}
