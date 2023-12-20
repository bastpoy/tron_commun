/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:46:03 by bpoyet            #+#    #+#             */
/*   Updated: 2023/12/20 14:24:20 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
#define PUSH_SWAP

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf/ft_printf.h"

typedef struct s_stack
{
    int number;
    struct s_stack *next;
} t_stack;

typedef struct s_listx
{
    t_stack *ptrbegin;
} t_listx;

t_listx *ft_init_listx();
t_stack *ft_get_last(t_listx *listx);
int ft_print_listx(t_listx *list);
int ft_size_listx(t_listx *listx);
void ft_insert_front(t_listx *listx, int nb);
void ft_insert_back(t_listx *listx, int nb);
void ft_del_front(t_listx *listx);
void ft_del_back(t_listx *listx);
int ft_free_lista(t_listx *lista);
int ft_free_listb(t_listx *listb);

void ft_first_insert_listb(t_listx *lista, t_listx *listb);
void ft_second_insert_listb(t_listx *lista, t_listx *listb);
void ft_rrb_or_rb(int count, t_listx *lista, t_listx *listb);
int ft_count_rrb(t_listx *lista, t_listx *listb);
int ft_put_minmax_stacka(t_listx *lista, t_listx *listb);

int ft_sa(t_listx *lista);
int ft_sb(t_listx *listb);
int ft_ss(t_listx *lista, t_listx *listb);
int ft_pa(t_listx *lista, t_listx *listb);
int ft_pb(t_listx *lista, t_listx *listb);
int ft_ra(t_listx *lista);
int ft_rb(t_listx *listb);
int ft_rr(t_listx *lista, t_listx *listb);
int ft_rra(t_listx *lista);
int ft_rrb(t_listx *listb);
int ft_rrr(t_listx *lista, t_listx *listb);

#endif

// int ft_check_sup_duplic(int argc, char **argv)
// {
//     int i;
//     int j;

//     i = 1;
//     while (i <= argc - 1)
//     {
//         j = i + 1;
//         // if ((size_t)ft_atoi(argv[i]) > 2147483647 || (size_t)ft_atoi(argv[i]) < -2147483648)
//         //     return (0);
//         while (j <= argc - 1)
//         {
//             printf("i %s j %s\n", argv[i], argv[j]);
//             if (argv[i] == argv[j])
//                 return (0);
//             j++;
//         }
//         i++;
//     }
//     return (1);
// }