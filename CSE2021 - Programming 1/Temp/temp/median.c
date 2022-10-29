#include <stdio.h>
#include <stdlib.h>

int generate_ab(int a, int b)
{
    /*
    * This function is to generate an integer number within the range [a, b]
    * Input: Two integer a,b
    * Output: an integer number within [a, b]
    * Example: generate_ab(4,9)
    * Output: 8
    */   
    return rand()% (b - a + 1) + a;
}


void bubble_sort(int array[], int length)
{
    /*
    * This function is an implementation of bubble sort.
    * Input: an array of integers, length of array.
    * Output: sorted array in ascending order.
    * Example: array = {1,5,2,3,1}
               bubble_sort(array, 5)
    * Output: array = {1,1,2,3,5}
    */

    for(int i=0; i<length- 1;i++)
    {
        for(int j=i+1; j<length;j++)
        {
            if(array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

float median(int array[], int length)
{
    /*
    * This function is to return the median value of an array of integers.
    * Input: an array of integers, length of array.
    * Output: median value.
    * Example: array = {1,2,5,3,2,4}
               med = median(array, 6)
    * Output: med = 2.5
    */

    bubble_sort(array, length);
    if(length % 2 == 1)
    {
        int idx = (length + 1)/2;
        float median = (float) array[idx - 1];
        return median;
    }
    else
    {
        int idx = length / 2;
        int num_1 = array[idx - 1];
        int num_2 = array[idx];
        float median = (float) (num_1 + num_2)/2;
        return median;
    }
}
int main()
{
    int array[10];
    for(int i=0; i<10;i++)
    {
        array[i] = generate_ab(1,9);
    }
    float med = median(array, 10);
    for(int i=0; i<10;i++)
    {
        printf("%d\t",array[i] );
    }

    putchar('\n');
    printf("median is: %.2f\n", med);
}