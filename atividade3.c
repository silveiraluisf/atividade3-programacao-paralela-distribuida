#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define BUFFER_SIZE 1000

/* declaração da funcao */
int countOccurrences(FILE *fptr, const char *word);


int main()
{
    FILE *fptr;
    char path[100];

    char word[50];

    int wCount;

    /* Input file path */
    printf("Enter file path: ");
    scanf("%s", path);

    /* Input word to search in file */
    printf("Enter word to search in file: ");
    scanf("%s", word);

    /* Try to open file */
    fptr = fopen(path, "r");

    struct timeval t1, t2;

    gettimeofday(&t1, NULL);

    /* Exit if file not opened successfully */
    if (fptr == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check you have read/write previleges.\n");

        exit(EXIT_FAILURE);
    }

    // Call function to count all occurrence of word
    wCount = countOccurrences(fptr, word);

    printf("'%s' is found %d times in file.\n", word, wCount);


    // Close file
    fclose(fptr);

    gettimeofday(&t2, NULL);

    double t_total = (t2.tv_sec - t1.tv_sec) + ((t2.tv_usec - t1.tv_usec)/1000000.0);

    printf(" tempo total = %f\n" , t_total);

    return 0;
}


/**
 * Returns total occurrences of a word in given file.
 */
int countOccurrences(FILE *fptr, const char *word)
{
    char str[BUFFER_SIZE];
    char *pos;

    int index, count;
    
    count = 0;

    // Read line from file till end of file.
    while ((fgets(str, BUFFER_SIZE, fptr)) != NULL)
    {
        index = 0;

        // Find next occurrence of word in str
        while ((pos = strstr(str + index, word)) != NULL)
        {
            // Index of word in str is
            // Memory address of pos - memory
            // address of str.
            index = (pos - str) + 1;

            count++;
        }
    }

    return count;
}