/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:04:47 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/14 18:16:15 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_if_sort(t_listx *lista)
{
    t_stack *stacka;

    stacka = lista->ptrbegin;
    while (stacka != NULL)
    {
        if (stacka->next)
        {
            if (stacka->number > stacka->next->number)
                return (0);
        }
        stacka = stacka->next;
    }
    return (1);
}

void algo_two(t_listx *lista)
{
    t_stack *stacka;

    stacka = lista->ptrbegin;

    if (stacka->number > stacka->next->number)
        ft_ra(lista);
    // ft_print_listx(lista);
}

void algo_three(t_listx *lista)
{
    t_stack *first;
    int second;
    int third;

    first = lista->ptrbegin;
    second = first->next->number;
    third = first->next->next->number;
    if (first->number > second && second > third)
    {
        ft_sa(lista);
        ft_rra(lista);
    }
    else if (second > third && third > first->number)
    {
        ft_sa(lista);
        ft_ra(lista);
    }
    else if (first->number > third && third > second)
        ft_ra(lista);
    else if (third > first->number && first->number > second)
        ft_sa(lista);
    else if (second > first->number && first->number > third)
        ft_rra(lista);
    // ft_print_listx(lista);
}

void algo_five(t_listx *lista)
{
    int count;
    t_listx *listb;

    listb = ft_init_listx();
    ft_pb(lista, listb);
    ft_pb(lista, listb);
    algo_three(lista);

    if (!ft_put_minmax_stack1(listb, lista))
    {
        count = ft_count_rrb(listb, lista);
        ft_rrb_or_rb1(count, listb, lista);
    }
    if (!ft_put_minmax_stack1(listb, lista))
    {
        count = ft_count_rrb(listb, lista);
        ft_rrb_or_rb1(count, listb, lista);
    }
    // ft_print_listx(lista);
    ft_free_listb(listb);
}

void algo_cent(t_listx *lista)
{
    int count;
    t_listx *listb;

    count = 0;
    listb = ft_init_listx();
    ft_first_insert_listb(lista, listb);
    ft_second_insert_listb(lista, listb);
    while (lista->ptrbegin)
    {
        if (!ft_put_minmax_stack(lista, listb))
        {
            count = ft_count_rra(lista, listb);
            ft_rrb_or_rb(count, lista, listb);
        }
    }
    while (listb->ptrbegin)
    {
        ft_pa(lista, listb);
    }
    ft_free_listb(listb);
}

void algo_cent1(t_listx *lista)
{
    t_stack *stacka;
    // t_listx *listb;

    int maxlista;
    int minlista;
    int gap;
    int mul;
    int i = 0;

    maxlista = ft_max_listx(lista);
    minlista = ft_min_listx(lista);
    gap = (maxlista - minlista) / 5;
    mul = 0;
    stacka = lista->ptrbegin;
    printf("max %d min %d gap %d\n", maxlista, minlista, gap);
    while (stacka && mul <= 4)
    {
        if (ft_getnumber_list(stacka, minlista + (gap * mul), (mul * gap) + gap + minlista))
        {
            printf("le nombre vaut %d et min %d et max %d \n", stacka->number, mul * gap, (mul * gap) + gap);
            ft_pb()
        }
        else
            mul++;
        i++;
    }
    printf("%d\n", i);
}
