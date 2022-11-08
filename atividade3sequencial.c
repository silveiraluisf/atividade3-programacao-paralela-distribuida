#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define BUFFER_SIZE 1000

/* declaração da funcao */
int countOccurrences(char *word);

int num_words = 30;
int qtd_word[30];
char keywords[50][100] = {"death", "day", "night", "fear", "sea", "whale", "ship", "joy",
                          "king", "dispair", "tomorrow", "yesterday", "time", "home", "love", "snake", "man",
                          "woman", "god", "tired", "me", "life", "rose", "book", "danger",
                          "wind", "world", "flower", "star", "end", };

int main()
{

    struct timeval t1, t2;

    gettimeofday(&t1, NULL);

    /* chama a função para contar o numero de ocorrencias da palavra */
        for (int i = 0; i < num_words; i++)
            qtd_word[i] = countOccurrences(keywords[i]);

        for (int j = 0; j < num_words; j++)
            printf("Palavra: %s | Numero de vezes = %d.\n\n", keywords[j], qtd_word[j]);

    /* equacao para determinaro tempo de execucao do programa */

    gettimeofday(&t2, NULL);

    double t_total = (t2.tv_sec - t1.tv_sec) + ((t2.tv_usec - t1.tv_usec)/1000000.0);

    printf("Tempo total de execucao = %f\n" , t_total);

    return 0;
}

/*retorna o total de ocorrencias de uma determinada palavra em um arquivo */

int countOccurrences(char *word)
{
    FILE *fptr = fopen("livro/mobdick.txt", "rb");

    /* Tratamento de excessao, caso nao cosiga ler o arquivo */
    if (fptr == NULL)
    {
        printf("Não foi possivel abrir o arquivo.\n");

        exit(EXIT_FAILURE);
    }
    
    char str[BUFFER_SIZE];
    char *pos;

    int index;
    
    int count = 0;

    /* le as linhas do arquivo ate o final dele */
        while ((fgets(str, BUFFER_SIZE, fptr)) != NULL)
        {
            index = 0;

            /* encontra a proxima ocorrencia da palavra em str */
            while ((pos = strstr(str + index, word)) != NULL)
                {
                    index = (pos - str) + 1;
                    count++;
                }
        }

    return count;

    fclose(fptr);
}