/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:46:03 by bpoyet            #+#    #+#             */
/*   Updated: 2023/12/11 20:34:59 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
#define PUSH_SWAP

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

int main(int argc, char **argv);

#endif