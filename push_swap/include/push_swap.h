/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:46:03 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/17 17:18:17 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../ft_printf/ft_printf.h"
#include <stdlib.h>
#include "stdio.h"

typedef struct s_stack
{
	int number;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;

typedef struct s_listx
{
	t_stack *ptrbegin;
} t_listx;

typedef struct s_env
{
	int maxlista;
	int minlista;
	int gap;
	int mul;
} t_env;

int free_twodim(char **str);
int check_twoarg(char *str);
int check_max_int(char *arg);
int checkparam(int argc, char **argv);
int check(int argc, char **argv);

t_listx *ft_init_listx(void);
t_stack *ft_get_last(t_listx *listx);
int ft_print_listx(t_listx *list);
int ft_size_listx(t_listx *listx);
void ft_insert_front(t_listx *listx, int nb);
void ft_insert_back(t_listx *listx, int nb);
void ft_del_front(t_listx *listx);
void ft_del_back(t_listx *listx);
int ft_free_list(t_listx *lista);
int ft_max_listx(t_listx *listx);
int ft_min_listx(t_listx *listx);
int ft_getnumber_list(t_listx *listx, int min, int max);

int ft_check_if_sort(t_listx *lista);
void algo_two(t_listx *lista);
void algo_three(t_listx *lista);
void algo_five(t_listx *lista);
void algo_cent(t_listx *lista);
void algo_cinqcent(t_listx *lista);

void ft_first_insert_listb(t_listx *lista, t_listx *listb);
void ft_second_insert_listb(t_listx *lista, t_listx *listb);
void ft_rrb_or_rb(int count, t_listx *lista, t_listx *listb);
void ft_rra_or_ra(int count, t_listx *listb, t_listx *lista);
void ft_rra_ra_pb(int count, t_listx *listb, t_listx *lista);
int ft_count_rrb(t_listx *listb, t_listx *lista);
int ft_put_minmax_stack(t_listx *lista, t_listx *listb);
int ft_put_minmax_stack1(t_listx *listb, t_listx *lista);
int num_max_min(t_listx *lista, t_listx *listb);
int pb_filter(t_listx *lista, t_listx *listb);

int do_rb_rrb(t_listx *lista, t_listx *listb, int count, int i);
void do_rrb_rb(t_listx *lista, t_listx *listb, int count, int i);
int do_ra_rra(t_listx *lista, t_listx *listb, int count, int i);
void do_rra_ra(t_listx *lista, t_listx *listb, int count, int i);
int do_ra_filt_rra(t_listx *lista, t_listx *listb, int i,
				   int count);
void do_rra_filt_ra(t_listx *lista, t_listx *listb, int i,
					int count);
int min_max(t_stack *stacka, t_stack *stackb, t_listx *lista,
			t_listx *listb);

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

int ft_max_listx1(t_listx *listx, int *count);
int ft_min_listx1(t_listx *listx, int *count);

#endif
