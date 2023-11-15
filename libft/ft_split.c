/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:06:49 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/15 15:43:19 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
			count++;
		}
		i++;
	}
	return (count + 1);
}

void	ft_addword(char **str, int *i, int *j, const char *s)
{
	str[*j] = ft_substr(s - *i, 0, *i);
	*i = 0;
	*j = *j + 1;
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc((ft_countsep(s, c) + 1) * sizeof(char **));
	if (!str)
		return (0);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			s++;
			i++;
			if (*s == c || *s == '\0')
				ft_addword(str, &i, &j, s);
		}
	}
	str[j] = NULL;
	return (str);
}

// int	main(void)
// {
// 	return (0);
// }

// int	main(void)
// {
// 	int i = 0;

// 	char **str = ft_split("      split       this for   me  !       ", ' ');
// 	while (str[i])
// 	{
// 		printf("%s et i %d\n", str[i],i);
// 		i++;
// 	}
// 	free(str);
// }
