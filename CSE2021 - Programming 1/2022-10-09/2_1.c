#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int i_arrayPrint_1d(int *arr, int _size)
{
    for (int i = 0; i < _size; i++)
    {
        printf("%d \t", *(arr + i));
    }
    puts("");
}

void i_arrayPrintCustom_1d(int *arr, int _size, char *title, char *preElement, char *postElement)
{
    printf("%s", title);
    for (int i = 0; i < _size; i++)
    {
        printf("%s%d%s", preElement, *(arr + i), postElement);
    }
    puts("");
}

int *i_arrayNew_1d(int _size)
{
    return (int *)calloc(_size, sizeof(int));
}

int *i_arrayClip_1d(int *arr, int _size, int min_value, int max_value)
{
    int *result = i_arrayNew_1d(_size);
    for (int i = 0; i < _size; i++)
    {
        if (arr[i] < min_value)
        {
            result[i] = min_value;
        }

        else if (arr[i] > max_value)
        {
            result[i] = max_value;
        }

        else
        {
            result[i] = arr[i];
        }
    }
    return result;
}

void i_arrayClip_1d_inplace(int *arr, int _size, int min_value, int max_value)
{
    for (int i = 0; i < _size; i++)
    {
        if (arr[i] < min_value)
        {
            arr[i] = min_value;
        }

        else if (arr[i] > max_value)
        {
            arr[i] = max_value;
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(arr) / sizeof(arr[0]);
    i_arrayPrint_1d(arr, length);
    i_arrayClip_1d_inplace(arr, length, 3, 6);
    i_arrayPrint_1d(arr, length);

    puts("");

    int arr1[] = {4, 12, 23, 4, 35, 16, 7, 48, 19};
    int length1 = sizeof(arr1) / sizeof(arr1[0]);
    i_arrayPrintCustom_1d(arr1, length1, "Original:\t", "", " \t");
    int *arr2 = i_arrayClip_1d(arr1, length1, 11, 33);
    i_arrayPrintCustom_1d(arr2, length1, "Clipped :\t", "", " \t");
}