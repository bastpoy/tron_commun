/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:45:05 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/15 14:49:15 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->rightfork);

	pthread_mutex_lock(&philo->var->locktdead);
	if (philo->var->deadflag == 0 && checkmeal(philo))
	{
		printf("%ld %d has taken a fork\n", get_time() - philo->var->timestart,
			   philo->ranging);
	}
	pthread_mutex_unlock(&philo->var->locktdead);
}

static void take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->leftfork);
	pthread_mutex_lock(&philo->var->locktdead);
	if (philo->var->deadflag == 0 && checkmeal(philo))
	{
		printf("%ld %d has taken a fork\n", get_time() - philo->var->timestart,
			   philo->ranging);
	}
	pthread_mutex_unlock(&philo->var->locktdead);
}

void take_fork(t_philo *philo)
{
	// if (philo->ranging == philo->var->philonum)
	// {
	// 	take_left_fork(philo);
	// 	take_right_fork(philo);
	// }
	// else
	// {
	// 	// if (philo->ranging == 1 || philo->ranging == 3)
	// 	printf("%ld %d prendre la fork\n", get_time() - philo->var->timestart, philo->ranging);
	take_right_fork(philo);
	take_left_fork(philo);
	// }
}

void loose_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->leftfork);
	pthread_mutex_unlock(philo->rightfork);
	// printf(" %d unlock \n", philo->ranging);
}
