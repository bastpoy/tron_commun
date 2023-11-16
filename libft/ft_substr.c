/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:10:33 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/16 15:44:38 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			size;
	unsigned int	i;

	i = 0;
	if (start > (unsigned int)ft_strlen((char *)s) && s)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s[i] && i < (unsigned int)len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// #include <stdio.h>

// int main(void)
// {
//     printf("%s\n", ft_substr("tripouille",0,42000));
// 	printf("%s\n", ft_substr2("tripouille",0,42000));
// }