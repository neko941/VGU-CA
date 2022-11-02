#include <stdio.h>

int main()
{
    // unintentional infinite loops

    // print number from 0 to 9, if equals 5 print equal 5
    int a = 0;
    while (a < 10) {
      printf("%d\n", a);
      if (a = 5)
         printf("a equals 5!\n");
      a++;
    }

    // solve
    int a = 0;
    while (a < 10) {
      printf("%d\n", a);
      if (a == 5)
         printf("a equals 5!\n");
      a++;
    }
}
