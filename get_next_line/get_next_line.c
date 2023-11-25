/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:03:24 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/25 14:48:59 by bpoyet           ###   ########.fr       */
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
	if(!str)
		return(0);
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
	if(!src)
		return(0);
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

size_t ft_getindexbackn(char *temp)
{
	int i;

	i = 0;
	while(temp[i] != '\n' && temp[i] != '\0')
	{
		i++;
		printf("%d\n",i);
	}
	return (i);
}

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*dest;

	i = ft_getindexbackn((char *)src);
	dest = (char *)malloc((i + 1) * sizeof(char));
	printf("%d\n", (int)i);
	if (!dest)
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	free((char*)src);
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	if(!s)
	{
		return(NULL);
	}
	while (*str != (unsigned char)c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	i = (int)ft_strlen((char *)s1);
	printf("i %d\n",(int)i);
	j = (int)ft_strlen((char *)s2);
	printf("j %d\n",(int)j);
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
	if(s1)
	{
		printf("free s1\n");
		free((char*)s1);
	}
	if(s2)
	{
		printf("free s2\n");
		free((char*)s2);
	}
	return (str);
}

char *get_next_line(int fd)
{
	int bytesread;
	char *buffer;
	char *temp;

	buffer = NULL;
	bytesread = BUFFER_SIZE;
	while(!ft_strchr(buffer, '\n') && bytesread == BUFFER_SIZE)
	{
		temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		bytesread = read(fd, temp, BUFFER_SIZE);
		temp[bytesread] = '\0';
		printf("bytesread %d\n", bytesread);
		if(bytesread == BUFFER_SIZE && !ft_strchr(temp, '\n'))// si j'ai pas trouve de \n et jai size max
		{
			buffer = ft_strjoin(buffer, temp);
			printf("buffer %s\n", buffer);
		}
		else if((ft_strchr(temp, '\n') || ft_strchr(temp, '\0')))// si jai un bytes read inferieur ou egale et jai trouve un \n ou \0
		{
			printf("dans le \\n");
			printf("lindex a free est %d\n", (int)ft_getindexbackn(temp));
			temp = ft_strdup(temp);
			buffer = ft_strjoin(buffer, temp);
			return(buffer);
		}
	}
	free(temp);
	printf("la taille vaut %d\n", (int)ft_strlen(buffer));
	return(buffer);
}

int main(void)
{
	int fd;
	char *str;

	fd = open("text.txt",O_RDONLY);
	str = get_next_line(fd);
	// printf("%s", str);
	close(fd);
	free(str);
}