/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:19:11 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/28 11:21:05 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t j;
	size_t i;

	j = 0;
	i = 0;
	if (!src)
		return (0);
	while (src[j])
		j++;
	if (size == 0)
		return (j);
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (j);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	size_t i;
	size_t j;
	size_t k;

	k = 0;
	i = (int)ft_strlen((char *)s1);
	// printf("i %d\n", (int)i);
	j = (int)ft_strlen((char *)s2);
	// printf("j %d\n", (int)j);
	str = (char *)malloc((i + j + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, (char *)s1, i + 1);
	while (s2[k])
	{
		str[i + k] = s2[k];
		k++;
	}
	str[i + k] = '\0';
	if (s1)
	{
		// printf("free s1\n");
		free((char *)s1);
	}
	if (s2)
	{
		// printf("free s2\n");
		free((char *)s2);
	}
	return (str);
}