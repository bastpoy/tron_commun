/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:09:13 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/11 14:51:44 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void ft_sleep(int time)
{
    long int sleeptime;

    sleeptime = get_time();
    while (get_time() - sleeptime < time)
    {
        // printf("%d\n", time / 10);
        // usleep(time / 10);
        usleep(100);
    }
}
static void take_right_fork(t_philo *philo)
{
    pthread_mutex_lock(philo->rightfork);
    pthread_mutex_lock(&philo->var->locktdead);
    if (philo->var->deadflag == 0)
        printf("%ld %d has taken a fork\n", get_time() - philo->timestart, philo->ranging);
    pthread_mutex_unlock(&philo->var->locktdead);
}
static void take_left_fork(t_philo *philo)
{
    pthread_mutex_lock(philo->leftfork);
    pthread_mutex_lock(&philo->var->locktdead);
    if (philo->var->deadflag == 0)
        printf("%ld %d has taken a fork\n", get_time() - philo->timestart, philo->ranging);
    pthread_mutex_unlock(&philo->var->locktdead);
}

void take_fork(t_philo *philo)
{

    // je prends ma premiere fourchette
    if (philo->ranging % 2 == 1)
    {
        take_left_fork(philo);
        take_right_fork(philo);
    }
    else
    {
        take_right_fork(philo);
        take_left_fork(philo);
    }
    // printf("%d attend sa fourchette gauche\n", philo->ranging);
}

void loose_fork(t_philo *philo)
{
    // printf("%ld %d release fork\n", get_time() - philo->timestart, philo->ranging);
    pthread_mutex_unlock(philo->leftfork);
    pthread_mutex_unlock(philo->rightfork);
}