#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <stdlib.h>

unsigned char *uc_arrayNew_1d(int _size)
{
    return (unsigned char *)calloc(_size, sizeof(unsigned char));
}

double **d_arrayNew_2d(int row, int col)
{
    double **matrix = (double **)calloc(row, sizeof(double *));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (double *)calloc(col, sizeof(double));
    }
    return matrix;
}

char *c_arrayNew_1d(int _size)
{
    return (char *)calloc(_size, sizeof(char));
}

char **c_arrayNew_2d(int row, int col)
{
    char **matrix = (char **)calloc(row, sizeof(char *));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (char *)calloc(col, sizeof(char));
    }
    return matrix;
}

double d_arrayMaxWidthIndeces_2d(double **input, int row, int col, int *x, int *y)
{
    double max = 0.0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (input[i][j] > max)
            {
                max = input[i][j];
                *y = i;
                *x = j;
            }
        }
    }
    return max;
}

#endif