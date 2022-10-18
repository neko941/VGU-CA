#include <time.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/**
 * Create a new 1-dimensional array with the given size
 * @param[in] _size the size of the array
 * @param[out] _ empty 1-dimensional array filled with 0
 */
int *i_arrayNew_1d(int _size)
{
    return (int *)calloc(_size, sizeof(int));
}

/**
 * Create a new 1-dimensional array with the given size filled values within range [min, max]
 * @param[in] _size the size of the array
 * @param[in] min the minimum value of the array
 * @param[in] max the maximum value of the array
 * @param[out] _ 1-dimensional array 
 */
int *i_arrayNewRandom_1d(int _size, int min, int max)
{
    assert(min <= max);
    int *arr = i_arrayNew_1d(_size);
    for (int i = 0; i < _size; i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
    }
    return arr;
}

/**
 * Create a new 2-dimensional array with the given size
 * @param[in] row number of rows
 * @param[in] col number of columns
 * @param[out] _ empty 2-dimensional array filled with 0
 */
int **i_arrayNew_2d(int row, int col)
{
    int **matrix = (int **)calloc(row, sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (int *)calloc(col, sizeof(int));
    }
    return matrix;
}

/**
 * Create a new 2-dimensional array with the given size filled with values within range [min, max]
 * @param[in] row number of rows
 * @param[in] col number of columns
 * @param[in] min minimum value of the array
 * @param[in] max maximum value of the array
 * @param[out] _ 2-dimensional array
 */
int **i_arrayNewRandom_2d(int row, int col, int min, int max)
{
    assert(min <= max);
    int **arr = i_arrayNew_2d(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = rand() % (max - min + 1) + min;
        }
    }
    return arr;
}

/**
 * Convert 2-dimensional array to 1-dimensional array
 * @param[in] row number of rows
 * @param[in] col number of columns
 * @param[out] _ 1-dimensional array
 */
int *i_arrayConvert_2To1(int **matrix, int row, int col)
{
    int *arr = i_arrayNew_1d(row * col);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i * col + j] = matrix[i][j];
        }
    }
    return arr;
}

void i_arrayPrint_2das1d(int *array, int row, int col)
{
    printf("i_arrayPrint_2das1d\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", array[i * col + j]);
        }
        printf("\n");
    }
}

void i_arrayPrint_subscritable2d(int **arr, int row, int col)
{
    printf("i_arrayPrint_subscritable2d\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", arr[i][j]);
        }
        puts("");
    }
    puts("");
}

void i_arrayPrint_pointer2d(int **arr, int row, int col)
{
    printf("i_arrayPrint_pointer2d\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", *(*(arr + i) + j));
        }
        puts("");
    }
    puts("");
}

void i_arrayPrint_pointer1d(int *arr, int _size)
{
    printf("i_arrayPrint_pointer1d\n");
    for (int i = 0; i < _size; i++)
    {
        printf("%d ", *(arr + i));
    }
    puts("\n");
}

void i_arrayPrint_subscritable1d(int *arr, int _size)
{
    printf("i_arrayPrint_subscritable1d\n");
    for (int i = 0; i < _size; i++)
    {
        printf("%d ", arr[i]);
    }
    puts("\n");
}

int main()
{

    // set random seed
    srand(time(NULL));

    // initialization 1d
    int size = 10;
    int *arr = i_arrayNewRandom_1d(size, 10, 100);

    // subscritable 1d
    i_arrayPrint_subscritable1d(arr, size);

    // pointer 1d
    i_arrayPrint_pointer1d(arr, size);

    // horizontal line
    for (int i = 0; i < size*4; i++)
    {
        printf("--");
    }
    puts("\n");

    // initialization 2d
    int row = 5;
    int col = 5;
    int **arr2 = i_arrayNewRandom_2d(row, col, 10, 99);

    // subscritable 2d
    i_arrayPrint_subscritable2d(arr2, row, col);

    // pointer 2d
    i_arrayPrint_pointer2d(arr2, row, col);

    // 2d as 1d
    int *arr2as1 = i_arrayConvert_2To1(arr2, row, col);
    i_arrayPrint_subscritable1d(arr2as1, row * col);
    i_arrayPrint_2das1d(arr2as1, row, col);
}