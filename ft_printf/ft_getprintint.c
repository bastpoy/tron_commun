/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprintint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:53:59 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/23 16:41:51 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_getprintint(va_list parameter)
{
	int		value;
	int error;
	int i;

	i = 0;
	error = 1;
	value = va_arg(parameter, int);
	ft_putnbr(value, 1, &error, &i);
	if(!error)
		return(-1);
	return (i);
}
