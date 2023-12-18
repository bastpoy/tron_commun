/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:46:03 by bpoyet            #+#    #+#             */
/*   Updated: 2023/12/18 13:24:11 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
#define PUSH_SWAP

#include <stdlib.h>
#include <stdio.h>

typedef struct s_stacka
{
    int number;
    struct s_stacka *next;
} t_stacka;

typedef struct s_stackb
{
    int number;
    struct s_stacka *next;
} t_stackb;

typedef struct s_lista
{
    t_stacka *ptrbegin;
} t_lista;

typedef struct s_listb
{
    t_stackb *ptrbegin;
} t_listb;

void ft_sa(t_lista *lista);

#endif