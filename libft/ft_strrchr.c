/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:22:08 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/07 16:02:10 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

char	*strrchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != '\0')
		str++;
	while (*str != (char)c && s != str)
		str--;
	if (*str == (char)c)
		return (str);
	else
		return (0);
}

// int main(void)
// {
//     char *str = "y le y rap";
//     printf("%s", strrchr(str, 'y'));
// }