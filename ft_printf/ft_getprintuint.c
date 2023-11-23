/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprintuint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:08:16 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/23 16:08:08 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
// #include <stdio.h>

int	ft_getprintuint(va_list parameter)
{
	unsigned int	value;
	int length;
	int error;

	error = 1;
	length = 0;
	value = va_arg(parameter, unsigned int);
	ft_putuint_fd(value, 1, &error, &length);
	if(!error)
		return(-1);
	return (length);
}
