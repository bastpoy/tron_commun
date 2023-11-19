/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:03:26 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/19 21:17:39 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

static void	writenbr(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putuint_fd(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	writenbr(n % 10 + '0', fd);
}

void	ft_puthex_fd(unsigned long n, int fd)
{
	unsigned long	absolut;
    char *hexastring;

    hexastring = "0123456789abcdef";
	absolut = n;
	if (absolut > 15)
	{
		ft_puthex_fd(absolut / 16, fd);
	}
	writenbr(hexastring[absolut % 16], fd);
}

void ft_getprintchar(va_list parameter,  const char *entry)
{
	char caracter;
	char *str;

	if (*entry == 'c')
	{
		caracter = (char)va_arg(parameter, int);
		ft_putchar_fd(caracter, 1);
	}
	if(*entry == 's')
	{
		str = va_arg(parameter, char*);
		ft_putstr_fd(str, 1);
	}
}

void ft_getprintptr(va_list parameter)
{
	unsigned long adress;

	adress = va_arg(parameter, unsigned long);
	ft_putstr_fd("0x", 1);
	ft_puthex_fd(adress, 1);
}

void ft_getprintint(va_list parameter)
{
	int value;

	value = va_arg(parameter, int);
	ft_putnbr_fd(value, 1);
}

void ft_getprintfuint(va_list parameter)
{
	unsigned int value;

	value = va_arg(parameter, unsigned int);
	ft_putuint_fd(value, 1);
}
int ft_printf(const char *entry, ...)
{
	va_list parameter;
	va_start(parameter, entry);
	while(*entry)
	{
		if(*entry == '%')
		{
			entry++;
			if(*entry == 'c' || *entry == 's')
				ft_getprintchar(parameter, entry);
			if(*entry == 'p')
				ft_getprintptr(parameter);
			if(*entry == 'd' || *entry == 'i')
				ft_getprintint(parameter);
			if(*entry == 'u')
				ft_getprintfuint(parameter);
		}
		else
		{
			ft_putchar_fd(*entry, 1);
		}
		entry++;
	}
	return (0);
}

int main(void)
{
	// int *ptr = malloc(sizeof(int));
	// ft_printf("%d\n",2147483647);
	printf("%ld\n",sizeof(unsigned int));
	printf("%u\n",2147483648);
}



			// if(*entry == 'p')
			// if(*entry == 'd')
			// if(*entry == 'i')
			// if(*entry == 'u')
			// if(*entry == 'x' || *entry == 'X')
			// if(*entry == '%')



// Pouvoir manipuler ma chaine. Il faut que je puisse print les caracteres
// et tout ce qui est precede de %(i,d,ld) doit etre remplacer par la valeur passe en parametre

// pouvoir detecter le nieme %d et l'associer au nieme parametre.
// je peux faire ca en utilisant les listes chainees