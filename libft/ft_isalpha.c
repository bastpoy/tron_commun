/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:29:15 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/10 15:11:04 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

// int	ft_isalpha(int c)
// {
// 	if (c < 65 || (c > 90 && c < 97) || c > 122)
// 	{
// 		return (0);
// 	}
// 	return (1);
// }
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}

// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>
// int main()
// {
// 	printf("%d\n", ft_isalpha(68));
// 	printf("%d\n", isalpha(68));
// }
