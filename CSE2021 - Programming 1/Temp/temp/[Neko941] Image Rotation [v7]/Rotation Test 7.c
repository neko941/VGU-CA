#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "./header/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "./header/stb_image_write.h"

int width, height, channels;
unsigned int img_size;
unsigned char *img;
unsigned char *tary;

void load_image(){
    img = stbi_load("Cover.jpg", &width, &height, &channels, 0);
    if(img == NULL) {
        printf("\nError in loading the image\n");
        exit(1);
    }
    printf("\nWidth of %d, a height of %d and %d channels\n", width, height, channels);
    img_size = width * height * channels;
}

void image_rotation(int degree){
    int background = 0;
    float rads = degree*M_PI / 180.0;
    float cs = cos(-rads);
    float ss = sin(-rads);
    float xcenter = (float)(width)/2.0;
    float ycenter = (float)(height)/2.0;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int k=0; k < channels; k++){
                int rorig = ycenter + ((float)(i)-ycenter)*cs - ((float)(j)-xcenter)*ss;
                int corig = xcenter + ((float)(i)-ycenter)*ss + ((float)(j)-xcenter)*cs;
                int pixel = background;
                if (rorig >= 0 && rorig < height && corig >= 0 && corig < width) {
                    pixel = img[rorig*width*channels+corig*channels+k];
                }
                tary[i * width * channels + j * channels + k] = pixel;
            }
        }
    }
    char *result_patch = (char*)malloc(100 * sizeof(char));
    sprintf(result_patch, "./result/Image Rotation Test Result (%d).jpg", degree);
    stbi_write_png(result_patch, width, height, channels, tary, width*channels);
}

int main()
{
    printf("~~~~~~~~~~~~~~~~~~~~WELCOME~~~~~~~~~~~~~~~~~~~~");


    // read image
    load_image();


    tary = malloc(img_size);

    for (int i = 1; i < 361; i++){
        image_rotation(i);
    }
    printf("\nPlease check the folder that includes this code.");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        // save image


    stbi_image_free(img);
    stbi_image_free(tary);
}
