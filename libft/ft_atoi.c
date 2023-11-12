/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:40:58 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/08 17:48:42 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
#include "libft.h"

unsigned int	ft_chartoint(char *str, int sign)
{
	unsigned int	output;

	output = 0;
	while (*str >= '0' && *str <= '9')
	{
		output = output * 10 + (*str - '0');
		str++;
	}
	if (sign)
		return (-output);
	return (output);
}

char	*space(char *str)
{
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r')
	{
		str++;
	}
	return (str);
}

int	ft_atoi(char *str)
{
	int	sign;

	sign = 0;
	if (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str = space(str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = 1;
		str++;
	}
	if (*str >= '0' && *str <= '9')
		return (ft_chartoint(str, sign));
	return (0);
}

// int	main(void)
// {
// 	char	*str;

// 	str = "		2147\n483648ab567";
// 	printf("%d\n", ft_atoi(str));
// 	printf("%d", atoi(str));
// }
