/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:37:26 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/13 00:37:19 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countnum(int n)
{
	int				i;
	unsigned int	nb;

	i = 0;
	if (n < 0)
	{
		nb = -n;
		i++;
	}
	else
		nb = n;
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i + 1);
}

static void	ft_putnbr(int nb, char *str, int *i)
{
	unsigned int	absolut;

	if (nb < 0)
	{
		absolut = -nb;
		str[*i] = '-';
		*i += 1;
	}
	else
		absolut = nb;
	if (absolut > 9)
	{
		ft_putnbr(absolut / 10, str, i);
	}
	str[*i] = absolut % 10 + '0';
	*i += 1;
}

char	*ft_itoa(int n)
{
	int		count;
	char	*str;
	int		*i;

	count = countnum(n);
	i = (int *)malloc(1 * sizeof(int));
	str = (char *)malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_putnbr(n, str, i);
	str[count] = '\0';
	return (str);
}

// #include <stdlib.h>
// #include <unistd.h>
// #include <stdio.h>

// void	ft_print_result(char const *s)
// {
// 	int		len;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	write(1, s, len);
// }

// int		main(int argc, const char *argv[])
// {
// 	int		arg;

// 	alarm(5);
// 	if (argc == 1)
// 		return (0);
// 	else if ((arg = atoi(argv[1])) == 1)
// 	{
// 		char *res = ft_itoa(0);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	else if (arg == 2)
// 	{
// 		char *res = ft_itoa(9);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	else if (arg == 3)
// 	{
// 		char *res = ft_itoa(-9);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	else if (arg == 4)
// 	{
// 		char *res = ft_itoa(10);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	else if (arg == 5)
// 	{
// 		char *res = ft_itoa(-10);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	else if (arg == 6)
// 	{
// 		char *res = ft_itoa(8124);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	else if (arg == 7)
// 	{
// 		char *res = ft_itoa(-9874);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	else if (arg == 8)
// 	{
// 		char *res = ft_itoa(543000);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	else if (arg == 9)
// 	{
// 		char *res = ft_itoa(-2147483648LL);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	else if (arg == 10)
// 	{
// 		char *res = ft_itoa(2147483647);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	return (0);
// }