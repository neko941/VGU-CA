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


int get_max(int array[], int length)
{
    /*
    * This function is to find the maximum value in an array of integer.
    * Input: an integer array, length of that array
    * Output: maximum number of the array
    * Example: a = {1,3,5,2,4};
               m = get_max(a, 5);
    * Output: m = 5
    */ 

    int max_num = array[0];
    for (int i=1; i<length;i++)
    {
        if(array[i] > max_num)
        {
            max_num = array[i];
        }
    }
    return max_num;
}

int get_min(int array[], int length)
{
    /*
    * This function is to find the minimum value in an array of integer.
    * Input: an integer array, length of that array
    * Output: minimum number of the array
    * Example: a = {1,3,5,2,4};
               m = get_min(a, 5);
    * Output: m = 1
    */ 
    int min_num = array[0];
    for (int i=1; i<length;i++)
    {
        if(array[i] < min_num)
        {
            min_num = array[i];
        }
    }
    return min_num;
}

float average(int array[], int length)
{
    /*
    * This function is to find the average value of the elements in an integer array.
    * Input: an integer array, length of that array
    * Output: average value of an integer array
    * Example: array = {1,3,5,2,4};
               a = average(array, 5);
    * Output: a = 3
    */ 
    float sum = 0.0;
    for (int i=0;i<length;i++)
    {
        sum += array[i];
    }
    return sum/length;
}

int check(int array[], int num, int length)
{
    /*
    * This function is to check whether a specific value is in an array or not.
    * Input: an integer array, a number that you want to check, length of that array
    * Output: 0 if the value you want to find is not in the array, otherwise 1
    * Example: a = {1,3,5,2,4};
               c = check(a,2, 5);
    * Output: c = 1
    * Example: a = {1,3,5,2,4};
               c = check(a, 10, 5);
    * Output: c = 0
    */ 
    for(int i=0; i<length;i++)
    {
        if(array[i] == num)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int array[] = {1,2,4,2,5,2, 10};
    printf("%d\n",get_max(array, 7));
    printf("%d\n",get_min(array, 7));
    printf("%.2f\n",average(array, 7));
    printf("%d\n",check(array,6 ,7));
}