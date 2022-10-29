#include <stdio.h>
#include <stdlib.h> // for malloc
#include "./headers/array.h"

int main()
{
    int n = 6;
    int *var_arr = i_array_new_1d(n);

    for (int i = 0; i < n; i++)
    {
        *(var_arr + i) = i+1;
    }
    i_array_print_1d(var_arr, n);

    int **mat= i_array_convert_1to2(var_arr, 3, 2);
    i_matrix_print_2d(mat, 3, 2);

    _array_reverse_1d(var_arr, 0, n-1);
    i_array_print_1d(var_arr, n);
    return 0;
}

