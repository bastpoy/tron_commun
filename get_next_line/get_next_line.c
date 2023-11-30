/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:03:14 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/30 15:10:51 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

size_t ft_getindexbackn(char *temp, int nextbackn)
{
	int i;

	i = 0;
	while ((temp[i] != '\n' || nextbackn) && temp[i] != '\0')
	{
		// printf("%c\n",temp[i]);
		i++;
	}
	if (temp[i] == '\n')
	{
		// printf("dans le backslah n\n");
		i++;
	}
	return (i);
}

char *ft_strdup(const char *src, int freesrc, int nextbackn)
{
	size_t i;
	char *dest;
	if(*src == '\0')
		return(NULL);
	i = ft_getindexbackn((char *)src, nextbackn);
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

char *ft_strchr(const char *s, int c)
{
	unsigned char *str;

	str = (unsigned char *)s;
	if (!s)
	{
		return (NULL);
	}
	while (*str != (unsigned char)c)
	{
		// printf("str %c\n",*str);
		if (*str == '\0')
			return (NULL);
		str++;
	}
	if (*str == '\n')
		return ((char *)str);
	return ((char *)str);
}

// void *ft_free(char *overflow, char *temp, int argument)
// {
// 	if(argument)
// 	{
// 		free(overflow);
// 		overflow = NULL;
// 		return(NULL);	
// 	}
// }

char *get_next_line(int fd)
{
	int bytesread;
	char *buffer;
	char *temp;
	static char *overflow = NULL;

	buffer = NULL;
	bytesread = BUFFER_SIZE;
	if(fd < 0 || read(fd, 0, 0) < 0)
	{
		free(overflow);
		overflow = NULL;
		return(NULL);
	}
	while ((!ft_strchr(buffer, '\0') || !ft_strchr(buffer, '\n') || !(overflow)) && bytesread == BUFFER_SIZE )
	{
		if (overflow) // si jai du text en trop parce que jai eu un retour a la ligne
		{
			if (ft_strchr(overflow, '\n') && *(ft_strchr(overflow, '\n') + 1) != '\0') // si dans cette overflow jai un retour a la ligne et que le caractere dapres n'est pas un \0
			{
				// printf("overflow -%s-\n", overflow);
				temp = ft_strdup(overflow, FREE, NONEXTBACKN); // je passe mon overflow jusquau retour a la ligne
				// printf("tempover -%s-", temp);
				// printf("avant -%s-", ft_strchr(overflow, '\n'));
				overflow = ft_strdup(ft_strchr(temp, '\n') + 1, NO_FREE, NONEXTBACKN); // overflow = ft_strchr(overflow, '\n');// + 1; // javance mon overflow jusqu'au prochain \n
				temp = ft_strdup(temp, FREE, NEXTBACKN);
				// printf("temp -%s-\n", temp);
				return ft_strjoin(buffer, temp);
				// printf("buffer dans -%s-", buffer);
				// return (buffer);
			}
			else // si jen ai pas je peux le passer dans temp et le free
			{
				// printf("overflow dans else -%s-\n", overflow);
				temp = ft_strdup(overflow, FREE, NONEXTBACKN);
				// printf("temp dans overflow -%s-", temp);
				overflow = NULL;
				buffer = ft_strjoin(buffer, temp);
				// printf("buffer: %p et i %p\n", buffer, overflow);
			}
		}
		if (!overflow)
		{
			temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
			bytesread = read(fd, temp, BUFFER_SIZE);
			temp[bytesread] = '\0';
			// printf("temp -%s-\n",temp);
			// printf("bytesread %d\n", bytesread);
			if (bytesread != 0 && bytesread == BUFFER_SIZE && (!(ft_strchr(temp, '\n')))) // si j'ai pas trouve de \n et jai size max byteread different de 0 dans le cas ou je lis un caratcere par un caractere
			{
				// printf("temp1 -%s-\n", temp);
				buffer = ft_strjoin(buffer, temp);
			}
			else if ((ft_strchr(temp, '\n') || ft_strchr(temp, '\0')) && bytesread != 0) // si j'ai trouve un \n ou \0 // le \0 dans le cas ou je suis a la gfin du fichier et au milieu du buffer
			{
				// printf("temp2-%s-\n", temp);
				// printf("avant overflow -%s-\n",ft_strchr(temp, '\n') + 1);
				if(ft_strchr(temp, '\n'))
					overflow = ft_strdup(ft_strchr(temp, '\n') + 1, NO_FREE, NONEXTBACKN); // je stocke ce quil y a apres dans overflow + 1 pour etre un caracterre apres le retour a la ligne de temp
				// printf("overflowok -%s-\n", overflow);
				temp = ft_strdup(temp, FREE, NEXTBACKN);
				return ft_strjoin(buffer, temp);
				// return (buffer);
			}
		}
		if ((!bytesread && !buffer) || (bytesread == -1)) // boucle qui indique la fin du fichier
		{
			free(temp);
			temp = NULL;
			return (NULL);
		}
	}
	free(temp);
	temp = NULL;
	return (buffer);
}


// int main(void)
// {
// 	int fd;
// 	char *str;

// 	fd = open("text.a", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
//  	close(fd);
// 	fd = open("text.a", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	close(fd);
// 	// while(str)
// 	// {
// 	// 	printf("%s", str);
// 	// 	free(str);
// 	// 	str = get_next_line(fd);
// 	// }
// 	// free(str);
// }