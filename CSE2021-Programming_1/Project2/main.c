#include <stdio.h>
#include <stdbool.h>

#include "./include/utils.h"
#include "./include/os.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "./include/stb_image_write.h"

int main()
{
    // get all image paths
    int numFiles = 0;
    char *dataDir = "./images/data";
    char **allFiles = listAllFiles(dataDir, &numFiles);

    // read template
    char *templatePath = "images/template.jpg";
    int widthTemplate, heightTemplate, channelTemplate;
    unsigned char *template = readImage(templatePath, &widthTemplate, &heightTemplate, &channelTemplate, 0);

    int width, height, channel;
    int widthInterval = 1;
    int heightInterval = 1;

    char *saveDir = "result";
    makeDir(saveDir);

    char *saveTemplateDir = "template";
    makeDir(saveTemplateDir);

    char *imagePath;
    char *outputImagePath;
    char *templateImagePath;

    for (int i = 0; i < numFiles; i++)
    {
        imagePath = pathJoin(dataDir, allFiles[i]);
        unsigned char *image = readImage(imagePath, &width, &height, &channel, 0);
        template = templateMatching(image, width, height, channel, template, widthTemplate, heightTemplate, widthInterval, heightInterval, false);

        outputImagePath = pathJoin(saveDir, stringReplace(allFiles[i], "img", saveDir));
        printf("Save to: %s\n", outputImagePath);
        stbi_write_jpg(outputImagePath, width, height, channel, image, width * channel);
        templateImagePath = pathJoin(saveTemplateDir, stringReplace(allFiles[i], "img", saveTemplateDir));
        printf("Save to: %s\n", templateImagePath);
        stbi_write_jpg(templateImagePath, widthTemplate, heightTemplate, channelTemplate, template, widthTemplate * channelTemplate);

        free(image);
        puts("\n\n\n");
    }

    // call python to convert to gif
    char *command = c_arrayNew_1d(55 + strlen(saveDir) + strlen(saveTemplateDir));
    sprintf(command, "python .\\Imges2Gif.py -i %s & python .\\Imges2Gif.py -i %s", saveDir, saveTemplateDir);
    printf("Using commad: %s\n", command);
    system(command);
    free(command);

    // free memories
    free(dataDir);
    for (int i = 0; i < numFiles; i++)
    {
        free(allFiles[i]);
    }
    free(allFiles);
    free(templatePath);
    free(template);
    free(saveDir);
    free(saveTemplateDir);
    free(imagePath);
    free(outputImagePath);
    free(templateImagePath);
}