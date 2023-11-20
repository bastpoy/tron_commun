/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:03:26 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/20 18:01:51 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_print.h"

int ft_getprintchar(va_list parameter,  const char *entry)
{
	char caracter;
	char *str;

	if (*entry == 'c')
	{
		caracter = (char)va_arg(parameter, int);
		ft_putchar_fd(caracter, 1);
		return (ft_strlen(entry));
	}
	else
	{
		str = va_arg(parameter, char*);
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
}

int ft_getprintaddr(va_list parameter, const char *entry)
{
	unsigned long adress;
	int length;

	adress = va_arg(parameter, unsigned long);
	length = ft_dividhex(adress);
	if(*entry == 'x')
	{
		ft_puthex_fd(adress, 1, 0);
		return(1);
	}
	else if(*entry == 'X')
	{
		ft_puthex_fd(adress, 1, 1);
	}
	else
	{
		ft_putstr_fd("0x", 1);
		ft_puthex_fd(adress, 1, 0);
	}
	return(length);
}

int ft_getprintint(va_list parameter)
{
	int value;
	char *length;

	value = va_arg(parameter, int);
	ft_putnbr_fd(value, 1);
	length = ft_itoa(value);
	return(ft_strlen(length));
}

int ft_getprintfuint(va_list parameter)
{
	unsigned int value;
	char *length;

	value = va_arg(parameter, unsigned int);
	ft_putuint_fd(value, 1);
	length = ft_itoa(value);
	return(ft_strlen(length));
}

int ft_getprintfperc()
{
	ft_putchar_fd('%', 1);
	return (1);
}

int ft_printf(const char *entry, ...)
{
	va_list parameter;
	va_start(parameter, entry);
	int lengthoutput;

	while(*entry)
	{
		if(*entry == '%')
		{
			entry++;
			if(*entry == 'c' || *entry == 's')
				lengthoutput += ft_getprintchar(parameter, entry);
			if(*entry == 'p' || *entry == 'x' || *entry == 'X')
				lengthoutput += ft_getprintaddr(parameter, entry);
			if(*entry == 'd' || *entry == 'i')
				lengthoutput += ft_getprintint(parameter);
			if(*entry == 'u')
				lengthoutput += ft_getprintfuint(parameter);
			if(*entry == '%')
				lengthoutput += ft_getprintfperc();
		}
		else
			ft_putchar_fd(*entry, 1);
		printf("\n	la len vaut %d\n", lengthoutput);
		entry++;
		lengthoutput++;
	}
	return (lengthoutput);
}

int main(void)
{
	printf("output %d\n",ft_printf("%x\n",2147483647));
	printf("output %d\n",printf("%x\n",2147483647));
}