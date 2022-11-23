#ifndef __SIMILARITY_H__
#define __SIMILARITY_H__

#include <math.h>

double cosineSimilarity(unsigned char *_crop, unsigned char *_template, int width, int height, int channel)
{
    long long int length = width * height * channel;
    double numerator = 0.0;
    double denomeratorCrop = 0.0;
    double denomeratorTemplate = 0.0;

    for (long long int i = 0; i < length; i++)
    {
        numerator += _crop[i] * _template[i];
        denomeratorCrop += _crop[i] * _crop[i];
        denomeratorTemplate += _template[i] * _template[i];
    }

    return numerator / (sqrt(denomeratorCrop) * sqrt(denomeratorTemplate));
}

double correlationCoefficient(unsigned char *_crop, unsigned char *_template, int width, int height, int channel)
{
    int length = width * height * channel;
    long long int sumCrop = 0, sumTemplate = 0, sumBoth = 0, sqCrop = 0, sqTemplate = 0;
    double correlation;

    for (int i = 0; i < length; i++)
    {
        sumCrop += _crop[i];
        sumTemplate += _template[i];
        sumBoth += _crop[i] * _template[i];
        sqCrop += pow(_crop[i], 2);
        sqTemplate += pow(_template[i], 2);
    }
    correlation = (length * sumBoth - sumCrop * sumTemplate) / (sqrt(length * sqCrop - pow(sumCrop, 2)) * sqrt(length * sqTemplate - pow(sumTemplate, 2)));
    return correlation;
}

#endif