/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:32:00 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/15 18:52:45 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_max_int(char *arg)
{
	int		number;
	char	*str;

	number = ft_atoi(arg);
	str = ft_itoa(number);
	if (!ft_strnstr(str, arg, ft_strlen(str)))
		return (free(str), 0);
	return (free(str), 1);
}

int	check_twoarg(char *str)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	tab = ft_split(str, ' ');
	while (tab[i])
	{
		j = i - 1;
		if ((!ft_atoi(tab[i]) && tab[i][0] != '0') || !check_max_int(tab[i]))
			return (free_twodim(tab), 0);
		while (j >= 0)
		{
			if (ft_atoi(tab[i]) == ft_atoi(tab[j]))
				return (free_twodim(tab), 0);
			j--;
		}
		i++;
	}
	return (free_twodim(tab), 1);
}

int	checkparam(int argc, char **argv)
{
	int	i;
	int	j;

	i = argc - 1;
	while (i > 0)
	{
		j = 1;
		if ((!ft_atoi(argv[i]) && argv[i][0] != '0') || !check_max_int(argv[i]))
			return (0);
		while (j < i)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i--;
	}
	return (1);
}

int	check(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		if (!check_twoarg(argv[1]))
			return (ft_printf("Error\n"), 0);
	}
	else
	{
		if (!checkparam(argc, argv))
			return (ft_printf("Error\n"), 0);
	}
	return (1);
}
