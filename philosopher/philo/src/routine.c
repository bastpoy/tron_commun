/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:21:01 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/11 18:02:52 by bpoyet           ###   ########.fr       */
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
    ft_sleep(philo->ttd + 1);
    // while (philo->var->deadflag == 0)
    // {
    pthread_mutex_lock(&philo->lock);
    if (get_time() >= philo->timedead && philo->var->deadflag == 0)
    {
        pthread_mutex_lock(&philo->var->locktdead);
        philo->var->deadflag = 1;
        pthread_mutex_unlock(&philo->var->locktdead);
        pthread_mutex_lock(&philo->write);
        printf("%ld %d died\n", get_time() - philo->timestart, philo->ranging);
        pthread_mutex_unlock(&philo->write);
    }
    pthread_mutex_unlock(&philo->lock);
    // }
    // ft_sleep(1);
    return (NULL);
}

void *routine(void *philoptr)
{
    t_philo *philo;
    int i = 0;

    philo = (t_philo *)philoptr;
    while (philo->var->deadflag == 0)
    {
        // Pour le premier tour de boucle je fais sleep les impaires pour eviter une deadlock
        if (philo->ranging % 2 == 1 && i == 0)
        {
            ft_sleep(philo->tte / 10);
        }
        pthread_create(&philo->checker, NULL, checker, (void *)philo);
        // Je prends les fourchettes
        take_fork(philo);
        // je mange et je met sa jour ma variable de temps de die
        // pthread_mutex_lock(&philo->var->locktdead);
        // if (philo->var->deadflag == 1)
        //     pthread_mutex_unlock(&philo->var->locktdead);
        // else
        // checker(philo);
        if (philo->var->deadflag == 0)
        {
            pthread_mutex_lock(&philo->write);
            printf("%ld %d is eating\n", get_time() - philo->timestart, philo->ranging);
            pthread_mutex_unlock(&philo->write);
            pthread_mutex_lock(&philo->lock);
            philo->timedead = get_time() + philo->ttd;
            pthread_mutex_unlock(&philo->lock);
            ft_sleep(philo->tte);
            // je repose mes fourchettes
            loose_fork(philo);
        }
        // je sleep
        // pthread_mutex_lock(&philo->var->locktdead);
        // if (philo->var->deadflag == 1)
        //     pthread_mutex_unlock(&philo->var->locktdead);
        // else
        // pthread_create(&philo->checker, NULL, checker, (void *)philo);
        // checker(philo);
        if (philo->var->deadflag == 0)
        {
            pthread_mutex_lock(&philo->write);
            printf("%ld %d is sleeping\n", get_time() - philo->timestart, philo->ranging);
            pthread_mutex_unlock(&philo->write);
            // je dors le temps du sleep
            ft_sleep(philo->tts);
        }
        // je pense mais si seulement si je suis toujours vivant
        // pthread_mutex_lock(&philo->var->locktdead);
        // if (philo->var->deadflag == 1)
        //     pthread_mutex_unlock(&philo->var->locktdead);
        // else
        // checker(philo);
        if (philo->var->deadflag == 0)
        {
            pthread_mutex_lock(&philo->write);
            printf("%ld %d is thinking\n", get_time() - philo->timestart, philo->ranging);
            pthread_mutex_unlock(&philo->write);
        }
        pthread_detach(philo->checker);
        i = 1;
    }
    // pthread_join(philo->checker, NULL);
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