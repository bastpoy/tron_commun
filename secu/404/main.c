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
    return(str1);
}

char **resizebit(char *str1)
{
    int len = strlen(str1);
    int codage = 10;
    int num_chunks = len / codage + (len % codage != 0); // Calculer le nombre de paquets de 10 bits
    char **chunks = malloc((num_chunks + 1) * sizeof(char *)); // Allouer de la mémoire pour les paquets

    int i;
    for(i = 0; i < num_chunks; i++)
    {
        chunks[i] = malloc(10 * sizeof(char)); // Allouer de la mémoire pour chaque paquet
        strncpy(chunks[i], &str1[i * codage], codage); // Copier 10 caractères à chaque fois
        chunks[i][codage] = '\0'; // Ajouter un caractère de fin de chaîne
    }

    chunks[num_chunks] = NULL; // Ajouter un pointeur NULL à la fin du tableau pour indiquer la fin

    return chunks;
}

int binaryToDecimal(char *binary)
{
    int decimal = 0;
    int codage = 9;
    // int length = strlen(binary);
    for(int i = 1; i < codage; i++)
    {
        if(binary[codage - i])
        {
            // printf("i vaut %d et %d\n", i, binary[9 - 1 - i]);
            if(binary[codage - i] == '1')
                decimal += pow(2, i - 1);
        }
    }
    printf("decimal %d et ascii value %c\n", decimal, (char)decimal);
    return decimal;
}

char *reversestring(char *str)
{
    char *reversestr = malloc(sizeof(char) * ft_strlen(str));
    int i = 0;
    int j = ft_strlen(str);
    while(str[i])
    {
        reversestr[i] = str[j - 1 - i];
        i++;
    }
    reversestr[i] = '\0';
    return (reversestr);
}

int main(int argc, char *argv[])
{
    char **strsplit;
    char *str1;
    char **ten;
    char *reversestr;

    char *tofind[] = {"011110111", "011111011", NULL};

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
    printf(" la reverse str %s\n", reversestring(str1));

    reversestr = reversestring(str1);
    while(tofind[i])
    {
        if(ft_strnstr(reversestr, tofind[i], ft_strlen(reversestr)))
        {
            printf("trouver pour %s\n", tofind[i]);
        }
        i++;
    }
    printf("la sub %s\n", ft_substr(reversestr, 32, 84));
    // ten = resizebit(str1);
    // while(ten[i])
    // {
    //     if(ten[i][0] == '0' && ten[i][8] == '1')
    //     {
    //         printf("str %s\n", ten[i]);
    //         binaryToDecimal(ten[i]);
    //     }
    //     i++;
    // }
    return (0);
}