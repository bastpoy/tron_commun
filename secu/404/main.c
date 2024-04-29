#include <stdio.h>
#include <string.h>
#include "./libft/libft.h"
#include <math.h>

char *converttobinary(char str, char *str1)
{
   switch (str) {
        case '0': str1 = ft_strjoin(str1, "0000"); break;
        case '1': str1 = ft_strjoin(str1, "0001"); break;
        case '2': str1 = ft_strjoin(str1, "0010"); break;
        case '3': str1 = ft_strjoin(str1, "0011"); break;
        case '4': str1 = ft_strjoin(str1, "0100"); break;
        case '5': str1 = ft_strjoin(str1, "0101"); break;
        case '6': str1 = ft_strjoin(str1, "0110"); break;
        case '7': str1 = ft_strjoin(str1, "0111"); break;
        case '8': str1 = ft_strjoin(str1, "1000"); break;
        case '9': str1 = ft_strjoin(str1, "1001"); break;
        case 'A': case 'a': str1 = ft_strjoin(str1, "1010"); break;
        case 'B': case 'b': str1 = ft_strjoin(str1, "1011"); break;
        case 'C': case 'c': str1 = ft_strjoin(str1, "1100"); break;
        case 'D': case 'd': str1 = ft_strjoin(str1, "1101"); break;
        case 'E': case 'e': str1 = ft_strjoin(str1, "1110"); break;
        case 'F': case 'f': str1 = ft_strjoin(str1, "1111"); break;
        default:
            printf("Caractère hexadécimal invalide : %c\n", str);
            exit(EXIT_FAILURE);
    }
}

char **resizebit(char *str1)
{
    int len = strlen(str1);
    int num_chunks = len / 10 + (len % 10 != 0); // Calculer le nombre de paquets de 10 bits
    char **chunks = malloc((num_chunks + 1) * sizeof(char *)); // Allouer de la mémoire pour les paquets

    int i;
    for(i = 0; i < num_chunks; i++)
    {
        chunks[i] = malloc(11 * sizeof(char)); // Allouer de la mémoire pour chaque paquet
        strncpy(chunks[i], &str1[i * 10], 10); // Copier 10 caractères à chaque fois
        chunks[i][10] = '\0'; // Ajouter un caractère de fin de chaîne
    }

    chunks[num_chunks] = NULL; // Ajouter un pointeur NULL à la fin du tableau pour indiquer la fin

    return chunks;
}

int binaryToDecimal(char *binary)
{
    int decimal = 0;
    // int length = strlen(binary);
    for(int i = 1; i < 9; i++)
    {
        if(binary[9 - i])
        {
            // printf("i vaut %d et %d\n", i, binary[9 - 1 - i]);
            if(binary[9 - i] == '1')
                decimal += pow(2, i - 1);
        }
    }
    printf("decimal %d et ascii value %c\n", decimal, (char)decimal);
    return decimal;
}

int main(int argc, char *argv[])
{
    char **strsplit;
    char *str1;
    char **ten;

    str1 = ft_strdup("");
    int i = 0;
    int j = 0;

    strsplit = ft_split(argv[1], ' ');
    while(strsplit[i])
    {
        j = 0;
        while(strsplit[i][j])
        {
            str1 = converttobinary(strsplit[i][j], str1);
            j++;
        }
        i++;
    }
    i = 0;
    printf("str %s\n", str1);
    ten = resizebit(str1);
    while(ten[i])
    {
        printf("str %s\n", ten[i]);
        binaryToDecimal(ten[i]);
        i++;
    }
    return (0);
}