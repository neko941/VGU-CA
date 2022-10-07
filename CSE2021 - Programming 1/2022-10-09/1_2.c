#include <stdio.h>
#include <math.h>

double ln(double x, int loop)
{
    double result = 0;
    for (int i = 1; i <= loop; i++)
    {
        result -= pow(x, i) / i;
    }
    return result;
}

int main()
{
    float x = 0.5;
    int loop = 10;
    printf("ln(x=%f, loop=%d) = %f\n", x, loop, ln(x, loop));
    loop = 100;
    printf("ln(x=%f, loop=%d) = %f", x, loop, ln(x, loop));
}