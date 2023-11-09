/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:10:33 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/09 13:21:58 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *str;
    int i;
    
    i = 0;
    str = (char *)malloc((len + 1)*sizeof(char));
    if(!str)
        return(0);
    while(s[i] && i < (int)len)
    {
        str[i] = s[start + i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

// #include <stdio.h>

// int main(void)
// {
//     printf("%s\n", ft_substr("yo mon pote",0,15));
//     printf("%s", substr("yo mon pote",0,15));
// }