/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chooseprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:04:33 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/21 16:01:52 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_chooseprint(int lengthoutput, va_list parameter, const char *entry)
{
	entry++;
	if (*entry == 'c' || *entry == 's')
		lengthoutput += ft_getprintchar(parameter, entry);
	else if (*entry == 'p' || *entry == 'x' || *entry == 'X')
		lengthoutput += ft_getprintaddr(parameter, entry);
	if (*entry == 'd' || *entry == 'i')
		lengthoutput += ft_getprintint(parameter);
	if (*entry == 'u')
		lengthoutput += ft_getprintuint(parameter);
	if (*entry == '%')
		lengthoutput += ft_getprintperc();
	return (lengthoutput);
}
