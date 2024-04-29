/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:56:23 by bpoyet            #+#    #+#             */
/*   Updated: 2024/04/29 16:53:37 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	char	*cpstr;
	size_t	i;
	size_t	j;

	j = 0;
	cpstr = (char *)str;
	if (str == to_find || (str && *to_find == '\0'))
		return (cpstr);
	while (cpstr[j] != '\0' && j < len)
	{
		i = 0;
		while (cpstr[j + i] == to_find[i] && i + j < len && to_find[i] != '\0'
			&& cpstr[i + j] != '\0')
			i++;
		if (i == ft_strlen(to_find))
		{
			printf("la sous chaine est a la position %ld\n", j);
			return (cpstr + j);
		}
		j++;
	}
	return (0);
}
