/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:03:14 by bpoyet            #+#    #+#             */
/*   Updated: 2023/12/12 09:18:40 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free(const char *a, int pi)
{
	if (a)
		free((char *)a - pi);
	return (NULL);
}

char	*ft_nextoverflow(char *overflow)
{
	char	*temp;

	if (ft_strchr(overflow, '\n')
		&& *(ft_strchr(overflow, '\n') + 1) != '\0')
	{
		temp = ft_strdup(overflow, FREE, NONEXTBACKN, 0);
		if (!temp)
			return (NULL);
		overflow = ft_strdup(ft_strchr(temp, '\n') + 1, NO_FREE, NONEXTBACKN,
				1);
		free(temp);
		if (!overflow)
			return (NULL);
		return (overflow);
	}
	else
	{
		free(overflow);
		overflow = NULL;
		return (NULL);
	}
	return (NULL);
}

char	*ft_readline(char *buffer, int fd)
{
	int		byteread;
	char	*temp;

	byteread = BUFFER_SIZE;
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (ft_free(buffer, 0));
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
			buffer = ft_strjoin(buffer, temp, 0);
		}
	}
	free(temp);
	return (buffer);
}

char	*ft_modifyoverflow(char *buffer, char *overflow, char **ptrbuffer)
{
	if (ft_strchr(buffer, '\n') && *(ft_strchr(buffer, '\n') + 1) != '\0')
	{
		overflow = ft_strdup(ft_strchr(buffer, '\n') + 1, NO_FREE, NONEXTBACKN,
				1);
		if (!overflow)
		{
			*ptrbuffer = NULL;
		}
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
	if (overflow)
	{
		buffer = ft_strdup(overflow, NO_FREE, NEXTBACKN, 0);
		if (!buffer)
			return (NULL);
		overflow = ft_nextoverflow(overflow);
	}
	if (!overflow || !buffer)
	{
		buffer = ft_readline(buffer, fd);
		if (!buffer)
			return (NULL);
		overflow = ft_modifyoverflow(buffer, overflow, &buffer);
		buffer = ft_strdup(buffer, FREE, NEXTBACKN, 0);
	}
	return (buffer);
}
