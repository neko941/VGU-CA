#include <stdio.h>
#include <stdlib.h>

int* i_array_new_1d(int n)
{
    return (int*) calloc(n+1, sizeof(int));
}

int* factorial_dynamic(int n)
{
    int* result = i_array_new_1d(n+1);
    result[0] = 1;
    for (int i=1; i<=n; i++)
        result[i] = result[i-1] * i;
    return result;
}

int pascal_algebraic_dynamic(int n)
{
    int* factorial = factorial_dynamic(n);
    for (int i=0; i<=n; ++i)
    {
        for(int j = 0; j <= n-i; j++)
            printf("  ");
        for (int j=0; j<i; j++)
//            printf("%3d ", factorial[i-1] / (factorial[j-1]*factorial[i-j]) + factorial[i-1] / (factorial[j] * factorial[i-j-1]));
            printf("%3d ", factorial[i] / (factorial[i-j] * factorial[j]));
        printf("  1\n");
    }
}

int main()
{
    pascal_algebraic_dynamic(10);
}
