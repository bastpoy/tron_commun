/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:08:47 by bpoyet            #+#    #+#             */
/*   Updated: 2024/01/29 23:15:31 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// premiere insertition dans b
void ft_first_insert_listb(t_listx *lista, t_listx *listb)
{
    t_stack *stackb;

    stackb = listb->ptrbegin;
    if (!stackb)
    {
        ft_pb(lista, listb);
    }
}

// deuxieme insertion dans b
void ft_second_insert_listb(t_listx *lista, t_listx *listb)
{
    t_stack *stackb;

    stackb = listb->ptrbegin;
    if (!stackb->next)
    {
        ft_pb(lista, listb);
        stackb = listb->ptrbegin;
        if (stackb->number < stackb->next->number)
            ft_sb(listb);
    }
}

// hypothese que le nombre que je renvoie est en haut de la pile
int ft_count_rrb(t_listx *lista, t_listx *listb)
{
    t_stack *stacka;
    t_stack *stackb;
    int count;

    stacka = lista->ptrbegin;
    stackb = listb->ptrbegin;
    count = 1;
    // je compare stack a avec la liste b
    while (stackb && stackb->next)
    {
        if (stacka->number < stackb->number &&
            stacka->number > stackb->next->number)
        {
            printf("count %d\n", count);
            return (count);
        }
        count++;
        stackb = stackb->next;
    }
    return (1);
}

int ft_count_rrb1(t_listx *listb, t_listx *lista)
{
    t_stack *stackb;
    t_stack *stacka;
    int count;

    stackb = listb->ptrbegin;
    stacka = lista->ptrbegin;
    count = 1;
    // je compare stack a avec la liste b
    while (stacka && stacka->next)
    {
        if (stackb->number > stacka->number &&
            stackb->number < stacka->next->number)
        {
            printf("count %d\n", count);
            return (count);
        }
        count++;
        stacka = stacka->next;
    }
    return (1);
}

// je calcule combien de fois je dois faire de rrb pour arriver caller mon nombre
// Suivant le nombre de fois je fais rrb ou rb
// Je calle mon nombre
// Je refais le meme nombre de rb ou rrb pour recaller ma pile
void ft_rrb_or_rb(int count, t_listx *lista, t_listx *listb)
{
    int i;
    int sizeb;

    i = 0;
    sizeb = ft_size_listx(listb);
    // si mon count rrb est superieur a la moitie de mes sizeb
    if (count <= (sizeb) / 2)
    {
        // je decalle de rb du nombre sizeb - 1 - count
        while (i != count)
        {
            ft_rb(listb);
            i++;
        }
        // je passe l'indice dedans
        ft_pb(lista, listb);
        // je me recalle du nombre de rb
        while (i != 0)
        {
            ft_rrb(listb);
            i--;
        }
    }
    else
    {
        while (i != (sizeb)-count)
        {
            ft_rrb(listb);
            i++;
        }
        ft_pb(lista, listb);
        while (i != 0)
        {
            ft_rb(listb);
            i--;
        }
    }
}

void ft_rrb_or_rb1(int count, t_listx *listb, t_listx *lista)
{
    int i;
    int sizea;

    i = 0;
    sizea = ft_size_listx(lista);
    printf("sizea %d count %d\n", sizea, count);
    // si mon count rrb est superieur a la moitie de mes sizea
    if (count <= (sizea) / 2)
    {
        printf("salut\n");
        // je decalle de rb du nombre sizea - 1 - count
        while (i != count)
        {
            ft_rra(lista);
            i++;
        }
        // je passe l'indice dedans
        ft_pa(listb, lista);
        // je me recalle du nombre de rb
        while (i != 0)
        {
            ft_ra(lista);
            i--;
        }
    }
    else
    {
        while (i != (sizea)-count)
        {
            ft_ra(lista);
            i++;
        }
        ft_pa(listb, lista);
        while (i != 0)
        {
            ft_rra(lista);
            i--;
        }
    }
}

// fonction qui prend le max de b et le compare avec a
// le met dans la stack si a > maxb
// fonction qui prend le min de b et le compare avec a
// le met dans la stack si a < minb
int ft_put_minmax_stack(t_listx *lista, t_listx *listb)
{
    t_stack *stacka;
    t_stack *stackb;
    t_stack *temp;

    stacka = lista->ptrbegin;
    stackb = listb->ptrbegin;
    temp = ft_get_last(listb);
    if (stacka->number > stackb->number)
    {
        ft_pb(lista, listb);
        return (1);
    }
    else if (stacka->number < temp->number)
    {
        ft_pb(lista, listb);
        ft_rb(listb);
        return (1);
    }
    else
    {
        printf("la\n");
        return (0);
    }
}

int ft_put_minmax_stack1(t_listx *listb, t_listx *lista)
{
    t_stack *stackb;
    t_stack *stacka;
    t_stack *temp;

    stackb = listb->ptrbegin;
    stacka = lista->ptrbegin;
    temp = ft_get_last(lista);
    if (stackb->number < stacka->number)
    {
        ft_pa(lista, listb);
        return (1);
    }
    else if (stackb->number > temp->number)
    {
        ft_pa(lista, listb);
        ft_ra(lista);
        return (1);
    }
    else
    {
        return (0);
    }
}

// je trie avec un stack de 3 nombres
void ft_sort_threenbr(t_listx *list)
{
    t_stack *first;
    int second;
    int third;

    first = list->ptrbegin;
    second = first->next->number;
    third = first->next->next->number;
    if (first->number > second && second > third)
    {
        ft_sa(list);
        ft_rra(list);
    }
    else if (second > third && third > first->number)
    {
        ft_sa(list);
        ft_ra(list);
    }
    else if (first->number > third && third > second)
        ft_ra(list);
    else if (third > first->number && first->number > second)
        ft_sa(list);
    else if (second > first->number && first->number > third)
        ft_rra(list);
}
