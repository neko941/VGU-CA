#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

// global parameters
const int HEIGHT = 218;
const int WIDTH = 300;
const int CHANNEL = 3;

const int WINDOW_SIZE = 3;

void read_color_image(unsigned char color_image[HEIGHT][WIDTH][CHANNEL], char* file_name)
{
    // ...
    int height, width, channel;
    unsigned char* temp = stbi_load(file_name, &width , &height , &channel, 0);
    if(temp == NULL)
    {
    	printf("Unable to load image.\n");
    	exit(1);
    }
    for(int i=0; i<HEIGHT;i++)
    {
    	for(int j=0; j<WIDTH;j++)
    	{
    		for(int k=0; k <CHANNEL;k++)
    		{
    			color_image[i][j][k] = temp[i*WIDTH*CHANNEL + j*CHANNEL + k];
    		}
    	} 
	}
	stbi_image_free(temp);
}

void convert_to_grayscale(unsigned char color_image[HEIGHT][WIDTH][CHANNEL], unsigned char grayscale_image[HEIGHT][WIDTH])
{
    // ...
    for(int i=0;i<HEIGHT;i++)
    {
    	for(int j=0; j<WIDTH;j++)
    	{
    		unsigned char r = color_image[i][j][0];
    		unsigned char g = color_image[i][j][1];
    		unsigned char b = color_image[i][j][2];
    		grayscale_image[i][j] = 0.3*r + 0.59*g + 0.11*b;
    	}
    }
}

void save_color_image(unsigned char color_image[HEIGHT][WIDTH][CHANNEL], char* file_name)
{
    // ...
    unsigned char* temp = (unsigned char*) malloc(HEIGHT*WIDTH*CHANNEL);
    for(int i=0; i< HEIGHT;i++)
    {
    	for(int j=0; j< WIDTH; j++)
    	{
    		for(int k = 0; k<CHANNEL;k++)
    		{
    			temp[i*WIDTH*CHANNEL + j*CHANNEL + k] = color_image[i][j][k];
    		}
    	}
    }
    stbi_write_png(file_name, WIDTH, HEIGHT, CHANNEL, temp, WIDTH*CHANNEL);  
    free(temp);  
}

void save_grayscale_image(unsigned char grayscale_image[HEIGHT][WIDTH], char* file_name)
{
    // ...
    unsigned char* temp = (unsigned char*) malloc(HEIGHT*WIDTH);
    for(int i=0; i<HEIGHT;i++)
    {
    	for(int j=0;j<WIDTH;j++)
    	{
    		temp[i*WIDTH + j] = grayscale_image[i][j];
    	}
    }
    stbi_write_png(file_name, WIDTH, HEIGHT, 1 ,temp, WIDTH);
    free(temp);
}

/*
* This function is to calculate a mean value of pixels in a WxW window
* Input: a 2D array of size WINDOW_SIZE X WINDOW_SIZE
* Output: mean value of that array
*/


double calculate_mean(unsigned char window[WINDOW_SIZE][WINDOW_SIZE]){
    double mean_val = 0.0;
    for(int i=0; i<WINDOW_SIZE; i++)
    {
        for(int j = 0; j<WINDOW_SIZE; j++)
        {
            mean_val = mean_val + window[i][j];
        }
    }
    return mean_val/(WINDOW_SIZE*WINDOW_SIZE);
}

void bubble_sort(unsigned char array[WINDOW_SIZE*WINDOW_SIZE]){
    int length = WINDOW_SIZE*WINDOW_SIZE;
    for(int i=0; i<length - 1; i++)
    {
        for(int j = i + 1; j<length; j++)
        {
            if(array[i] > array[j])
            {
                unsigned char temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void flatten(unsigned char window[WINDOW_SIZE][WINDOW_SIZE], unsigned char result[WINDOW_SIZE*WINDOW_SIZE]){
    for(int i=0; i<WINDOW_SIZE; i++)
    {
        for(int j=0; j<WINDOW_SIZE; j++)
        {
            result[i * WINDOW_SIZE + j] = window[i][j];
        }
    }
}

unsigned char calculate_median(unsigned char window[WINDOW_SIZE][WINDOW_SIZE]){
    unsigned char flatten_array[WINDOW_SIZE*WINDOW_SIZE];
    flatten(window, flatten_array);
    bubble_sort(flatten_array);

    int length = WINDOW_SIZE*WINDOW_SIZE;
    if(length % 2 == 1)
    {
        int index = (length + 1)/2;
        return flatten_array[index - 1];
    }
    else
    {
        int index = length/2;
        return (unsigned char)(flatten_array[index] + flatten_array[index - 1])/2;
    }

}
void mean_transfer(char* image_path)
{
    /* CREATE ARRAYS */
    unsigned char image_color[HEIGHT][WIDTH][CHANNEL];
    unsigned char image_gray[HEIGHT][WIDTH];
    unsigned char new_image[HEIGHT][WIDTH];

    unsigned char window[WINDOW_SIZE][WINDOW_SIZE];

    /* READ */
    read_color_image(image_color, image_path);

    /* CONVERT */
    convert_to_grayscale(image_color, image_gray);

    /* MEAN TRANS */

    int bound = (int) WINDOW_SIZE/2; //window size = 5 --> 2; 3 -->1
    for(int i = bound; i<HEIGHT - bound; i++)
    {
        for(int j=bound; j < WIDTH - bound; j++)
        {
            /* FOR EACH pxl i,j --> EXTRACT 1 WINDOW */
            for(int m = 0; m<WINDOW_SIZE; m++)
            {
                for(int n=0; n <WINDOW_SIZE; n++)
                {
                    window[m][n] = image_gray[i + m - bound][j + n - bound];
                }
            }
            /* CALCULATE MEAN */
            double mean_val = calculate_mean(window);

            new_image[i][j] = (unsigned char) mean_val;
        }
    }
    save_grayscale_image(new_image, "new_image_1.jpg");
}

void median_transfer(char* image_path)
{
    /* CREATE ARRAYS */
    unsigned char image_color[HEIGHT][WIDTH][CHANNEL];
    unsigned char image_gray[HEIGHT][WIDTH];
    unsigned char new_image[HEIGHT][WIDTH];

    unsigned char window[WINDOW_SIZE][WINDOW_SIZE];

    /* READ */
    read_color_image(image_color, image_path);

    /* CONVERT */
    convert_to_grayscale(image_color, image_gray);

    /* MEDIAN TRANS */

    int bound = (int) WINDOW_SIZE/2; //window size = 5 --> 2; 3 -->1
    for(int i = bound; i<HEIGHT - bound; i++)
    {
        for(int j=bound; j < WIDTH - bound; j++)
        {
            /* FOR EACH pxl i,j --> EXTRACT 1 WINDOW */
            for(int m = 0; m<WINDOW_SIZE; m++)
            {
                for(int n=0; n <WINDOW_SIZE; n++)
                {
                    window[m][n] = image_gray[i + m - bound][j + n - bound];
                }
            }
            /* CALCULATE MEAN */
            unsigned char median_val = calculate_median(window);

            new_image[i][j] = median_val;
        }
    }
    save_grayscale_image(new_image, "new_image_median.jpg");
}


int main()
{
    median_transfer("new_background.jpg");
}