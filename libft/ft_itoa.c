/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:37:26 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/10 12:37:29 by bpoyet           ###   ########.fr       */
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
	while (nb >= 10)
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
	i = (int *)malloc(10 * sizeof(int));
	str = (char *)malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_putnbr(n, str, i);
	free(i);
	str[count] = '\0';
	return (str);
}