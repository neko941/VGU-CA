#ifndef __GRAYSCALE_H__
#define __GRAYSCALE_H__

#include <math.h>
#include <time.h>
#include "./array.h"
#include "./color.h"
#include "./print.h"

double sRGB_to_linear(double x)
{
    if (x < 0.04045)
        return x / 12.92;
    return pow((x + 0.055) / 1.055, 2.4);
}

double linear_to_sRGB(double y)
{
    if (y <= 0.0031308)
        return 12.92 * y;
    return 1.055 * pow(y, 1 / 2.4) - 0.055;
}

unsigned char *uc_grayscaleGammaCompression_1d(unsigned char *color_image, int width, int height, int channel)
{
    int t = clock();
    puts("******************** Converting to grayscale using Gamma Compression");
    unsigned char *gray_image = uc_arrayNew_1d(width * height);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double gray_linear = 0.2126 * sRGB_to_linear(color_image[i * width * channel + j * channel + 0] / 255.0) +
                                 0.7152 * sRGB_to_linear(color_image[i * width * channel + j * channel + 1] / 255.0) +
                                 0.0722 * sRGB_to_linear(color_image[i * width * channel + j * channel + 2] / 255.0);
            gray_image[i * width + j] = (unsigned char)round(linear_to_sRGB(gray_linear) * 255);
            progressingBar((i * width + j) / (double)(height * width - 1), ((double)clock() - t) / CLOCKS_PER_SEC);
        }
    }
    green();
    printf("\n******************** Converting to grayscale successfully\n\n");
    reset();

    return gray_image;
}

#endif