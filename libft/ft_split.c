/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:06:49 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/16 20:26:21 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_countsep(char const *s, char c)
{
	int	count;
	int	state;

	state = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && state == 0)
		{
			count++;
			state = 1;
		}
		if (*s == c && state == 1)
			state = 0;
		s++;
	}
	return (count);
}

static char	*ft_addword(char **str, int *i, int *j, const char *s)
{
	int k;
	int l;
	const char *ptr;

	ptr = s - *i;
	l = 0;
	k = *j;
	// str[k] = ft_substr(s - *i, 0, *i);
	str[k] = (char *)malloc((*i + 1) * sizeof(char));
	if (!str)
		return (0);
	while (ptr[l] && l < *i)
	{
		str[k][l] = ptr[l];
		l++;
	}
	str[k][l] = 0;
	*i = 0;
	// *j = *j + 1;
	return (str[k]);
}

static char	**ft_testmalloc(char **str, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	return (NULL);
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
			if ((*s == c || *s == '\0'))
			{
				str[j] = ft_addword(str, &i, &j, s);
				if (!str[j])
					return (ft_testmalloc(str, j));
				j++;
			}
		}
	}
	str[j] = NULL;
	return (str);
}

// static int	count_words(const char *str, char c)
// {
// 	int i;
// 	int trigger;

// 	i = 0;
// 	trigger = 0;
// 	while (*str)
// 	{
// 		if (*str != c && trigger == 0)
// 		{
// 			trigger = 1;
// 			i++;
// 		}
// 		else if (*str == c)
// 			trigger = 0;
// 		str++;
// 	}
// 	return (i);
// }

// static char	*word_dup(const char *str, int start, int finish)
// {
// 	char	*word;
// 	int		i;

// 	i = 0;
// 	word = malloc((finish - start + 1) * sizeof(char));
// 	while (start < finish)
// 		word[i++] = str[start++];
// 	word[i] = '\0';
// 	return (word);
// }

// char		**ft_split(char const *s, char c)
// {
// 	size_t	i;
// 	size_t	j;
// 	int		index;
// 	char	**split;

// 	if (!s || !(split = malloc((count_words(s, c) + 1) * sizeof(char *))))
// 		return (0);
// 	i = 0;
// 	j = 0;
// 	index = -1;
// 	while (i <= ft_strlen(s))
// 	{
// 		if (s[i] != c && index < 0)
// 			index = i;
// 		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
// 		{
// 			split[j++] = word_dup(s, index, i);
// 			index = -1;
// 		}
// 		i++;
// 	}
// 	split[j] = 0;
// 	return (split);
// }

// int	main(void)
// {
// 	int i = 0;

// 	char **str = ft_split("  tripouille  42  ", ' ');
// 	// char **str1 = ft_split1("  tripouille  42  ", ' ');
// 	while (i < 2)
// 	{
// 		printf("%s et i %d\n", str[i],i);
// 		i++;
// 	}
// 	free(str);
// 	// free(str1);
// }
