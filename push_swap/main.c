/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:24:21 by bpoyet            #+#    #+#             */
/*   Updated: 2023/12/19 16:07:28 by bpoyet           ###   ########.fr       */
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
        ft_printf("le numero vaut %d et le pointeur vaut %p\n", lista->ptrbegin->number, lista->ptrbegin);
        i--;
    }
}

int print_listx(t_listx *list)
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
    printf("\n\n");
    return (1);
}

int main(int argc, char **argv)
{
    // t_listx *lista;
    // t_listx *listb;

    if (argc == 1)
        return (0);
    if (!ft_check_if_num(argc, argv))
    {
        printf("pas bon\n");
        return (0);
    }
    // lista = ft_init_listx();
    // listb = ft_init_listx();
    // ft_fill_tab(argc, argv, lista);
    // ft_fill_tab(argc, argv, listb);
    // print_listx(lista);
    // print_listx(listb);

    // ft_rrr(lista, listb);
    // printf("---lista---\n");
    // print_listx(lista);
    // printf("---listb---\n");
    // print_listx(listb);

    // ft_rrr(lista, listb);
    // printf("---lista---\n");
    // print_listx(lista);
    // printf("---listb---\n");
    // print_listx(listb);

    // ft_free_lista(lista);
    // ft_free_listb(listb);
    // free(lista);
    // free(listb);
    return (0);
}