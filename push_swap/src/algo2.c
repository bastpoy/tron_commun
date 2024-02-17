/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:13:00 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/17 17:29:06 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int ft_max_listx1(t_listx *listx, int *count)
{
    t_stack *stackx;
    int temp;

    *count = 0 stackx = listx->ptrbegin;
    if (!stackx)
        return (0);
    temp = stackx->number;
    while (stackx)
    {
        if (stackx->number > temp)
            temp = stackx->number;
        *count++;
        stackx = stackx->next;
    }
    return (temp);
}

int ft_min_listx1(t_listx *listx, int *count)
{
    t_stack *stackx;
    int temp;

    *count = 0;
    stackx = listx->ptrbegin;
    if (!stackx)
        return (0);
    temp = stackx->number;
    while (stackx)
    {
        if (stackx->number < temp)
            temp = stackx->number;
        *count++;
        stackx = stackx->next;
    }
    return (temp);
}

void sortedInsert(t_stack **head_ref, t_stack *new_node)
{
    t_stack *current;
    /* Special case for the head end */
    if (*head_ref == NULL || (*head_ref)->number >= new_node->number)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        current = *head_ref;
        while (current->next != NULL &&
               current->next->number < new_node->number)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void insertionSort(t_listx *list)
{
    t_stack *sorted = NULL;

    t_stack *current = list->ptrbegin;
    while (current != NULL)
    {
        t_stack *next = current->next;
        sortedInsert(&sorted, current);

        current = next;
    }
    list->ptrbegin = sorted;
}