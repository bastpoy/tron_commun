/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:03:14 by bpoyet            #+#    #+#             */
/*   Updated: 2023/12/04 16:19:55 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_checkoverflow(char *overflow, char *buffer)
{
	if (overflow)
		buffer = ft_strdup(overflow, NO_FREE, NEXTBACKN);
	return (buffer);
}

char	*ft_nextoverflow(char *overflow)
{
	char	*temp;

	if (overflow)
	{
		if (ft_strchr(overflow, '\n') && *(ft_strchr(overflow, '\n')
				+ 1) != '\0')
		{
			temp = ft_strdup(overflow, FREE, NONEXTBACKN);
			overflow = ft_strdup(ft_strchr(temp, '\n') + 1, NO_FREE,
					NONEXTBACKN);
			free(temp);
			return (overflow);
		}
		else
		{
			free(overflow);
			overflow = NULL;
			return (NULL);
		}
	}
	return (NULL);
}

char	*ft_readline(char *buffer, int fd)
{
	int		byteread;
	char	*temp;

	byteread = BUFFER_SIZE;
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!temp)
		return(NULL);
	while (!ft_strchr(buffer, '\n') && byteread != 0)
	{
		byteread = read(fd, temp, BUFFER_SIZE);
		if (byteread == -1)
		{
			free(temp);
			return (NULL);
		}
		if (byteread != 0)
		{
			temp[byteread] = '\0';
			buffer = ft_strjoin(buffer, temp, NO_FREE);
		}
	}
	free(temp);
	return (buffer);
}

char	*ft_modifyoverflow(char *buffer, char *overflow)
{
	char	*temp;

	if (ft_strchr(buffer, '\n') && *(ft_strchr(buffer, '\n') + 1) != '\0')
	{
		temp = ft_strchr(buffer, '\n') + 1;
		overflow = ft_strdup(temp, NO_FREE, NONEXTBACKN);
		return (overflow);
	}
	else
	{
		free(overflow);
		overflow = NULL;
		return (NULL);
	}
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*overflow = NULL;

	buffer = NULL;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		free(overflow);
		return (overflow = NULL);
	}
	buffer = ft_checkoverflow(overflow, buffer);
	overflow = ft_nextoverflow(overflow);
	if (!overflow || !buffer)
	{
		buffer = ft_readline(buffer, fd);
		overflow = ft_modifyoverflow(buffer, overflow);
		buffer = ft_strdup(buffer, FREE, NEXTBACKN);
	}
	return (buffer);
}

// int main()
// {
// 	char *str;
// 	int fd = open("text.a",O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	close(fd);
// }