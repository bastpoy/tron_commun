/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:19:11 by bpoyet            #+#    #+#             */
/*   Updated: 2023/12/01 12:24:41 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str, int nextbackn)
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

char	*ft_strjoin(char const *s1, char const *s2, int freearg)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	i = (int)ft_strlen((char *)s1, 1);
	j = (int)ft_strlen((char *)s2, 1);
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
		free((char *)s1);
	if (s2 && freearg == 1)
		free((char *)s2);
	return (str);
}










// 	while ((!ft_strchr(buffer, '\0') || !ft_strchr(buffer, '\n') || !(overflow)) && bytesread == BUFFER_SIZE)
// 	{
// 		if (overflow)
// 		{
// 			if (ft_strchr(overflow, '\n') && *(ft_strchr(overflow, '\n') + 1) != '\0')
// 			{
// 				temp = ft_strdup(overflow, FREE, NONEXTBACKN);
// 				overflow = ft_strdup(ft_strchr(temp, '\n') + 1, NO_FREE,NONEXTBACKN);
// 				temp = ft_strdup(temp, FREE, NEXTBACKN);
// 				return (ft_strjoin(buffer, temp));
// 			}
// 			temp = ft_strdup(overflow, FREE, NONEXTBACKN);
// 			overflow = NULL;
// 			buffer = ft_strjoin(buffer, temp);
// 		}
// 		if (!overflow)
// 		{
// 			temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 			bytesread = read(fd, temp, BUFFER_SIZE);
// 			temp[bytesread] = '\0';
// 			if (bytesread != 0 && bytesread == BUFFER_SIZE && (!(ft_strchr(temp,'\n'))))
// 				buffer = ft_strjoin(buffer, temp);
// 			else if ((ft_strchr(temp, '\n') || ft_strchr(temp, '\0'))&& bytesread != 0)
// 			{
// 				if (ft_strchr(temp, '\n'))
// 					overflow = ft_strdup(ft_strchr(temp, '\n') + 1, NO_FREE,NONEXTBACKN);
// 				temp = ft_strdup(temp, FREE, NEXTBACKN);
// 				return (ft_strjoin(buffer, temp));
// 			}
// 		}
// 		if ((!bytesread && !buffer) || (bytesread == -1))
// 			return (temp = ft_free(NULL, temp, 2));
// 	}
// 	temp = ft_free(NULL, temp, 2);
// 	return (buffer);
// }