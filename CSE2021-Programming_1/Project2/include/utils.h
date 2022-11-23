#ifndef __UTILS_H__
#define __UTILS_H__

#include <time.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

#include <stdbool.h>

#define STB_IMAGE_IMPLEMENTATION
#include "./stb_image.h"

#include "./color.h"
#include "./similarity.h"
#include "./array.h"
#include "./print.h"
#include "./grayscale.h"
#include "./stringplus.h"

void drawBoundingBox(unsigned char *image, int widthBoundingBox, int heightBoundingBox, int widthOfOriginalImage, int channel, int x, int y, int *color)
{
    for (int i = 0; i < widthBoundingBox; i++)
    {
        for (int j = 0; j < channel; j++)
        {
            image[y * widthOfOriginalImage * channel + (x + i) * channel + j] = color[j];
            image[(y + heightBoundingBox) * widthOfOriginalImage * channel + (x + i) * channel + j] = color[j];
        }
    }
    for (int i = 0; i < heightBoundingBox; i++)
    {
        for (int j = 0; j < channel; j++)
        {
            image[(y + i) * widthOfOriginalImage * channel + x * channel + j] = color[j];
            image[(y + i) * widthOfOriginalImage * channel + (x + widthBoundingBox) * channel + j] = color[j];
        }
    }
}

unsigned char *copyImage(unsigned char *src, int length)
{
    unsigned char *des = uc_arrayNew_1d(length);
    for (int i = 0; i < length; i++)
    {
        des[i] = src[i];
    }
    return des;
}

unsigned char *templateMatching(unsigned char *_image, int width, int height, int channel, unsigned char *_template, int widthTemplate, int heightTemplate, int widthInterval, int heightInterval, bool greyscale)
{
    unsigned char *_imageTemp;
    int channelTemp;
    if (greyscale)
    {
        _imageTemp = uc_grayscaleGammaCompression_1d(_image, width, height, channel);
        _template = uc_grayscaleGammaCompression_1d(_template, widthTemplate, heightTemplate, channel);
        channelTemp = 1;
    }
    else
    {
        _imageTemp = copyImage(_image, width * height * channel);
        channelTemp = channel;
    }

    if (!(widthInterval > 0) || !(heightInterval > 0))
    {
        error("Interval must be greater than zero");
    }
    double percentage = 0.0;
    int newHeight = height - heightTemplate + 1;
    int newWidth = width - widthTemplate + 1;
    double **result = d_arrayNew_2d(newHeight, newWidth);
    unsigned char *window = uc_arrayNew_1d(widthTemplate * heightTemplate * channelTemp);

    puts("******************** Window slicing and calculate cosine similarity");
    int t = clock();
    double numberHeightUsed = (double)newHeight / (double)heightInterval;
    double numberWidthUsed = (double)newWidth / (double)widthInterval;
    double totalOfInteration = numberHeightUsed * numberWidthUsed - 1;
    for (int i = 0; i < newHeight; i += heightInterval)
    {
        for (int j = 0; j < newWidth; j += widthInterval)
        {
            for (int innerI = 0; innerI < heightTemplate; innerI++)
            {
                for (int innerJ = 0; innerJ < widthTemplate; innerJ++)
                {
                    for (int k = 0; k < channelTemp; k++)
                    {
                        window[innerI * widthTemplate * channelTemp + innerJ * channelTemp + k] = _imageTemp[(innerI + i) * width * channelTemp + (innerJ + j) * channelTemp + k];
                    }
                }
            }
            result[i][j] = cosineSimilarity(window, _template, widthTemplate, heightTemplate, channelTemp);
            // progressingBar((i * newWidth + j) / (newHeight * newWidth - 1), ((double)clock() - t) / CLOCKS_PER_SEC);
            percentage = (((double)i / (double)heightInterval) * numberWidthUsed + ((double)j / (double)widthInterval)) / totalOfInteration;
            percentage = (percentage > 1.0) ? 1.0 : percentage;
            progressingBar(percentage, ((double)clock() - t) / CLOCKS_PER_SEC);
        }
    }
    puts("");
    success("******************** Done window slicing and calculate cosine similarity");

    puts("******************** Searching max result");
    int x = 0;
    int y = 0;
    double max = d_arrayMaxWidthIndeces_2d(result, newHeight, newWidth, &x, &y);
    char *_m = c_arrayNew_1d(100);
    sprintf(_m, "******************** Found the template at x=%d y=%d max=%f", x, y, max);
    success(_m);
    free(_m);

    puts("******************** Getting new template");
    unsigned char *newTemplate = uc_arrayNew_1d(widthTemplate * heightTemplate * channel);
    for (int innerI = 0; innerI < heightTemplate; innerI++)
    {
        for (int innerJ = 0; innerJ < widthTemplate; innerJ++)
        {
            for (int k = 0; k < channel; k++)
            {
                newTemplate[innerI * widthTemplate * channel + innerJ * channel + k] = _image[(innerI + y) * width * channel + (innerJ + x) * channel + k];
            }
        }
    }
    success("******************** Done");

    puts("******************** Draw bounding box");
    int color[] = {0, 255, 0};
    drawBoundingBox(_image, widthTemplate, heightTemplate, width, channel, x, y, color);
    success("******************** Done");

    return newTemplate;
}

