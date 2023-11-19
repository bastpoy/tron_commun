/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:03:26 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/19 16:13:23 by bpoyet           ###   ########.fr       */
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

void	ft_puthex_fd(int n, int fd)
{
	unsigned int	absolut;
    char *hexastring;

    hexastring = "0123456789abcdef";
	if (n < 0)
	{
		absolut = -n;
		writenbr('-', fd);
	}
	else
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
	int value;

	value = va_arg(parameter, int);
	ft_putstr_fd(&value, 1);
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
	int *ptr = malloc(sizeof(int));
	ft_printf("%c%s%p\n",'y',"putepute", ptr);
	printf("%c%s%p\n",'y',"putepute", ptr);
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