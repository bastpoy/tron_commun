/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:56:23 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/11 15:12:36 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	char	*cpstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cpstr = (char *)str;
	while (cpstr[j] != '\0' && j < (int)len)
	{
		while (cpstr[j + i] == to_find[i] && i + j < (int)len
			&& cpstr[i + j] != '\0')
		{
			i++;
		}
		if (to_find[i] == '\0')
		{
			return (cpstr + j);
		}
		i = 0;
		j++;
	}
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
//     char *str = "yo mec";
//     char *to_find = "";
//     size_t size = 9;
//     // printf("%s\n", catin());
//     printf("%s", ft_strnstr(str, to_find, size));
// }
