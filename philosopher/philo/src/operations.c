/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:09:13 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/12 17:54:59 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void ft_sleep(int time)
{
    long int sleeptime;

    sleeptime = get_time();
    while (get_time() - sleeptime < time)
        usleep(100);
}

void eating(t_philo *philo)
{
    pthread_mutex_lock(&philo->write);
    printf("%ld %d is eating\n", get_time() - philo->timestart, philo->ranging);
    pthread_mutex_unlock(&philo->write);
    pthread_mutex_lock(&philo->lock);
    philo->mealseat += 1;
    philo->timedead = get_time() + philo->ttd;
    pthread_mutex_unlock(&philo->lock);
    ft_sleep(philo->tte);
    // je repose mes fourchettes
    loose_fork(philo);
}
void sleeping(t_philo *philo)
{
    pthread_mutex_lock(&philo->write);
    printf("%ld %d is sleeping\n", get_time() - philo->timestart, philo->ranging);
    pthread_mutex_unlock(&philo->write);
    ft_sleep(philo->tts);
}

void thinking(t_philo *philo)
{
    pthread_mutex_lock(&philo->write);
    printf("%ld %d is thinking\n", get_time() - philo->timestart, philo->ranging);
    pthread_mutex_unlock(&philo->write);
}