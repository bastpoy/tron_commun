/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:24:21 by bpoyet            #+#    #+#             */
/*   Updated: 2023/12/18 13:29:41 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

// fonction qui va trier mes nombres
// je check si ce sont tous des nombres
int ft_check_args(int argc, char **argv)
{
    int i;
    int j;

    i = argc - 1;
    printf("i vaut %d\n", i);
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

t_lista *ft_init_list()
{
    t_lista *lista;
    t_stacka *stacka;

    lista = malloc(sizeof(t_lista));
    stacka = malloc(sizeof(t_stacka));
    if(!lista || !stacka)
        return (NULL);
    stacka->number = 0;
    stacka->next = NULL;
    lista->ptrbegin = stacka;
    return(lista);
}

void ft_insert_front(t_lista *lista, int nb)
{
    t_stacka *stacka;

    stacka = malloc(sizeof(t_stacka));
    stacka->number = nb;
    stacka->next = lista->ptrbegin;
    lista->ptrbegin = stacka;
}

void ft_fill_tab(int argc, char **argv, t_lista *lista)
{
    int i;

    i = argc - 1;
    while(i > 0)
    {
        ft_insert_front(lista, ft_atoi(argv[i]));
        ft_printf("le numero vaut %d et le pointeur vaut %p et lista %p\n",lista->ptrbegin->number, lista->ptrbegin, lista);
        i--;
    }
}

int print_list(t_lista *list)
{
    if(!list)
        return (0);
    t_stacka *el;
    
    el = list->ptrbegin;
    printf("el vaut %p\n", el);
    while(!el)
    {
        ft_printf("l'element %d et son adresse %p\n", el->number, el);
        el = el->next;
    }
    return(1);
}

int main(int argc, char **argv)
{
    if (argc == 1)
        return (0);
    if (!ft_check_args(argc, argv))
        return (0);
    t_lista *lista;
    lista = ft_init_list();
    ft_fill_tab(argc, argv, lista);
    print_list(lista);
    ft_sa(lista);
    ft_printf("la\n");
    print_list(lista);
    return(0);
}