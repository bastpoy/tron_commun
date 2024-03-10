/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:21:01 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/10 23:55:51 by bpoyet           ###   ########.fr       */
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
    while (philo->var->deadflag == 0)
    {
        pthread_mutex_lock(&philo->lock);
        if (get_time() >= philo->timedead)
        {
            pthread_mutex_lock(&philo->var->locktdead);
            philo->var->deadflag = 1;
            pthread_mutex_unlock(&philo->var->locktdead);
            printf("%ld %d died\n", get_time() - philo->timestart, philo->ranging);
        }
        pthread_mutex_unlock(&philo->lock);
    }
    return (NULL);
}

void *routine(void *philoptr)
{
    t_philo *philo;
    int i = 0;

    philo = (t_philo *)philoptr;
    philo->timestart = get_time();
    philo->timedead = philo->timestart + philo->ttd;
    pthread_create(&philo->checker, NULL, checker, (void *)philo);
    while (philo->var->deadflag == 0)
    {
        // Pour le premier tour de boucle je fais sleep les impaires pour eviter une deadlock
        if (philo->ranging % 2 == 1 && i == 0)
            ft_sleep(2);
        // Je prends les fourchettes
        take_fork(philo);
        // je mange et je met sa jour ma variable de temps de die
        pthread_mutex_lock(&philo->var->locktdead);
        if (philo->var->deadflag == 1)
            pthread_mutex_unlock(&philo->var->locktdead);
        else
        {
            printf("%ld %d is eating\n", get_time() - philo->timestart, philo->ranging);
            pthread_mutex_lock(&philo->lock);
            philo->timedead = get_time() + philo->ttd;
            pthread_mutex_unlock(&philo->lock);
            pthread_mutex_unlock(&philo->var->locktdead);
            ft_sleep(philo->tte);
            // je repose mes fourchettes
            loose_fork(philo);
        }
        // je sleep
        pthread_mutex_lock(&philo->var->locktdead);
        if (philo->var->deadflag == 1)
            pthread_mutex_unlock(&philo->var->locktdead);
        else
        {
            printf("%ld %d is sleeping\n", get_time() - philo->timestart, philo->ranging);
            pthread_mutex_unlock(&philo->var->locktdead);
            // je dors le temps du sleep
            ft_sleep(philo->tts);
        }
        // printf("je sors jamais\n");
        // je pense mais si seulement si je suis toujours vivant
        pthread_mutex_lock(&philo->var->locktdead);
        if (philo->var->deadflag == 1)
            pthread_mutex_unlock(&philo->var->locktdead);
        else
        {
            printf("%ld %d is thinking\n", get_time() - philo->timestart, philo->ranging);
            pthread_mutex_unlock(&philo->var->locktdead);
        }
        i = 1;
    }
    pthread_join(philo->checker, NULL);
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
        pthread_mutex_destroy(&var->philos[i].lock);
        i++;
    }
    pthread_mutex_destroy(&var->locktdead);
    return (0);
}