#include <stdio.h>

int main() {

  long long int n=12345678910;
  int reverse = 0;
  int remainder;

  while (n != 0) {
    remainder = n % 10;
    reverse = reverse * 10 + remainder;
    n /= 10;
  }

  printf("Reversed number = %d", reverse);

  return 0;
}
