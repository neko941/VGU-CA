/// @file reverse_number.c

#include <stdio.h>

/**
 * Reverse given number
 * Example: 12345678910 => (0)1987654321
 * @param[in] x number that u wanna reverse
 * @param[out] reverse reversed number
 */
long long int reverse_number(long long int x)
{
    int reverse = 0; ///< variable to store the result
    int remainder; ///< remainder after mod 10

    while (x != 0)
    {
        remainder = x % 10;
        reverse = reverse * 10 + remainder;
        x /= 10;
    }
    return reverse;
}

/**
 * Main entry point of the program.
*/
int main()
{
    long long int n = 12345678910;
    printf("Number = %lld\n", n);
    long long int result = reverse_number(n);
    printf("Reversed number = %lld", result);
}
