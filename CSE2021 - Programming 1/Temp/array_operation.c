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

void add(float arr1[], float arr2[], float des[], int length)
{
    /*
    * This function is to compute the element wise addition between two arrays.
    * Input: 2 source arrays, 1 destination array, length of those 3 array (must be the same).
    * Output: sum array of two source arrays.
    * Example: a = {1, 2, 3}
               b = {4, 5, 6}
               c = {_, _, _}
               add(a, b, c, 3)
    
    * Output:  a = {1, 2, 3}
               b = {4, 5, 6}
               c = {5, 7, 9}
    */    
    for(int i=0; i<length;i++)
    {
        des[i] = arr1[i] + arr2[i];
    }
}

void sub(float arr1[], float arr2[], float des[], int length)
{
    /*
    * This function is to compute the element-wise subtraction between two arrays.
    * Input: 2 source arrays, 1 destination array, length of those 3 array (must be the same).
    * Output: subtracted result array of two source arrays.
    * Example: a = {1, 2, 3}
               b = {4, 5, 6}
               c = {_, _, _}
               sub(a, b, c, 3)
    
    * Output:  a = {1, 2, 3}
               b = {4, 5, 6}
               c = {-3, -3, -3}
    */  
    for(int i=0; i<length;i++)
    {
        des[i] = arr1[i] - arr2[i];
    }
}

void multiply(float arr1[], float arr2[], float des[], int length)
{
    /*
    * This function is to compute the element-wise multiplication between two arrays.
    * Input: 2 source arrays, 1 destination array, length of those 3 array (must be the same).
    * Output: multiplicated result array of two source arrays.
    * Example: a = {1, 2, 3}
               b = {4, 5, 6}
               c = {_, _, _}
               multiply(a, b, c, 3)
    
    * Output:  a = {1, 2, 3}
               b = {4, 5, 6}
               c = {4, 10, 18}
    */ 

    for(int i=0; i<length;i++)
    {
        des[i] = arr1[i] * arr2[i];
    }
}

void division(float arr1[], float arr2[], float des[], int length)
{
    /*
    * This function is to compute the element-wise division between two arrays.
    * Input: 2 source arrays, 1 destination array, length of those 3 array (must be the same).
    * Output: divided result array of two source arrays. If the element i-th of array 2 is 0, then the i-th element of destination array
    * will be set as 99999 by default.
    * Example: a = {1, 2, 3}
               b = {4, 5, 6}
               c = {_, _, _}
               division(a, b, c, 3)
    
    * Output:  a = {1, 2, 3}
               b = {4, 5, 6}
               c = {0.25, 0.4, 0.5}
    */ 
    for(int i=0; i<length;i++)
    {
        if(arr2[i] != 0)
        {
            des[i] = arr1[i] / arr2[i];            
        }
        else
        {
            des[i] = 99999;
        }

    }
}

float dot(float arr1[], float arr2[], int length)
{
    /*
    * This function is to compute the dot product between two arrays.
    * Input: 2 source arrays, length of those 2 arrays (must be the same).
    * Output: dot product of two source arrays.
    * Example: a = {1, 2, 3}
               b = {4, 5, 6}
               dot(a, b, 3)
    
    * Output:  32
    */ 
    float result = 0.0;
    for (int i=0; i<length; i++)
    {
        result+= arr1[i]*arr2[i];
    }
}

int main()
{
    float a[3];
    float b[3];
    for (int i=0; i<3;i++)
    {
        a[i] = (float)generate_ab(1,9);
        b[i] = (float)generate_ab(1,9);
    }
    for (int i=0; i<3;i++)
    {
        printf("%.2f\t%.2f\n", a[i], b[i]);
    }    
    float des[3];
    division(a, b, des, 3);
    for (int i = 0; i< 3;i++)
    {
        printf("%.2f\t", des[i]);
    }
    printf("%.2f\n", dot(a, b, 3));
}