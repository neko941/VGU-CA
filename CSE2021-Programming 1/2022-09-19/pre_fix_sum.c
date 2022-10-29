#include <stdio.h>

int PrefixSum_fill_1d(int arr[], int n, int prefixSum[])
{
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
}

void print_array_1d(int * arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    puts("");
}

int main()
{
    int arr[] = { 10, 4, 16, 20 };  // initialize array
    int size = sizeof(arr) / sizeof(arr[0]); // compute the size of array
    int prefixSum[size]; // declare a new array to store value
    PrefixSum_fill_1d(arr, size, prefixSum); // use function to update array

    // print result
    printf("Original Array:\n\t");
    print_array_1d(arr, size);
    printf("Pre-fix Sum Array:\n\t");
    print_array_1d(prefixSum, size);
}
