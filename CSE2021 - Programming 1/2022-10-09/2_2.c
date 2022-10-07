#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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

int *i_arraySign_1d(int *arr, int _size)
{
    int *result = i_arrayNew_1d(_size);
    for (int i = 0; i < _size; i++)
    {
        if (arr[i] == 0)
        {
            result[i] = 0;
        }
        else
        {
            result[i] = (int)(arr[i] / abs(arr[i]));
        }
    }
    return result;
}

int *i_arrayDiff_1d(int *arr, int _size)
{
    int *result = i_arrayNew_1d(_size - 1);
    for (int i = 0; i < _size - 1; i++)
    {
        result[i] = arr[i + 1] - arr[i];
    }
    return result;
}

int main()
{
    int arr[] = {1, 3, 7, 1, 2, 6, 0, 1};
    int length = sizeof(arr) / sizeof(arr[0]);
    i_arrayPrintCustom_1d(arr, length, "Original:\t", "", " \t");
    int *diff = i_arrayDiff_1d(arr, length);
    i_arrayPrintCustom_1d(diff, length - 1, "Diff:\t\t", "   ", " \t");
    int *sign = i_arraySign_1d(diff, length - 1);
    i_arrayPrintCustom_1d(sign, length - 1, "Sign:\t\t", "   ", " \t");
}