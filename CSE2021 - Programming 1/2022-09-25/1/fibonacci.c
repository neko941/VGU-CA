/// @file fibonacci.c

#include <stdio.h>

/**
 * Print the Fibonacci sequence
 * @param[in] length the length of Fibonacci sequence
 */
void fibonacci(int length)
{
    int i;
    int first = 0;
    int second = 1;
    int next;

    printf("\nThe Fibonacci series:\n");
    for ( i = 0 ; i < length ; i++ )
    {
        if ( i <= 1 )
            next = i;
        else
            next = first + second;
            first = second;
            second = next;
        printf("%d\t",next);
    }
}

/**
 * Main entry point of the program.
*/
int main()
{
    int length;

    printf("Enter the length of sequence:\n>> ");
    scanf("%d", &length);
    fibonacci(length);
}
