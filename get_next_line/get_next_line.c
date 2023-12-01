/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:03:14 by bpoyet            #+#    #+#             */
/*   Updated: 2023/12/01 15:08:37 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

// size_t	ft_getindexbackn(char *temp, int nextbackn)
// {
// 	int	i;

// 	i = 0;
// 	while ((temp[i] != '\n' || nextbackn) && temp[i] != '\0')
// 	{
// 		i++;
// 	}
// 	if (temp[i] == '\n')
// 	{
// 		i++;
// 	}
// 	return (i);
// }

char	*ft_strdup(const char *src, int freesrc, int nextbackn)
{
	size_t	i;
	char	*dest;

	if (!src || *src == '\0')
		return (NULL);
	i = ft_strlen((char *)src, nextbackn);
	dest = malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
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

char	*ft_strchr(const char *s, int c)
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

char	*ft_free(char *overflow, char *temp, int argument)
{
	if (argument == 1)
	{
		free(overflow);
		overflow = NULL;
	}
	if (argument == 2)
	{
		free(temp);
		temp = NULL;
	}
	return (NULL);
}
char *ft_checkoverflow(char* overflow, char* buffer)
{
	char *temp;

	temp = NULL;
	if(overflow)
	{
		if(ft_strchr(overflow, '\n') && *(ft_strchr(overflow, '\n') + 1) != '\0')
		{
			temp = ft_strdup(overflow, NO_FREE, NEXTBACKN);
			buffer = ft_strjoin(buffer, temp, FREE);
		}
		else
		{
			buffer = ft_strjoin(buffer, overflow, NO_FREE);
		}
	}
	return (buffer);
}

char *ft_nextoverflow(char *overflow)
{
	if(overflow)
	{
		if(ft_strchr(overflow, '\n') && *(ft_strchr(overflow, '\n') + 1) != '\0')
		{
			overflow = ft_strdup(ft_strchr(overflow, '\n') + 1, NO_FREE,NONEXTBACKN);
			return (overflow);
		}
		else
		{
			free(overflow);
			return(NULL);
		}
	}
	return (NULL);
}

char *ft_readline(char *buffer, int fd)
{
	int byteread;
	char *temp;

	byteread = BUFFER_SIZE;
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	// printf("re");
	while(!ft_strchr(buffer, '\n') && byteread != 0)
	{
		// printf("pouet");
		byteread = read(fd, temp, BUFFER_SIZE);
		if(byteread == -1)
		{
			free(temp);
			return NULL;
		}
		if(byteread != 0)// si il vaut 0 jecris pas dans mon buffer;
		{
			temp[byteread] = '\0';
			// printf("temp -%s-\n",temp);
			buffer = ft_strjoin(buffer, temp, NO_FREE);
		}
	}
	// printf("la");
	free(temp);
	return (buffer);
}

char *ft_modifyoverflow(char *buffer, char *overflow)
{
	if(ft_strchr(buffer, '\n') && *(ft_strchr(buffer, '\n') + 1) != '\0')
	{
		overflow = ft_strdup(ft_strchr(buffer, '\n') + 1, NO_FREE, NONEXTBACKN);
		return (overflow);
	}
	else
	{
		free(overflow);
		return (NULL);
	}

}
char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*overflow = NULL;

	buffer = NULL;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (overflow = ft_free(overflow, NULL, 1));
	//si jai overflow je le mets avant buffer et je return buffer	 entree: buffer/over     sortie: buffer => return buffer avec nouveau over sinon rien si presence \n fin de fonctions 
	// printf("\noverflowok -%s-", overflow);
	buffer = ft_checkoverflow(overflow, buffer);
	// printf("buffer apres over -%s-\n", buffer);
	//modification overflow et attribution de nouvelle valeur		 entree: overflow 		sortie: overflow => null si dans buffer overflow si presence dun \n
	overflow = ft_nextoverflow(overflow);
	// printf("overflow change -%s-\n", overflow);
	//je lis tant que j'ai pas un retour a la ligne ou de fin     	 entree: buffer 		sortie: buffer => buffer avec des elements du texte
	if(!overflow && !buffer)
	{
		buffer = ft_readline(buffer, fd);
		// printf("buffer1 -%s-\n",buffer);
		//je stocke la valeur en trop si il y en a une dans mon over	 entree: buffer/over 	sortie: over => null si pas over sinon over
		overflow = ft_modifyoverflow(buffer, overflow);
		printf("%d\n",(int)ft_strlen((char*)overflow,NONEXTBACKN));
		// printf("overflow -%s-", overflow);
		buffer = ft_strdup(buffer, FREE, NEXTBACKN);
		// printf("buffer2 -%s-\n",buffer);
	}
	// printf("fin buffer -%s-\n", buffer);
	return (buffer);
}

int main(void)
{
	int fd;
	char *str;

	fd = open("text.a", O_RDONLY);
	str = get_next_line(fd);
	// printf("%s", str);
	// free(str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// free(str);
	// close(fd);
	// str = get_next_line(fd);
	// printf("%s", str);
	// free(str);
 	// close(fd);
	// fd = open("text.a", O_RDONLY);
	while(str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	free(str);
}