/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:02:17 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/10 15:19:37 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = (int)ft_strlen((char *)s1);
	j = (int)ft_strlen((char *)s2);
	str = (char *)malloc((i + j + 1) * sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, (char *)s1, i + 1);
	while (i + k < i + j + 1)
	{
		str[i + k] = s2[k];
		k++;
	}
	str[i + k] = '\0';
	return (str);
}

// #include <stdio.h>
// int	main(int argc, char **argv)
// {
// 	(void)argc;
// 	(void)argv;
// 	printf("%s\n",ft_strjoin("", ""));
//     printf("%s\n",strjoin("", ""));
// }