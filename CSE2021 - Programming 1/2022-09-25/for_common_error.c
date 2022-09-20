#include <stdio.h>


int main()
{
    // Off-by-one
    // print the following array
//    int array[] = {4, 3, 3, 2, 1};
//    for (int i = 0; i <= 5; i++)
//       printf("%d\t", array[i]);
//    puts("");
//    for (int i = 0; i < 5; i++)
//       printf("%d\t", array[i]);


    // infinite loop
    // calculate the sum from 5 to 10
//    int i = 5;
//    int sum = 0;
//    while (i <= 10){
//       sum += i;
//       printf("%d\n", sum);
//    }

//    for (;;)
//        printf("me chilling in an infinite loop\n");

//    while(1)
//        printf("me chilling in an infinite loop\n");
//        printf("me still chilling but not in an infinite loop\n");

    // unintentional infinite loops
//        int a = 0;
//        while (a < 10) {
//          printf("%d\n", a);
//          if (a = 5)
//             printf("a equals 5!\n");
//          a++;
//        }

    // not execute all instruction / missing curly braces
    // count + print number [0; 5)
//        int count = 0;
//        for (int i = 0; i < 5; i++)
//            count++;
//            printf("me sitting at %d\n", count);
//
//        for (int i = 0; i < 5; i++){
//            count++;
//            printf("me sitting at %d\n", count);
//        }

    // double increment
    // sum of element [0; 5]
    int sum = 0;
    for (int i=0; i<=5; i++)
    {
        sum += i;
        printf("Sum = %d\n", sum);
        i++;
    }
    return 0;
}
