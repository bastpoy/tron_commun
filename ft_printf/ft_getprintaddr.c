/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprintaddr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:55:11 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/21 15:55:54 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_getprintaddr(va_list parameter, const char *entry)
{
	unsigned long	adress;
	int				length;

	adress = va_arg(parameter, unsigned long);
	length = (int)ft_dividhex(adress);
	if (*entry == 'x')
		ft_puthex_fd(adress, 1, 0);
	else if (*entry == 'X')
		ft_puthex_fd(adress, 1, 1);
	else
	{
		ft_putstr_fd("0x", 1);
		length += 2;
		ft_puthex_fd(adress, 1, 0);
	}
	return (length);
}
