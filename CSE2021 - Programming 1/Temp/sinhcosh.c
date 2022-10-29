#include <stdio.h>
#include <math.h>
#include <stdlib.h>


long long int factorial_simple(int n)
{
    /*
    * This function is to compute the factorial n! of a number n.
    * Naive loop is used.
    * Input: an integer number n
    * Output: n!
    * Example: factorial_simple(5)
    * Output: 120
    */

    if (n==0 || n == 1)
    {
        return 1;
    }
    long long int result = 1;
    for (int i=2; i<=n;i++)
    {
        result*=i;
    }
    return result;
}

int factorial_recursive(int n)
{
    /*
    * This function is to compute the factorial n! of a number n.
    * Recursion is used.
    * Input: an integer number n
    * Output: n!
    * Example: factorial_recursive(5)
    * Output: 120
    */

    if(n ==0 || n ==1)
    {
        return 1;
    }
    return n*factorial_recursive(n - 1);
}

float sinh_x(float x, int loops)
{
    /*
    * This function is to compute the value of a hypebolic function, sinh(x).
    * This one compute sinh(x) based on a power series.
    * Input: a float number x, an integer number of loop (10 - 20 is recommended to avoid overflow)
    * Output: sinh(x)
    * Example: sinh_x(2.0, 15)
    * Output: 
    */

    float result = 0.0;
    for(int i=0; i<loops; i++)
    {
        result+= (pow(x, 2*i + 1)/(factorial_simple(2*i + 1)));
    }
    return result;
}

float cosh_x(float x, int loops)
{
    float result = 0.0;
    for(int i=0; i<loops; i++)
    {
        result+= (pow(x, 2*i)/(factorial_simple(2*i)));
    }
    return result;
}
int main()
{
    printf("sinh(%.2f) is %f\n", 2.0, sinh_x(2.0, 15));
    printf("cosh(%.2f) is %f\n", 2.0, cosh_x(2.0, 15));
}