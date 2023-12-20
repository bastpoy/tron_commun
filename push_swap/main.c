/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:24:21 by bpoyet            #+#    #+#             */
/*   Updated: 2023/12/20 15:41:35 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_if_num(int argc, char **argv)
{
    int i;
    int j;

    i = argc - 1;
    j = 0;
    while (i > 0)
    {
        while (argv[i][j])
        {
            if (argv[i][j] < '0' || argv[i][j] > '9')
                return (0);
            j++;
        }
        j = 0;
        i--;
    }
    return (1);
}

void ft_fill_tab(int argc, char **argv, t_listx *lista)
{
    int i;

    i = argc - 1;
    while (i > 0)
    {
        ft_insert_front(lista, ft_atoi(argv[i]));
        i--;
    }
}

int main(int argc, char **argv)
{
    t_listx *lista;
    t_listx *listb;
    int count;

    if (argc == 1)
        return (0);
    if (!ft_check_if_num(argc, argv))
    {
        printf("pas bon\n");
        return (0);
    }
    lista = ft_init_listx();
    listb = ft_init_listx();
    ft_fill_tab(argc, argv, lista);

    ft_first_insert_listb(lista, listb);
    ft_second_insert_listb(lista, listb);

    while (lista->ptrbegin)
    {
        if (!ft_put_minmax_stacka(lista, listb))
        {
            count = ft_count_rrb(lista, listb);
            ft_rrb_or_rb(count, lista, listb);
        }
    }
    while (listb->ptrbegin)
    {
        ft_pa(lista, listb);
    }
    return (0);
}
