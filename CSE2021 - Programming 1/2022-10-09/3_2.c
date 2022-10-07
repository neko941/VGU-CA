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

int diagonalSquareSum(int **matrix, int row, int col)
{
    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i==j)
            {
                sum += matrix[i][j] * matrix[i][j];
            }
        }
    }
    return sum;
}

int main()
{
    int row = 3;
    int col = 3;
    int **arr = i_arrayNew_2d(row, col);
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            arr[j][i] = i * row + j + 1;
        }
    }

    printf("The matrix:\n");
    i_arrayPrint_2d(arr, row, col);

    printf("Sum of square diagonal = %d\n", diagonalSquareSum(arr, row, col));
}