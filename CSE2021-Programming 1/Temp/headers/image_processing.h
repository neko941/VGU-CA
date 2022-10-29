#ifndef IMAGE_PROCESSING_H_
#define IMAGE_PROCESSING_H_

#define LEN(arr) ((int) (sizeof (arr) / sizeof (arr)[0]))

void print_2d_array(int *arr)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<2; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

#endif
