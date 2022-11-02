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

/*==================================Given Codes===================================================*/


/*==================================Your Codes Here===============================================*/

//Document: https://drive.google.com/file/d/17YtjwGxWBsBHsnLXfWFiEgnRnYMtaHKg/view?usp=sharing

/*
* This function is to convert a foreground image with a given background to a new one with fake background.
* Input: 3 paths-to-images, one is a background img, one is foreground and one is a fake background
* Output: Substracted background grayscale image, mask image, segmented image, foreground with fake background image.
*/

void background_subtract(char* background_path, char* foreground_path, char* fake_background_path){

    /* CREATE ARRAYS TO STORE IMAGES */
    unsigned char background[HEIGHT][WIDTH][CHANNEL];
    unsigned char foreground[HEIGHT][WIDTH][CHANNEL];
    unsigned char fake_background[HEIGHT][WIDTH][CHANNEL];

    /* CREATE SUBTRACTED ARRAYS */
    unsigned char subtracted_color[HEIGHT][WIDTH][CHANNEL];
    unsigned char subtracted_gray[HEIGHT][WIDTH];

    /* CREATE MASK */
    unsigned char mask[HEIGHT][WIDTH];

    /* CREATE SEGMENTED IMAGE */
    unsigned char segmented_image[HEIGHT][WIDTH][CHANNEL];

    /* OUTPUT */
    unsigned char new_image[HEIGHT][WIDTH][CHANNEL];

    /* READ IMAGES */
    read_color_image(background, background_path);
    read_color_image(foreground, foreground_path);
    read_color_image(fake_background, fake_background_path);

    /* SUBTRACT IMGS */
    for(int i=0; i<HEIGHT; i++)
    {
        for(int j=0; j<WIDTH; j++)
        {
            for(int k =0; k<CHANNEL; k++)
            {
                subtracted_color[i][j][k] = abs(foreground[i][j][k] - background[i][j][k]);
            }
        }
    }
    save_color_image(subtracted_color, "subtracted_color.jpg");

    /* CONVERT TO GRAYSCALE */
    convert_to_grayscale(subtracted_color, subtracted_gray);
    save_grayscale_image(subtracted_gray, "subtracted_gray.jpg");

    /* CREATE MASK */
    unsigned char threshold = 30;
    for(int i=0; i<HEIGHT; i++)
    {
        for(int j=0; j<WIDTH; j++)
        {
            mask[i][j] = (subtracted_gray[i][j] < threshold) ? 0:255;
        }
    }    
    save_grayscale_image(mask, "mask.jpg");

    /* CREATE SEGMENTED Image */
    for(int i=0; i<HEIGHT; i++)
    {
        for(int j=0; j<WIDTH; j++)
        {
            for(int k=0; k<CHANNEL; k++)
            {
                segmented_image[i][j][k] = (mask[i][j]/255)*foreground[i][j][k];
                //segmented_image[i][j][k] = (mask[i][j] == 0) ? 0:foreground[i][j][k];
            }
        }
    }
    save_color_image(segmented_image, "segmented_image.jpg");

    /* COMBINE */

    for(int i=0; i<HEIGHT; i++)
    {
        for(int j=0; j<WIDTH; j++)
        {
            for(int k=0; k<CHANNEL; k++)
            {
                //new_image[i][j][k] = (mask[i][j] == 0) ? fake_background[i][j][k] : segmented_image[i][j][k];
                new_image[i][j][k] = ((255 - mask[i][j])/255)*fake_background[i][j][k] + segmented_image[i][j][k];
            }
        }
    }
    save_color_image(new_image, "new_image_2.jpg");
}

int main()
{
    background_subtract("background.jpg", "foreground.jpg", "new_background.jpg");
}




