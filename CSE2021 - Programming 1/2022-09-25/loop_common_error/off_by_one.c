#include <stdio.h>

int main()
{
    // Off-by-one

    // print the following array
    int array[] = {4, 3, 3, 2, 1};
    for (int i = 0; i <= 5; i++)
       printf("%d\t", array[i]);
    puts("");

    // solve
    for (int i = 0; i < 5; i++)
       printf("%d\t", array[i]);
}
