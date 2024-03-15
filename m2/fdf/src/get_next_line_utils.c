/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:19:11 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/08 14:29:44 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

static size_t	ft_strlen1(const char *str, int nextbackn)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && (str[i] != '\n' || nextbackn))
	{
		i++;
	}
	if (str[i] == '\n' && nextbackn == 0)
	{
		i++;
	}
	return (i);
}

char	*ft_strdup1(const char *src, int freesrc, int nextbackn, int pi)
{
	size_t	i;
	char	*dest;

	if (!src || *src == '\0')
		return (NULL);
	i = ft_strlen1((char *)src, nextbackn);
	dest = (char *)malloc((i + 1) * sizeof(char));
	if (!dest)
		return (ft_free(src, pi));
	i = 0;
	while (src[i] && (src[i] != '\n' || nextbackn))
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
	{
		dest[i] = '\n';
		i++;
	}
	dest[i] = '\0';
	if (freesrc)
		free((char *)src);
	return (dest);
}

char	*ft_strchr1(const char *s, int c)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	if (!s)
	{
		return (NULL);
	}
	while (*str != (unsigned char)c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	if (*str == '\n')
		return ((char *)str);
	return ((char *)str);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	j;
	size_t	i;

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

char	*ft_strjoin1(char const *s1, char const *s2, int pi)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	i = (int)ft_strlen1((char *)s1, 1);
	j = (int)ft_strlen1((char *)s2, 1);
	str = NULL;
	str = (char *)malloc((i + j + 1) * sizeof(char));
	if (!str)
		return (ft_free(s1, pi));
	ft_strlcpy(str, (char *)s1, i + 1);
	while (s2[k])
	{
		str[i + k] = s2[k];
		k++;
	}
	str[i + k] = '\0';
	if (s1)
		free((char *)s1);
	return (str);
}
