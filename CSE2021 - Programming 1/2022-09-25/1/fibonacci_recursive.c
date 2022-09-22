/// @file fibonacci_recursive.c

#include <stdio.h>

/**
 * Calculate the Fibonacci value at length n
 * @param[in] n the position in Fibonacci sequence
 */
int fibonacci(int n)
{
   if (n == 0)
      return 0;
   else if (n == 1)
      return 1;
   else
      return fibonacci(n-1) + fibonacci(n-2);
}

/**
 * Main entry point of the program.
*/
int main()
{
    int i;
    int length;

    printf("Enter the length of sequence:\n>> ");
    scanf("%d", &length);

    printf("\nThe Fibonacci series:\n");
    for (i = 0; i < length; i++)
      printf("%d\t", fibonacci(i));
}
