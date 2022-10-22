/// @file BoW-BBoW.c
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/**
 * Create a new 1 dimensional array with the given size filled with 0
 * @param[in] _size the size of the array
 * @param[out] _ empty 1 dimensional array filled with 0
 */
int *i_arrayNew_1d(int _size)
{
    return (int *)calloc(_size, sizeof(int));
}

/**
 * Create a new 2-dimensional array with the given size filled with 0
 * @param[in] row number of rows
 * @param[in] col number of columns
 * @param[out] _ empty 2-dimensional array filled with 0
 */
char **c_array_new_2d(int row, int col)
{
    char **matrix = (char **)malloc(row * sizeof(char *));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (char *)malloc(col * sizeof(char));
    }
    return matrix;
}

/**
 * Customizedly print a 1-dimensional array
 * @param[in] array input array
 * @param[in] _size size of array
 * @param[in] header print this string before printing all the array
 * @param[in] preElement print this string before each of the element
 * @param[in] postElement print this string after each of the element
 * @param[in] footer print this string after printing all the array
 */
void i_arrayPrintCustomized_1d(int *array, int _size, char *header, char *preElement, char *postElement, char *footer)
{
    printf("%s", header);
    for (int i = 0; i < _size; i++)
    {
        printf("%s%d%s", preElement, array[i], postElement);
    }
    printf("%s", footer);
}

/**
 * Customizedly print a 1-dimensional array
 * @param[in] array input array
 * @param[in] header print this string before printing all the array
 * @param[in] preElement print this string before each of the element
 * @param[in] postElement print this string after each of the element
 * @param[in] footer print this string after printing all the array
 */
void c_arrayPrintCustomized_1d(char *str, char *header, char *preElement, char *postElement, char *footer)
{
    printf("%s", header);
    printf("%s%s%s", preElement, str, postElement);
    printf("%s", footer);
}

/**
 * Customizedly print a 1-dimensional array
 * @param[in] array input array
 * @param[in] _size size of array
 * @param[in] header print this string before printing all the array
 * @param[in] preElement print this string before each of the element
 * @param[in] postElement print this string after each of the element
 * @param[in] footer print this string after printing all the array
 */
void c_arrayPrintCustomized_2d(char **array, int _size, char *header, char *preElement, char *postElement, char *footer)
{
    printf("%s", header);
    for (int i = 0; i < _size; i++)
    {
        printf("%s%s%s", preElement, array[i], postElement);
    }
    printf("%s", footer);
}

/**
 * Get a set of unique elements of the input array
 * @param[in] matrix input array
 * @param[in] row number of words
 * @param[in] col maximum length of words
 * @param[in] res number of unique elements
 * @param[out] result a set of unique elements of the input array
 */
char **getVocabulary(char **matrix, int row, int col, int *res)
{
    *res = 0;
    char **result = c_array_new_2d(row, col);

    strcpy(result[(*res)++], "<OOV>");
    for (int i = 0; i < row; i++)
    {
        int j = 0;
        for (j = i + 1; j < row; j++)
        {
            if (strcmp(matrix[i], matrix[j]) == 0)
            {
                break;
            }
        }
        if (j == row)
        {
            strcpy(result[(*res)++], matrix[i]);
        }
    }
    return result;
}

/**
 * Get result of Bag of Words
 * @param[in] vocab array storing the unique words
 * @param[in] _size number of the unique words
 * @param[in] tokenized input array, want to find BoW on this array
 * @param[in] _size1 number of elements in the `tokenized` array
 * @param[out] BoW Bag of Words array
 */
