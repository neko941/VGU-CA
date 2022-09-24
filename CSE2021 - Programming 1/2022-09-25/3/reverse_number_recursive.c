/// @file reverse_number_recursive.c

#include <stdio.h>

/**
 * Reverse given number but it's recursive
 * Example: 12345678910 => (0)1987654321
 * @param[in] x number that u wanna reverse
 * @param[in] reverse current reversed number
 * @param[out] reverse final reversed number
 */
long long int reverse_number(long long int x, long long int reverse)
{
    if(x!=0)
        reverse_number(x / 10, reverse * 10 + x % 10);
    else
        return reverse;
}

/**
 * Main entry point of the program.
*/
int main()
{
    long long int n = 12345678910;
    printf("Number = %lld\n", n);
    long long int result = reverse_number(n, 0);
    printf("Reversed number = %lld", result);
}
