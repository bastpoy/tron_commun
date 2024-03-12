/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:05:53 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/12 17:02:03 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int main(int argc, char *argv[])
{
    t_var var;

    if (!check_args(argv))
        return (0);
    if (argc == 5 || argc == 6)
    {
        if (!init_philo(argv, &var))
            return (1);
        do_routine(&var);
        return (0);
    }
    else
    {
        printf("Wrong number of arguments\n");
        return (0);
    }
}
