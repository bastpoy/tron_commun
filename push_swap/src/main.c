/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:24:21 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/18 11:03:59 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int length_split(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

static t_listx *ft_fill_list(int argc, char **argv)
{
	t_listx *lista;
	int i;

	i = argc - 1;
	lista = ft_init_listx();
	while (i > 0)
	{
		ft_insert_front(lista, ft_atoi(argv[i]), 0);
		i--;
	}
	return (lista);
}

static t_listx *ft_fill_list1(char *argv)
{
	t_listx *lista;
	char **split;
	int i;

	lista = ft_init_listx();
	split = ft_split(argv, ' ');
	i = length_split(split) - 1;
	while (i >= 0)
	{
		ft_insert_front(lista, ft_atoi(split[i]), 0);
		i--;
	}
	free_twodim(split);
	return (lista);
}

int main(int argc, char **argv)
{
	t_listx *lista;

	if (!check(argc, argv))
		return (0);
	if (argc == 2)
		lista = ft_fill_list1(argv[1]);
	else
		lista = ft_fill_list(argc, argv);
	if (ft_check_if_sort(lista))
		return (0);
	else if (ft_size_listx(lista) == 2)
		algo_two(lista);
	else if (ft_size_listx(lista) == 3)
		algo_three(lista);
	else if (ft_size_listx(lista) >= 4 && ft_size_listx(lista) <= 5)
		algo_five(lista);
	else if (ft_size_listx(lista) > 5)
		algo_radix(lista);
	printf("la\n");
	ft_free_list(lista);
	return (0);
}
