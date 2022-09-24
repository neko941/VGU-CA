/// @file fibonacci_basedon_pascal.c

#include <stdio.h>
#include <stdlib.h>

/**
 * Print tje given array
 * @param[in] arr the array 
 * @param[in] _size size of the array
 */
void i_array_print_1d(int *arr, int _size)
{
    for(int i=0; i<_size; i++)
        if (arr[i] != 0)
            printf("%3d ", arr[i]);
    puts("");
}

/**
 * Create a new dynamic array with the given size
 * @param[in] n the size of the array
 * @param[out] _ array with given size
 */
int* i_array_new_1d(int n)
{
    return (int*) calloc(n, sizeof(int));
}

/**
 * Print tje given array
 * @param[in] row number of row 
 * @param[in] col number of column
 * @param[out] _ array[row][col]
 */
int** i_array_new_2d(int row, int col)
{
    int** matrix = (int**)calloc(row, sizeof(int*));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (int*)calloc(col, sizeof(int));
    }
    return matrix;
}

/**
 * Print tje given array
 * @param[in] matrix the 2d matrix 
 * @param[in] row number of row 
 * @param[in] col number of column
 */
void i_matrix_print_2d (int ** matrix, int row, int col)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if (matrix[i][j] != 0)
                printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/**
 * Compute the Pascal's Triangle with the given level
 * @param[in] n Pascal's Triangle up to n levels
 * @param[out] result return 2d array stored the pascal triangle
 */
int** pascal_triangle(int n)
{
    int** result = i_array_new_2d(n, n);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<=i; j++)
        {
            if (i==0 || j==0)
            {
                result[i][j] = 1;
            }
            else if (i==j)
            {
                result[i][j] = 1;
            }
            else
            {
                result[i][j] = result[i-1][j-1] + result[i-1][j];
            }
        }
    }

    return result;
}

/**
 * Compute the Fibonacci Sequence based on Pascal's Triangle with the given level
 * @param[in] matrix matrix of Pascal's Triangle 
 * @param[in] n Pascal's Triangle up to n levels / length of Fibonacci Sequence
 * @param[out] result return 2d array stored the pascal triangle
 */
int* fibonacci_basedon_pascal(int** matrix, int n)
{
    int* result = i_array_new_1d(n);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<=i; j++)
        {
            result[i] += matrix[j][i-j];
        }
    }

    return result;
}

/**
 * Main entry point of the program.
 */
int main()
{
    int n = 10;
    int** result = pascal_triangle(n);
    printf("Pascal's Triangle\n");
    i_matrix_print_2d(result, n, n);

    int* result1 = fibonacci_basedon_pascal(result, n);
    printf("\nFibonacci Sequence\n");
    i_array_print_1d(result1, n);
}