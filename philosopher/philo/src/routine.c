/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:21:01 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/12 18:05:08 by bpoyet           ###   ########.fr       */
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

void *checker(void *philoptr)
{
    t_philo *philo;

    philo = (t_philo *)philoptr;
    // je sleep le temps de
    ft_sleep(philo->ttd + 1);
    pthread_mutex_lock(&philo->lock);
    if (get_time() >= philo->timedead && philo->var->deadflag == 0 &&
        philo->mealseat < philo->var->mealstoeat)
    {
        pthread_mutex_lock(&philo->var->locktdead);
        philo->var->deadflag = 1;
        pthread_mutex_unlock(&philo->var->locktdead);
        pthread_mutex_lock(&philo->write);
        printf("%ld %d died\n", get_time() - philo->timestart, philo->ranging);
        pthread_mutex_unlock(&philo->write);
    }
    pthread_mutex_unlock(&philo->lock);
    return (NULL);
}

void *routine(void *philoptr)
{
    t_philo *philo;
    int i = 0;

    philo = (t_philo *)philoptr;
    while (philo->var->deadflag == 0 && philo->mealseat < philo->var->mealstoeat)
    {
        if (philo->ranging % 2 == 1 && i == 0)
            ft_sleep(philo->tte / 10);
        i = 1;
        if (pthread_create(&philo->checker, NULL, checker, (void *)philo) != 0)
            return ((void *)1);
        take_fork(philo);
        if (philo->var->deadflag == 0 && philo->mealseat < philo->var->mealstoeat)
            eating(philo);
        if (philo->var->deadflag == 0 && philo->mealseat < philo->var->mealstoeat)
            sleeping(philo);
        if (philo->var->deadflag == 0 && philo->mealseat < philo->var->mealstoeat)
            thinking(philo);
        if (pthread_detach(philo->checker) != 0)
            return ((void *)1);
    }
    return (NULL);
}

int do_routine(t_var *var)
{
    int i;

    i = 0;
    while (i < var->philonum)
    {
        var->philos[i].timestart = get_time();
        var->philos[i].timedead = get_time() + var->philos->ttd;
        pthread_create(&var->philos[i].thread, NULL, routine, (void *)&var->philos[i]);
        // ft_sleep(1);
        i++;
    }
    i = 0;
    while (i < var->philonum)
    {
        pthread_join(var->philos[i].thread, NULL);
        pthread_mutex_destroy(var->philos[i].leftfork);
        pthread_mutex_destroy(&var->philos[i].lock);
        pthread_mutex_destroy(&var->philos[i].write);
        i++;
    }
    pthread_mutex_destroy(&var->locktdead);
    return (0);
}