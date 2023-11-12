/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:58:43 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/11 15:59:04 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (i == n)
	{
		return (0);
	}
	while (i < (unsigned int)n - 1 && (s1[i] || s2[i]) && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// int	main(void)
// {
// 	char un[]="test\200";
// 	char deux[]="test\0";

// 	printf("%d\n",ft_strncmp(un, deux,6));
// 	printf("%d",strncmp(un, deux, 6));
// }