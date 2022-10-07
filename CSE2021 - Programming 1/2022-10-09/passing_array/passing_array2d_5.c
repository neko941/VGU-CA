#include <stdio.h>

void printarray(void *array, int row, int col)
{
    int *charArray = (int *)array;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", charArray[i * col + j]);
        }
        printf("\n");
    }
}

int main()
{
    int array[2][3] = {{1, 2, 5}, {3, 4, 6}};
    printarray(array, 2, 3);
}