#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void readFiles(char *fileName, char *lines, int *n){
    FILE *fptr = fopen(fileName, "r");
    int length = 100000;
    char line[length];
    if(fptr==NULL){
        printf("Error!! Cannot open file.");
        exit(1);
    }
    printf("Content of \"%s\":\n", fileName);
    while(fgets(line, length-1, fptr)!=NULL){
        printf("%s", line);
        for(size_t i=0; line[i]!='\0'; i++){
            if(line[i]==' '){
                for(size_t j=i; line[j]!='\0'; j++)
                    line[j] = line[j+1];
            }
            if(line[i]=='\n')
                line[i] = ',';

            if(line[i]==',')
                *n = *n + 1;
        }
        strcat(lines, line);
    }
    puts("");
}

void bow(char *lines, int n){
    int i = 0, length = 100000;
    int *count = (int*)calloc(n, sizeof(int));

    char **vocab = (char**)malloc(sizeof(char*) * n);
    for(int j=0; j<n; j++)
        *vocab = (char*)malloc(length);

    char *token = strtok(lines, ",");
    token[0] = toupper(token[0]);
    *(vocab+i) = token;
    *(count+i) = *(count+i) + 1;
    i = i + 1;

    while(1){
        token = strtok(NULL, ",");
        if(token==NULL)
            break;
        token[0] = toupper(token[0]);
        for(int j=0; j<i; j++){
            if(!strcmp(*(vocab+j), token)){
                *(count+j) = *(count+j) + 1;
                break;
            }
            if(j==i-1){
                *(vocab+i) = token;
                *(count+i) = *(count+i) + 1;
                i = i + 1;
                break;
            }
        }
    }

    for(int j=0; j<i; j++){
        printf("%s: %d\n", *(vocab+j), *(count+j));
    }
}


int main()
{
    int n = 2, length = 100000, m = 0;
    char *names[] = {"bp1.txt", "bp2.txt"};
    char lines[length];
    for(int i=0; i<n; i++){
        readFiles(names[i], lines, &m);
    }
    bow(lines, m);
    return 0;
}
