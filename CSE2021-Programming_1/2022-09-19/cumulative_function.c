#include <stdio.h>

int cumulative_function(int n)
{
    int sum = 0;
    for (int i=0; i<=n; i++)
    {
        sum += i;
        printf("%d\n", sum);
    }
    return sum;
}

int main()
{
    int n=5;
    int sum = cumulative_function(n);
    printf("Sum: %d", sum);
}
