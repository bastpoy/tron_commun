/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprintint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:53:59 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/21 15:55:43 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_getprintint(va_list parameter)
{
	int		value;
	char	*length;

	value = va_arg(parameter, int);
	ft_putnbr_fd(value, 1);
	length = ft_itoa(value);
	return (ft_strlen(length));
}
