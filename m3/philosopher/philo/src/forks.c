/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:45:05 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/19 21:00:02 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->rightfork);
	if (deadflagstatus(philo) && checkmeal(philo))
	{
		pthread_mutex_lock(&philo->var->write);
		printf("%ld %d has taken a fork\n", get_time() - philo->var->timestart,
			   philo->ranging);
		pthread_mutex_unlock(&philo->var->write);
	}
}

static void take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->leftfork);
	if (deadflagstatus(philo) && checkmeal(philo))
	{
		pthread_mutex_lock(&philo->var->write);
		printf("%ld %d has taken a fork\n", get_time() - philo->var->timestart,
			   philo->ranging);
		pthread_mutex_unlock(&philo->var->write);
	}
}

void take_fork(t_philo *philo)
{
	// if (philo->ranging % 2 == 1)
	// {
	// 	take_left_fork(philo);
	// 	take_right_fork(philo);
	// }
	// else
	// {
	take_right_fork(philo);
	take_left_fork(philo);
	// }
}

void loose_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->leftfork);
	pthread_mutex_unlock(philo->rightfork);
}
