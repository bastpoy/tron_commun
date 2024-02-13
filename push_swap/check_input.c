/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:32:00 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/13 18:15:56 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_input(char *str)
{
    char **tab;
    int i;
    int j;

    i = 0;
    tab = ft_split(str, ' ');
    while (tab[i])
    {
        j = i - 1;
        if (!ft_atoi(tab[i]))
            return (0);
        while (j >= 0)
        {
            if (ft_atoi(tab[i]) == ft_atoi(tab[j]))
                return (0);
            i--;
        }
        i++;
    }
    free(tab);
    return (1);
}
