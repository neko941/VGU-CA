#include <stdio.h>

int main()
{
    // double increment

    // sum of element [0; 5]
    int sum = 0;
    for (int i=0; i<=5; i++)
    {
        sum += i;
        printf("Sum = %d\n", sum);
        i++;
    }

    // solve
    int sum = 0;
    for (int i=0; i<=5; i++)
    {
        sum += i;
        printf("Sum = %d\n", sum);
    }
}
