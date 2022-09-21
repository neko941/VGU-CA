#include <stdio.h>
#include <math.h>

double factorial(int n)
{
    double fac = 1;

    for (int i = 1; i <= n; i++)
        fac *= i;

    return fac;
}

double compute_sinh(double x, int n)
{
    double sum;

    for (int i = 0; i < n; i++)
        sum += pow(x, 2*i) / factorial(2*i);

    return sum;
}

int main()
{
    printf("%f\n", compute_sinh(3.14, 10));
}
