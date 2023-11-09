/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:06:49 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/09 18:23:58 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
int ft_countsep(char const *s, char c)
{
    int i; 
    int count;

    count = 0;
    i = 0;
    while(s[i])
    {
        if(s[i] == c)
            count++;
        i++;
    }
    return (count);
}

char **ft_split(char const *s, char c)
{
    char **str;
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = ft_countsep(s, c) + 1;
    str = malloc((k + 1) * sizeof(char));
    while(i < k)
    {
        printf("i vaut %d\n",i);
        str[i] = malloc((ft_strlen((char*)s) + 1) * sizeof(char));
         i++;
    }
    i = 0;
    k = 0;
    while(s[i])
    {
        while(s[i] != c && s[i] != '\0')
        {
            str[k][j] = s[i];
            i++;
            j++;
            if(s[i] == c || s[i] == '\0')
            {
                str[k][j] = '\0';
                k++;
                j = 0;
            }
        }
        i++;
    }
    str[k] = NULL;
    return str;
}


// int main(void)
// {
//     int i = 0;

//     char **str = ft_split("hhhallerhmechmecton",'h');
//     while(str[i])
//     {
//         printf("%s\n",str[i]);
//         i++;
//     }
// }