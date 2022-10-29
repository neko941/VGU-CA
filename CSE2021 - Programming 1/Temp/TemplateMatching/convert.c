#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"


void conversion(char* original, char* output)
{
	int height, width, channel;
    unsigned char* temp = stbi_load(original, &width , &height , &channel, 0);
    if(temp == NULL)
    {
    	puts("Unable to load image.");
    	exit(1);
    }
    unsigned char* out = (unsigned char*) malloc(width*height*3);
    for(int i=0; i<height; i++)
    {
    	for(int j=0; j<width; j++)
    	{
    		for(int k=0; k<3; k++)
    		{
    			out[i*width*3 + j*3 + k] = temp[i*width*channel + j*channel + k];
    		}
    	}
    }
    stbi_write_png(output, width, height, 3, out, width*3);

   	stbi_image_free(temp);  
    free(out); 
}
int main()
{
	char original[100];
	char output[100];
	printf("Name of original image: \n");
	scanf("%99s", original);
	printf("Name of output image: \n");
	scanf("%99s", output);
	conversion(original, output);

}
