#include <stdio.h>
#include <stdlib.h>

int **i_arrayNew_2d(int row, int col)
{
    int **matrix = (int **)calloc(row, sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (int *)calloc(col, sizeof(int));
    }
    return matrix;
}

int **i_arrayConvert_1To2(int *arr, int row, int col)
{
    int **matrix = i_arrayNew_2d(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = arr[i * col + j];
        }
    }
    return matrix;
}

void printarray(void *array, int row, int col)
{
    int *intArray = array;
    int **array_2d = i_arrayConvert_1To2(intArray, row, col);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", array_2d[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int array[2][3] = {{1, 2, 5}, {3, 4, 6}};
    int row = 2;
    int col = 3;
    printarray(array, row, col);
}