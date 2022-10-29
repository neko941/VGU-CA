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

void i_arrayPrint_2d(int **matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        printf("\t");
        for (int j = 0; j < col; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int row = 4;
    int col = 3;
    int **arr = i_arrayNew_2d(row, col);
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            arr[j][i] = i * row + j + 1;
        }
    }
    i_arrayPrint_2d(arr, row, col);
}