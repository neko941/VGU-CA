#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

// global parameters
const int HEIGHT = 160;
const int WIDTH = 200;
const int CHANNEL = 3;

const int HEIGHT_2 = 30;
const int WIDTH_2 = 37;
const int CHANNEL_2 = 3;


long int SAD(unsigned char x[HEIGHT_2][WIDTH_2][CHANNEL_2], unsigned char y[HEIGHT_2][WIDTH_2][CHANNEL_2])
{
    long int sad_val = 0;
    for(int i=0; i<HEIGHT_2; i++)
    {
        for(int j=0; j<WIDTH_2; j++)
        {
            for(int k=0; k<CHANNEL_2; k++)
            {
                sad_val += abs(x[i][j][k] - y[i][j][k]);
            }
        }
    }
    return sad_val;
}

double correlation_x_y(unsigned char x[HEIGHT_2][WIDTH_2][CHANNEL_2], unsigned char y[HEIGHT_2][WIDTH_2][CHANNEL_2])
{
    long int sum_xi_yi = 0;
    long int sum_xi = 0;
    long int sum_yi = 0;
    long int sum_xi_2 = 0;
    long int sum_yi_2 = 0;
    int length = HEIGHT_2*WIDTH_2*CHANNEL_2;

    for(int i=0; i<HEIGHT_2;i++)
    {
        for(int j=0; j<WIDTH_2; j++)
        {
            for(int k = 0; k<CHANNEL_2; k++)
            {
                sum_xi_yi+=  x[i][j][k]*y[i][j][k];
                sum_xi+= x[i][j][k];
                sum_yi+= y[i][j][k];
                sum_xi_2 += x[i][j][k]*x[i][j][k];
                sum_yi_2 += y[i][j][k]*y[i][j][k];
            }
        }
    }
    long int nominator = length*sum_xi_yi - sum_xi*sum_yi;
    double denominator_1 = sqrt(length*sum_xi_2 - sum_xi*sum_xi);
    double denominator_2 = sqrt(length*sum_yi_2 - sum_yi*sum_yi);
    double result = (double) nominator/(denominator_1*denominator_2);

    return result;
}
void read_second_color_image(unsigned char color_image_no_2[HEIGHT_2][WIDTH_2][CHANNEL_2], char* file_name)
{
    int height, width, channel;
    unsigned char* temp = stbi_load(file_name, &width , &height , &channel, 0);
    if(temp == NULL)
    {
        printf("Unable to load image.\n");
        exit(1);
    }
    for(int i=0; i<HEIGHT_2;i++)
    {
        for(int j=0; j<WIDTH_2;j++)
        {
            for(int k=0; k <CHANNEL_2;k++)
            {
                color_image_no_2[i][j][k] = temp[i*WIDTH_2*CHANNEL_2 + j*CHANNEL_2 + k];
            }
        } 
    }
    stbi_image_free(temp);    

}
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
void template_matching_CORR(unsigned char image[HEIGHT][WIDTH][CHANNEL], unsigned char template[HEIGHT_2][WIDTH_2][CHANNEL_2], double corr_mtx[HEIGHT][WIDTH])
{
    //init correlation matrix
    for(int i=0; i<HEIGHT;i++)
    {
        for(int j=0; j<WIDTH;j++)
        {
            corr_mtx[i][j] = 0.0;
        }
    }
    unsigned char sample[HEIGHT_2][WIDTH_2][CHANNEL_2];
    for(int i=0; i<HEIGHT - HEIGHT_2; i++)
    {
        for(int j=0;j<WIDTH - WIDTH_2; j++)
        {
            //define correlation value
            double corr_val;


            //crop samples from image
            for(int m=0; m < HEIGHT_2; m++)
            {
                for(int n=0; n < WIDTH_2; n++)
                {
                    for(int k=0; k< CHANNEL_2; k++)
                    {
                        sample[m][n][k] = image[i+m][j+n][k];
                    }
                }
            }

            corr_val = correlation_x_y(sample, template);
            corr_mtx[i][j] = corr_val;
        }
    }
}


