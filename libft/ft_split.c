/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:06:49 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/15 00:37:56 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_countsep(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && i != 0 && s[i + 1] != '\0' && s[i - 1] != c)
		{
			printf("i %d\n", i);
			count++;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = ft_countsep(s, c) + 1;
	if (!(str = malloc((j + 1) * sizeof(char))))
		return (0);
	j = 0;
	while (*s)
	{
		while(str[i] == c)
			s++;
	}
	str[j] = NULL;
	return (str);
}

int	main(void)
{
	int i = 0;

	char **str = ft_split(" 0qwer 0re rweq  eqwr ", ' ');
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
	free(str);
}