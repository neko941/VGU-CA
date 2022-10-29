#include <stdio.h>
#include <math.h>

double function(double x)
{
    return x / 2 * (1 + x + 0.04 * pow(x, 3));
}

int main()
{
    float x = 0.5;
    printf("Function(x=%f) = %f\n", x, function(x));
    x = 1.5;
    printf("Function(x=%f) = %f", x, function(x));
}