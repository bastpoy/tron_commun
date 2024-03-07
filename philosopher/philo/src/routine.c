/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:21:01 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/07 12:45:03 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

long int get_time()
{
    struct timeval tv;

    if (gettimeofday(&tv, NULL) == -1)
        return (-1);
    return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}

void *routine(void *philoptr)
{
    t_philo *philo;

    philo = (t_philo *)philoptr;
    philo->timestart = get_time();
    philo->timedead = philo->timestart + philo->ttd;
    // printf("%ld philo time dead\n", philo->timedead);
    while (philo->var->deadflag == 0)
    {
        // printf("philo %d leftfork %p rightfork %p\n", philo->ranging, philo->leftfork, philo->rightfork);
        pthread_mutex_lock(philo->rightfork);
        pthread_mutex_lock(philo->leftfork);
        if (philo->var->deadflag == 0)
        {
            if (get_time() >= philo->timedead)
            {
                pthread_mutex_lock(philo->var->lock);
                philo->var->deadflag = 1;
                pthread_mutex_unlock(philo->var->lock);
                printf("%ld %d is dead\n", get_time() - philo->timestart, philo->ranging);
            }
            else
            {
                philo->timedead = get_time() + philo->ttd;
                // printf("dead var %d\n", philo->var->deadflag);
                printf("%ld %d is eating\n", get_time() - philo->timestart, philo->ranging);
                usleep(philo->tte * 1000);
                printf("%ld %d is thinking\n", get_time() - philo->timestart, philo->ranging);
            }
        }
        pthread_mutex_unlock(philo->leftfork);
        pthread_mutex_unlock(philo->rightfork);
    }
    printf("\n\n");
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
        pthread_mutex_destroy(var->philos[i].leftfork);
        i++;
    }
    pthread_mutex_destroy(var->lock);
    return (0);
}