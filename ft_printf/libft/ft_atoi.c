/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:40:58 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/17 19:19:28 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	test_max(long int n)
{
	if (n > INT_MAX)
		return (-1);
	if (n < INT_MIN)
		return (0);
	return (n);
}

static long int	ft_chartoint(char *str, int sign)
{
	long int	output;

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

static char	*space(char *str)
{
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r')
	{
		str++;
	}
	return (str);
}

int	ft_atoi(const char *str)
{
	int		sign;
	char	*ptr;

	ptr = (char *)str;
	sign = 0;
	if (*ptr == ' ' || *ptr == '\n' || *ptr == '\t' || *ptr == '\v'
		|| *ptr == '\f' || *ptr == '\r')
		ptr = space(ptr);
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign = 1;
		ptr++;
	}
	if (*ptr >= '0' && *ptr <= '9')
		return (test_max(ft_chartoint(ptr, sign)));
	return (0);
}
