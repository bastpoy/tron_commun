/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:24:21 by bpoyet            #+#    #+#             */
/*   Updated: 2023/12/11 20:43:53 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include "libft/libft.h"

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
t_stacka ft_fill_tab(int argc, char **argv)
{



        
        
        
        }

int main(int argc, char **argv)
{
    if (argc == 1)
        return (0);
    if (!ft_check_args(argc, argv))
        return (0);
}