void template_matching_SAD(unsigned char image[HEIGHT][WIDTH][CHANNEL], unsigned char template[HEIGHT_2][WIDTH_2][CHANNEL_2], long int sad_mtx[HEIGHT][WIDTH])
{
    //init correlation matrix
    for(int i=0; i<HEIGHT;i++)
    {
        for(int j=0; j<WIDTH;j++)
        {
            sad_mtx[i][j] = INT_MAX;
        }
    }
    unsigned char sample[HEIGHT_2][WIDTH_2][CHANNEL_2];
    for(int i=0; i<HEIGHT - HEIGHT_2; i++)
    {
        for(int j=0;j<WIDTH - WIDTH_2; j++)
        {
            //define correlation value
            long int sad_val;


            //crop samples from image
            for(int m=0; m < HEIGHT_2; m++)
            {
                for(int n=0; n < WIDTH_2; n++)
                {
                    for(int k=0; k< CHANNEL_2; k++)
                    {
                        sample[m][n][k] = image[i+m][j+n][k];
                    }
                }
            }

            sad_val = SAD(sample, template);
            sad_mtx[i][j] = sad_val;
        }
    }
}


void get_position_CORR(double corr_mtx[HEIGHT][WIDTH], int* i_pos, int* j_pos)
{
    double max_val = 0.0;
    for(int i=0; i<HEIGHT; i++)
    {
        for(int j=0; j<WIDTH; j++)
        {
            if(corr_mtx[i][j] > max_val)
            {
                max_val = corr_mtx[i][j];
                *i_pos = i;
                *j_pos = j;
            }
        }
    }
}

void get_position_SAD(long int sad_mtx[HEIGHT][WIDTH], int* i_pos, int* j_pos)
{
    long int min_val = INT_MAX;
    for(int i=0; i<HEIGHT; i++)
    {
        for(int j=0; j<WIDTH; j++)
        {
            if(sad_mtx[i][j] < min_val)
            {
                min_val = sad_mtx[i][j];
                *i_pos = i;
                *j_pos = j;
            }
        }
    }
}

void draw_bounding_box(unsigned char output[HEIGHT][WIDTH][CHANNEL], int i_pos, int j_pos)
{
    for(int i=0; i<HEIGHT_2; i++)
    {
        output[i_pos + i][j_pos][0] = 0;
        output[i_pos + i][j_pos][1] = 0;
        output[i_pos + i][j_pos][2] = 0;

        output[i_pos + i][j_pos+ WIDTH_2][0] = 0;
        output[i_pos + i][j_pos + WIDTH_2][1] = 0;
        output[i_pos + i][j_pos + WIDTH_2][2] = 0;
    }

    for(int i=0; i<WIDTH_2; i++)
    {
        output[i_pos][j_pos + i][0] = 0;
        output[i_pos][j_pos + i][1] = 0;
        output[i_pos][j_pos + i][2] = 0;

        output[i_pos + HEIGHT_2][j_pos+ i][0] = 0;
        output[i_pos + HEIGHT_2][j_pos + i][1] = 0;
        output[i_pos + HEIGHT_2][j_pos + i][2] = 0;
    }    
}

void copy_image(unsigned char src[HEIGHT][WIDTH][CHANNEL], unsigned char des[HEIGHT][WIDTH][CHANNEL])
{
    for(int i=0; i<HEIGHT;i++)
    {
        for(int j=0; j<WIDTH; j++)
        {
            for(int k = 0; k<CHANNEL;k++)
            {
                des[i][j][k] = src[i][j][k];
            }
        }
    }
}
int main()
{
    unsigned char image[HEIGHT][WIDTH][CHANNEL];
    unsigned char template[HEIGHT_2][WIDTH_2][CHANNEL_2];
    unsigned char output_corr[HEIGHT][WIDTH][CHANNEL];
    unsigned char output_sad[HEIGHT][WIDTH][CHANNEL];    
    double corr_mtx[HEIGHT][WIDTH];
    long int sad_mtx[HEIGHT][WIDTH];

    read_color_image(image, "image4.jpg");
    read_second_color_image(template, "template.jpg");
    copy_image(image, output_corr);
    copy_image(image, output_sad);
    template_matching_CORR(image, template, corr_mtx);
    template_matching_SAD(image, template, sad_mtx);
    
    int ipos_corr;
    int jpos_corr;
    int ipos_sad;
    int jpos_sad;
    get_position_CORR(corr_mtx, &ipos_corr, &jpos_corr);
    get_position_SAD(sad_mtx, &ipos_sad, &jpos_sad);
    draw_bounding_box(output_corr, ipos_corr, jpos_corr);
    draw_bounding_box(output_sad, ipos_sad, jpos_sad);
    save_color_image(output_corr, "output_corr.jpg");
    save_color_image(output_sad, "output_sad.jpg");
}