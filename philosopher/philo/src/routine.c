/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:21:01 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/20 14:54:00 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int	checkallmeal(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->var->nomeat == 1)
		return (1);
	else
	{
		while (i < philo->var->philonum)
		{
			pthread_mutex_lock(&philo->var->philos[i].meal);
			if (philo->var->philos[i].mealseat < philo->var->mealstoeat)
			{
				pthread_mutex_unlock(&philo->var->philos[i].meal);
				return (1);
			}
			pthread_mutex_unlock(&philo->var->philos[i].meal);
			i++;
		}
	}
	return (0);
}

int	checkmeal(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->var->nomeat == 1)
		return (1);
	else
	{
		pthread_mutex_lock(&philo->meal);
		if (philo->mealseat < philo->var->mealstoeat)
		{
			pthread_mutex_unlock(&philo->meal);
			return (1);
		}
		else
		{
			pthread_mutex_unlock(&philo->meal);
			return (0);
		}
		i++;
	}
}

void	*checker(void *varptr)
{
	t_var	*var;
	int		i;

	i = 0;
	var = (t_var *)varptr;
	ft_sleep(var->philos[0].ttd + 1);
	while (var->deadflag == 0 && var->philonum != 1)
	{
		if (i == var->philonum)
			i = 0;
		pthread_mutex_lock(&var->philos[i].lock);
		if ((get_time() >= var->philos[i].timedead && var->deadflag == 0)
			|| !checkmeal(&var->philos[i]))
		{
			is_dead(var, i);
			pthread_mutex_unlock(&var->philos[i].lock);
			return (NULL);
		}
		pthread_mutex_unlock(&var->philos[i].lock);
		i++;
	}
	return (NULL);
}

void	*routine(void *philoptr)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)philoptr;
	pthread_mutex_lock(&philo->var->startmutex);
	pthread_mutex_unlock(&philo->var->startmutex);
	pthread_mutex_lock(&philo->lock);
	philo->timedead = get_time() + philo->ttd;
	pthread_mutex_unlock(&philo->lock);
	while (deadflagstatus(philo) && checkmeal(philo))
	{
		if (philo->var->philonum == 1)
			return (one_philo(philo));
		if (philo->ranging % 2 == 1 && i == 0)
			ft_sleep(philo->tte / 10);
		i = 1;
		take_fork(philo);
		eating(philo);
		thinking(philo);
	}
	return (NULL);
}

int	do_routine(t_var *var)
{
	int	i;

	i = 0;
	if (pthread_create(&var->checker, NULL, checker, (void *)var) != 0)
		return (1);
	pthread_mutex_lock(&var->startmutex);
	while (i < var->philonum)
	{
		if (pthread_create(&var->philos[i].thread, NULL, routine,
				(void *)&var->philos[i]) != 0)
			return (1);
		i++;
	}
	var->timestart = get_time();
	pthread_mutex_unlock(&var->startmutex);
	destroy_mutex(var);
	return (0);
}
