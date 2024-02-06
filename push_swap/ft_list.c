/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:36:41 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/06 16:28:40 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_listx *ft_init_listx()
{
    t_listx *lista;

    lista = malloc(sizeof(t_listx));
    lista->ptrbegin = NULL;
    return (lista);
}

int ft_print_listx(t_listx *list)
{
    if (!list)
        return (0);
    t_stack *el;

    el = list->ptrbegin;
    while (el)
    {
        ft_printf("valeur %d adresse %p\n", el->number, el);
        el = el->next;
    }
    printf("\n");
    return (1);
}

int ft_size_listx(t_listx *listx)
{
    t_stack *stackx;
    int count;

    count = 0;
    stackx = listx->ptrbegin;
    while (stackx != NULL)
    {
        stackx = stackx->next;
        count++;
    }
    return (count);
}

void ft_insert_front(t_listx *listx, int nb)
{
    t_stack *stackx;

    stackx = malloc(sizeof(t_stack));
    stackx->number = nb;
    stackx->next = listx->ptrbegin;
    listx->ptrbegin = stackx;
}

void ft_insert_back(t_listx *listx, int nb)
{
    t_stack *stackx;

    stackx = ft_get_last(listx);
    stackx->next = malloc(sizeof(t_stack));
    stackx->next->number = nb;
    stackx->next->next = NULL;
}

void ft_del_front(t_listx *listx)
{
    t_stack *el;

    if (!listx)
        ft_printf("cant free NULL ptr");
    el = listx->ptrbegin;
    listx->ptrbegin = listx->ptrbegin->next;
    free(el);
}

void ft_del_back(t_listx *listx)
{
    t_stack *current;
    t_stack *previous;

    current = listx->ptrbegin;
    previous = NULL;
    if (listx == NULL || listx->ptrbegin == NULL || listx->ptrbegin->next == NULL)
    {
        // Empty list or list with only one element
        printf("je ne peux pas avoir l'avant dernier\n");
    }
    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }
    previous->next = NULL;
    free(current);
}

int ft_free_lista(t_listx *lista)
{
    t_stack *stacka;
    t_stack *tmp;

    stacka = lista->ptrbegin;
    if (!lista)
        return (0);
    while (stacka != NULL)
    {
        tmp = stacka;
        stacka = stacka->next;
        free(tmp);
    }
    return (1);
}

int ft_free_listb(t_listx *listb)
{
    t_stack *stackb;
    t_stack *tmp;

    stackb = listb->ptrbegin;
    if (!listb)
        return (0);
    while (stackb != NULL)
    {
        tmp = stackb;
        stackb = stackb->next;
        free(tmp);
    }
    return (1);
}

t_stack *ft_get_last(t_listx *listx)
{
    t_stack *stackx;

    stackx = listx->ptrbegin;
    while (stackx)
    {
        if (stackx->next == NULL)
            return (stackx);
        else
            stackx = stackx->next;
    }
    return (stackx);
}
