/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:05:53 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/05 15:40:34 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int main(int argc, char *argv[])
{
    t_var var;

    if (!check_args(argv))
        return (0);
    if (argc == 5)
    {
        init_philo(argv, &var);
        do_routine(&var);
        pthread_mutex_destroy(&var.mutex);
        printf("good\n");
        return (0);
    }
    else if (argc == 6)
    {
        printf("good\n");
        return (0);
    }
    else
    {
        printf("Wrong number of arguments\n");
        return (0);
    }
}
