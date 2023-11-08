/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:27:24 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/08 18:00:21 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <bsd/string.h>
// #include <stdio.h>
#include "libft.h"

size_t ft_strlcat(char *dest, char *src, size_t size)
{
	unsigned int i;
	unsigned int len_src;
	unsigned int len_dest;

	i = 0;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (len_dest > size)
	{
		return (size + len_src);
	}
	if (size < 1)
	{
		return (len_src + size);
	}
	while (src[i] && (i + 1 + len_dest) < size)
	{
		dest[i + len_dest] = src[i];
		i++;
	}
	dest[i + len_dest] = '\0';
	return (len_dest + len_src);
}
/*
int	main(void)
{
	char	*src1;
	char	*src2;
	int		val;
	int		i;
	int		res;

	src1 = "salutmecert";
	char dest1[13] = "re la fam";
	src2 = "salutmecert";
	char dest2[13] = "re la fam";
	val = 11;
	i = ft_strlcat(dest1, src1, val);
	res = strlcat(dest2, src2, val);
	printf("int un %d\n", i);
	printf("int deux: %d\n", res);
	printf("chaine1: %s\n", dest1);
	printf("chaine2: %s", dest2);
}*/
