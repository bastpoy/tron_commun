/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:21:01 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/05 18:00:37 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int get_time()
{
    // struct timeval tv;

    // long int tnow;
    // if (gettimeofday(&tv, NULL) == -1)
    //     return (1);
    // if (start == 1)
    // {
    //     philo->tstart = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
    // }
    // else
    // {
    //     tnow = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
    //     philo->tpasses = tnow - philo->tstart;
    // }
    // return (0);
    struct timeval tv;

    if (gettimeofday(&tv, NULL) == -1)
        return (1);
    return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}

void *routine(void *philoptr)
{
    t_philo *philo;

    philo = (t_philo *)philoptr;
    // avant de commencer il faut stocker son ttd
    philo->ttd = get_time() + philo->var->ttdin;
    get_time(philo);
    usleep(1000000);
    while (philo->dead = 0)
    {
        // si je peux manger
        // je lock la fork a droite
        // je lock la fork a gauche
        // je eat
        // je delock
        // si je peux pas manger je dors ou je pense
    }
    printf("ranging %d\n", philo->ranging);
    printf("salut le thread\n");
    return (NULL);
}

int do_routine(t_var *var)
{
    int i;

    i = 0;
    while (i < var->philonum)
    {
        pthread_create(&var->philo[i].thread, NULL, routine, (void *)&var->philo[i]);
        i++;
    }
    i = 0;
    while (i < var->philonum)
    {
        pthread_join(var->philo[i].thread, NULL);
        i++;
    }
    return (0);
}