/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprintuint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:08:16 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/21 15:55:59 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_getprintuint(va_list parameter)
{
	unsigned int	value;
	char			*length;

	value = va_arg(parameter, unsigned int);
	ft_putuint_fd(value, 1);
	length = ft_itoa(value);
	return ((int)ft_strlen(length));
}