int *BoW(char **vocab, int _size, char **tokenized, int _size1)
{
    int *BoW = i_arrayNew_1d(_size);

    int flag = 0;
    for (int i = 0; i < _size1; i++)
    {
        for (int j = 0; j < _size; j++)
        {
            if (strcmp(tokenized[i], vocab[j]) == 0)
            {
                BoW[j] += 1;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            BoW[0] += 1;
        }
        flag = 0;
    }
    return BoW;
}

/**
 * Get result of Binary Bag of Words
 * @param[in] vocab array storing the unique words
 * @param[in] _size number of the unique words
 * @param[in] tokenized input array, want to find BoW on this array
 * @param[in] _size1 number of elements in the `tokenized` array
 * @param[out] BBoW Binary Bag of Words array
 */
int *BBoW(char **vocab, int _size, char **tokenized, int _size1)
{
    int *bow = BoW(vocab, _size, tokenized, _size1);
    int *BBoW = i_arrayNew_1d(_size);

    for (int i = 0; i < _size; i++)
    {
        if (bow[i] == 0)
        {
            BBoW[i] = 0;
        }
        else
        {
            BBoW[i] = 1;
        }
    }
    return BBoW;
}

/**
 * Split a string into a list of separated words
 * @param[in] str the string to split
 * @param[in] seperator the separator to split words
 * @param[in] size number of words after splitted
 * @param[out] tokenizer list of separated words
 */
char **tokenizer(char *str, char *seperator, int *size)
{
    *size = 0;
    char *token = strtok(str, seperator);
    char **tokenizer = c_array_new_2d(100, 49);

    while (token != NULL)
    {
        tokenizer[(*size)++] = token;
        token = strtok(NULL, seperator);
    }
    return tokenizer;
}

/**
 * Remove all special characters and trailing space of the input string
 * @param[in] str the string to clean
 */
void clear_string(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (!(
                (int)str[i] == 32 ||
                ((int)str[i] >= 65 && (int)str[i] <= 90) ||
                ((int)str[i] >= 97 && (int)str[i] <= 122)))

        {
            for (int j = i; j < len; j++)
            {
                str[j] = str[j + 1];
            }
            len--;
            i--;
        }

        while (str[i] == ' ' && str[i + 1] == ' ')
        {
            for (int j = i; j < len; j++)
            {
                str[j] = str[j + 1];
            }
            len--;
            i--;
        }
    }
}

/**
 * Remove all space at beginning and at the end of the input string
 * @param[in] str the string to clean
 */
void strip(char *str)
{
    int len = strlen(str);
    while (str[len - 1] == ' ')
    {
        str[len - 1] = '\0';
        len--;
    }
    while (str[0] == ' ')
    {
        for (int i = 0; i < len; i++)
        {
            str[i] = str[i + 1];
        }
        len--;
    }
}

/**
 * Change all string to lower case
 * @param[in] str the string to clean
 */
char toLowercase(char *str)
{
    for (; *str; ++str)
    {
        *str = tolower(*str);
    }
}

/**
 * Main entry point of the program.
 */
int main()
{
    // declare and initialize variables
    char str[10000];
    char str0[] = {"vietnam machine learning deEp lEarning bOok learning neko"};
    char str1[] = {"   vietnam;[/>/]   machi.[/;/ne    learn.[;.ing deep learning book 123   learning |"};
    char str2[] = {"vietnam is not a book"};
    char str3[] = {"a book is a book"};
    char test_str[] = {"neko941 is from vietnam unD er es nEkO941 iS nOt learning a machine learning book."};
    char seperator[] = " ";

    // comcatenate main string
    strcat(str, str0);
    strcat(str, seperator);
    strcat(str, str1);
    strcat(str, seperator);
    strcat(str, str2);
    strcat(str, seperator);
    strcat(str, str3);
    c_arrayPrintCustomized_1d(str, "Concatenated main string: \n\t", "", " ", "\n");

    // test preprocessing
    clear_string(str);
    strip(str);
    toLowercase(str);
    c_arrayPrintCustomized_1d(str, "Cleaned main string: \n\t", "", " ", "\n");
    clear_string(test_str);
    strip(test_str);
    toLowercase(test_str);
    c_arrayPrintCustomized_1d(test_str, "Cleaned test string: \n\t", "", " ", "\n");

    // tokenizer
    int length = 0;
    char **tokenized = tokenizer(str, seperator, &length);
    c_arrayPrintCustomized_2d(tokenized, length, "Tokenized main string: \n\t", "", " ", "\n");

    int length1 = 0;
    char **tokenized1 = tokenizer(test_str, seperator, &length1);
    c_arrayPrintCustomized_2d(tokenized1, length1, "Tokenized test string: \n\t", "", " ", "\n");

    // get vocabulary
    int vocab_size;
    char **vocab = getVocabulary(tokenized, length, 49, &vocab_size);
    c_arrayPrintCustomized_2d(vocab, ++vocab_size, "Vocabulary: \n\t", "", " ", "\n");

    // Bag of Words
    int *bow = BoW(vocab, vocab_size, tokenized1, length1);
    i_arrayPrintCustomized_1d(bow, vocab_size, "Bag of Word: \n\t", "", "\t", "\n");

    // Binary Bag of Words
    int *bbow = BBoW(vocab, vocab_size, tokenized1, length1);
    i_arrayPrintCustomized_1d(bbow, vocab_size, "Binary Bag of Word: \n\t", "", "\t", "\n");
}
