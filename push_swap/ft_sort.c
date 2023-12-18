/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:07:28 by bpoyet            #+#    #+#             */
/*   Updated: 2023/12/18 13:31:38 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sa(t_lista *lista)
{
	int tmp;

	tmp = lista->ptrbegin->number;
	lista->ptrbegin->number = lista->ptrbegin->next->number;
	lista->ptrbegin->next->number = tmp;
	printf("tmp %d lista->ptrbegin->number %d lista->ptrbegin->next->number %d\n", tmp, lista->ptrbegin->number, lista->ptrbegin->next->number);
}