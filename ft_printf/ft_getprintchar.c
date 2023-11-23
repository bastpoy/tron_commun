/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprintchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:56:33 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/22 14:40:05 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_getprintchar(va_list parameter, const char *entry)
{
	char	caracter;
	char	*str;

	if (*entry == 'c')
	{
		caracter = (char)va_arg(parameter, int);
		ft_putchar_fd(caracter, 1);
		return (1);
	}
	else
	{
		str = va_arg(parameter, char *);
		if(!str)
		{
			ft_putstr_fd("(null)", 1);
			return(6);
		}
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
}