// =============================================================================================================

int lengthOfInt(int value)
{
    // char str[ENOUGH];
    // sprintf(str, "%d", value);
    // return strlen(str);
    return (int)((ceil(log10(value)) + 1) * sizeof(char)) - 1;
}

unsigned char *readImage(char const *filename, int *x, int *y, int *comp, int req_comp)
{
    unsigned char *image = stbi_load(filename, x, y, comp, req_comp);
    if (image == NULL)
    {
        red();
        puts("Error in loading the image");
        reset();
        exit(1);
    }
    else
    {
        green();
        puts("******************** Reading image successfully");
        int length_path = 12 + strlen(filename) + 1;
        char *result_path = c_arrayNew_1d(length_path);
        sprintf(result_path, "Image Path: %s", filename);

        int length_width = 7 + lengthOfInt(*x) + 1;
        char *result_width = c_arrayNew_1d(length_width);
        sprintf(result_width, "Width: %d", *x);

        int length_height = 8 + lengthOfInt(*y) + 1;
        char *result_height = c_arrayNew_1d(length_height);
        sprintf(result_height, "Height: %d", *y);

        int length_channel = 9 + lengthOfInt(*comp) + 1;
        char *result_channel = c_arrayNew_1d(length_channel);
        sprintf(result_channel, "Channel: %d", *comp);

        cyan();
        printf("%c", 218);
        printTrailings(strlen(result_path) + 2, 196);
        printf("%c\n", 191);

        printf("%c %s %c\n", 179, result_path, 179);
        printf("%c %s", 179, result_width);
        printTrailings(strlen(result_path) - strlen(result_width) + 1, 32);
        printf("%c\n", 179);

        printf("%c %s", 179, result_height);
        printTrailings(strlen(result_path) - strlen(result_height) + 1, 32);
        printf("%c\n", 179);

        printf("%c %s", 179, result_channel);
        printTrailings(strlen(result_path) - strlen(result_channel) + 1, 32);
        printf("%c\n", 179);

        printf("%c", 192);
        printTrailings(strlen(result_path) + 2, 196);
        printf("%c\n\n", 217);

        reset();
        return image;
    }
}

// =============================================================================================================

/* create a GIF */
// #include "./include/gifenc.c"
// ge_GIF *gif = ge_new_gif(
//     "result.gif", /* file name */
//     640, 480,     /* canvas size */
//     (uint8_t[]){
//         /* palette */
//         0x00, 0x00, 0x00, /* 0 -> black */
//         0xFF, 0x00, 0x00, /* 1 -> red */
//         0x00, 0xFF, 0x00, /* 2 -> green */
//         0x00, 0x00, 0xFF, /* 3 -> blue */
//     },
//     2,  /* palette depth == log2(# of colors) */
//     -1, /* no transparency */
//     0   /* infinite loop */
// );
// char **allResultFiles = listAllFiles(saveDir, &numFiles);
// for (int i = 0; i < numFiles; i++)
// {
//     imagePath = pathJoin(dataDir, allFiles[i]);
//     unsigned char *image = readImage(imagePath, &width, &height, &channel, 0);
//     for (int i = 0; i < width * height * channel; i++)
//     {
//         gif->frame[i] = image[i];
//     }
//     ge_add_frame(gif, 10);
// }
// ge_close_gif(gif);

#endif