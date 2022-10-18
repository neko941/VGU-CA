#include <stdio.h>
#include <stdlib.h>

int *i_arrayNew_1d(int _size)
{
    return (int *)calloc(_size, sizeof(int));
}

void i_arrayPrint_2d(int *matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        printf("\t");
        for (int j = 0; j < col; j++)
        {
            printf("%d\t", matrix[i * col + j]);
        }
        printf("\n");
    }
}

int diagonalDoubleSquareSum(int *matrix, int row, int col)
{
    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j)
            {
                sum += 2 * matrix[i * col + j] * matrix[i * col + j];
            }
        }
    }
    return sum;
}

int main()
{
    int row = 3;
    int col = 3;
    int *arr = i_arrayNew_1d(row * col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i * row + j] = j * col + i + 1;
        }
    }
    printf("The matrix:\n");
    i_arrayPrint_2d(arr, row, col);

    printf("The result: ");
    printf("%d\n", diagonalDoubleSquareSum(arr, row, col));
}