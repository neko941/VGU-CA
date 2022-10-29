#ifndef ARRAY_H_
#define ARRAY_H_

int* i_array_new_1d(int _size)
{
    return (int *)malloc(sizeof(int *) + _size * sizeof(int));
}

int ** i_array_new_2d(int row, int col)
{
    int** matrix = (int**)malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (int*)malloc(col * sizeof(int));
    }
    return matrix;
}

int i_array_print_1d (int *arr, int _size)
{
    printf("1D Array:\n\t");
    for(int i=0; i<_size; i++)
    {
        printf("%d \t", *(arr + i));
    }
    puts("");
}

void i_matrix_print_2d (int ** matrix, int row, int col)
{
    int i,j;
    printf("2D Array: \n");
    for(i=0; i<row; i++)
    {
        printf("\t");
        for(j=0; j<col; j++)
        {
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
}

int ** i_array_convert_1to2 (int *arr, int row, int col)
{
    int i,j;
    int** matrix = i_array_new_2d(row, col);

    // matrix[i][j] is equal *(*(matrix+i)+j)
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            matrix[i][j] = arr[i*col+j];
        }
    }
    return matrix;
}

void _array_reverse_1d(int *arr, int start, int _end)
{
    int temp;
    while (start < _end)
    {
        temp = arr[start];
        arr[start] = arr[_end];
        arr[_end] = temp;
        start++;
        _end--;
    }
}

#endif
