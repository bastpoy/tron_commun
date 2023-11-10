/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:38:56 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/10 12:39:04 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int i;
    char *str;

    i = ft_strlen((char*)s);
    str = (char*)malloc((i + 1) * sizeof(char));
    if(!str)
        return (NULL);
    i = 0;
    while(s[i])
    {
        str[i] = *f(i,s[i]);
        i++;
    }
    str[i] = '\0';
    return (str);
}

char my_func(unsigned int i, char str)
{
 	printf("My inner function: index = %d and %c\n", i, str);
	return str - 32;
}

int main()
{
	char str[10] = "hello.";
	printf("The result is %s\n", str);
	char *result = ft_strmapi(str, my_func);
	printf("The result is %s\n", result);
	return 0;
}
