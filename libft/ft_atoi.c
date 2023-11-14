/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:40:58 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/14 14:49:27 by bpoyet           ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	int	sign;
	char *ptr = (char*)str;
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
		return (ft_chartoint(ptr, sign));
	return (0);
}

int	main(void)
{
	return(0);
}
