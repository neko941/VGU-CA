/// @file fibonacci_customized_recursive.c

#include <stdio.h>

/**
 * Print the Fibonacci sequence but it's recursive
 * @param[in] first first element of the sequence
 * @param[in] second second element of the sequence
 * @param[in] length length of the sequence
 */

void fibonacci(int first, int second, int length)
{
    if (length != 2)
    {
        int next = first + second;
        first = second;
        second = next;
        length--;
        printf("%d\t", next);
    }
    return fibonacci(first, second, length);
}

/**
 * Main entry point of the program.
*/
int main()
{
    int first;
    int second;
    int length;
    int i;

    printf("Enter the first of the Fibonacci sequence: \n>> ");
    scanf("%d", &first);
    printf("Enter the second of the Fibonacci sequence: \n>> ");
    scanf("%d", &second);
    printf("Enter the length of the Fibonacci sequence: \n>> ");
    scanf("%d", &length);

    printf("\nThe Fibonacci sequence:\n");
    printf("%d\t%d\t", first, second);
    fibonacci(first, second, length);
}
