/// @file pascal_algebraic.c

#include <stdio.h>


int factorial(int n)
{
    int fac = 1;

    for(; n > 1; n--)
        fac *= n;

    return fac;
}

double factorial_recursive(int n)
{
    if (n >= 1)
        return n*factorial(n-1);
    else
        return 1;
}

int nCr(int n,int r)
{
    return factorial(n) / ( factorial(n-r) * factorial(r) );
}

int pascal_algebraic(int n)
{
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n-i; j++)
            printf("  ");

        for(int j = 0; j <= i; j++)
            printf(" %3d", nCr(i, j));

        puts("");
    }
}

int main()
{
    pascal_algebraic(10);
}
