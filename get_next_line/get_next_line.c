/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:03:24 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/24 18:43:13 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
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

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*dest;

	i = ft_strlen((char *)src);
	dest = (char *)malloc((i + 1) * sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	i = (int)ft_strlen((char *)s1);
	j = (int)ft_strlen((char *)s2);
	str = (char *)malloc((i + j + 1) * sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, (char *)s1, i + 1);
	while (s2[k])
	{
		str[i + k] = s2[k];
		k++;
	}
	str[i + k] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (*str != (unsigned char)c)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return ((char *)str);
}

char *get_next_line(int fd)
{
	int bytesread;
	char *buffer1;
	char *buffer2;
	char *temp;

	temp = NULL;
	bytesread = BUFFER_SIZE;
	while(!ft_strchr(temp, '\n') && bytesread < BUFFER_SIZE)
	{
		temp = malloc(sizeof(char) * (BUFFER_SIZE));
		bytesread = read(fd, temp, BUFFER_SIZE);
		if(bytesread == BUFFER_SIZE)
		{
			buffer1 = ft_strjoin(buffer1, temp);
			free(temp);
		}
	}
	return(buffer);
}

int main(void)
{
	int fd;

	fd = open("text.txt",O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
}