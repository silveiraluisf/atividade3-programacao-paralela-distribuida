#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define BUFFER_SIZE 1000

/* declaração da funcao */
int countOccurrences(FILE *fptr, const char *word);


int main()
{
    FILE *fptr = fopen("livro/teste.txt", "rb");;
    char path[100];

    char word[50];

    int wCount;

    /* Input da palavra a ser procurada */
    printf("Enter word to search in file: ");
    scanf("%s", word);

    struct timeval t1, t2;

    gettimeofday(&t1, NULL);

    /* Tratamento de excessao, caso nao cosiga ler o arquivo */
    if (fptr == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check you have read/write previleges.\n");

        exit(EXIT_FAILURE);
    }

    // chama a função para contar o numero de ocorrencias da palavra
    wCount = countOccurrences(fptr, word);

    printf("'%s' is found %d times in file.\n", word, wCount);

    fclose(fptr);

    // equacao para determinaro tempo de execucao do programa

    gettimeofday(&t2, NULL);

    double t_total = (t2.tv_sec - t1.tv_sec) + ((t2.tv_usec - t1.tv_usec)/1000000.0);

    printf(" tempo total = %f\n" , t_total);

    return 0;
}


/*retorna o total de ocorrencias de uma determinada palavra em um arquivo */

int countOccurrences(FILE *fptr, const char *word)
{
    char str[BUFFER_SIZE];
    char *pos;

    int index, count;
    
    count = 0;

    // le as linhas do arquivo ate o final dele
    while ((fgets(str, BUFFER_SIZE, fptr)) != NULL)
    {
        index = 0;

        // encontra a proxima ocorrencia da palavra em str
        while ((pos = strstr(str + index, word)) != NULL)
        {
            index = (pos - str) + 1;
            count++;
        }
    }

    return count;
}