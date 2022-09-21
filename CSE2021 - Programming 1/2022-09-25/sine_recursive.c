#include <stdio.h>
#include <math.h>

double factorial(int n)
{
    if (n >= 1)
        return n*factorial(n-1);
    else
        return 1;
}

double sine_recursive(double x, int n)
{
   if (n >= 0)
        return pow(-1, n) * pow(x, 2*n+1) / (factorial(2*n+1)) + sine_recursive(x, n-1);
    else
        return 0;
}

int main()
{
    printf("%f\n", sine_recursive(3.14, 10));
}
