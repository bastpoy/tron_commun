/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:09:13 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/20 14:54:18 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void	ft_sleep(int time)
{
	long int	sleeptime;

	sleeptime = get_time();
	while (get_time() - sleeptime < time)
		usleep(100);
}

void	eating(t_philo *philo)
{
	if (deadflagstatus(philo) && checkmeal(philo))
	{
		pthread_mutex_lock(&philo->var->write);
		printf("%ld %d is eating\n", get_time() - philo->var->timestart,
			philo->ranging);
		pthread_mutex_unlock(&philo->var->write);
	}
	pthread_mutex_lock(&philo->lock);
	philo->timedead = get_time() + philo->ttd;
	pthread_mutex_unlock(&philo->lock);
	ft_sleep(philo->tte);
	loose_fork(philo);
	pthread_mutex_lock(&philo->meal);
	philo->mealseat += 1;
	pthread_mutex_unlock(&philo->meal);
	if (deadflagstatus(philo))
	{
		pthread_mutex_lock(&philo->var->write);
		printf("%ld %d is sleeping\n", get_time() - philo->var->timestart,
			philo->ranging);
		pthread_mutex_unlock(&philo->var->write);
	}
	if (deadflagstatus(philo) && checkallmeal(philo))
		ft_sleep(philo->tts);
}

void	thinking(t_philo *philo)
{
	if (deadflagstatus(philo) && checkallmeal(philo))
	{
		pthread_mutex_lock(&philo->var->write);
		printf("%ld %d is thinking\n", get_time() - philo->var->timestart,
			philo->ranging);
		pthread_mutex_unlock(&philo->var->write);
	}
}

int	deadflagstatus(t_philo *philo)
{
	pthread_mutex_lock(&philo->var->locktdead);
	if (philo->var->deadflag == 0)
	{
		pthread_mutex_unlock(&philo->var->locktdead);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&philo->var->locktdead);
		return (0);
	}
}
