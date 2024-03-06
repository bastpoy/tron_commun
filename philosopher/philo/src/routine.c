/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:21:01 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/06 17:50:25 by bpoyet           ###   ########.fr       */
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
    int i;
    int time;

    i = 0;
    time = 0;
    philo = (t_philo *)philoptr;
    // avant de commencer il faut stocker son ttd
    philo->timestart = get_time();
    philo->timedead = philo->timestart + philo->ttd;
    // usleep(1000000);
    while (i < 5 && philo->var->deadflag == 0)
    {
        time += philo->tte;
        pthread_mutex_lock(philo->rightfork);
        pthread_mutex_lock(philo->leftfork);
        philo->timedead = get_time() + philo->ttd;
        printf("%ld %d is eating\n", get_time() - philo->timestart, philo->ranging);
        usleep(philo->tte * 1000);
        pthread_mutex_unlock(philo->rightfork);
        pthread_mutex_unlock(philo->leftfork);
        printf("%ld %d is thinking\n", get_time() - philo->timestart, philo->ranging);
        i++;
    }
    printf("\n\n");
    philo->var->deadflag = 1;
    printf("%ld %d is dead\n", get_time() - philo->timestart, philo->ranging);
    return (NULL);
}

int do_routine(t_var *var)
{
    int i;

    i = 0;
    while (i < var->philonum)
    {
        pthread_create(&var->philos[i].thread, NULL, routine, (void *)&var->philos[i]);
        i++;
    }
    i = 0;
    while (i < var->philonum)
    {
        pthread_join(var->philos[i].thread, NULL);
        i++;
    }
    return (0);
}