/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:21:01 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/15 15:27:17 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int checkmeal(t_philo *philo)
{
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
	}
}

int deadflagstatus(t_philo *philo)
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

void *checker(void *varptr)
{
	t_var *var;
	int i;

	i = 0;
	var = (t_var *)varptr;
	ft_sleep(var->philos[0].ttd + 1);
	while (var->deadflag == 0 && var->philonum != 1)
	{
		if (i == var->philonum)
			i = 0;
		pthread_mutex_lock(&var->philos[i].lock);
		if ((get_time() >= var->philos[i].timedead && var->deadflag == 0) ||
			!checkmeal(&var->philos[i]))
		{
			is_dead(var, i);
			return (NULL);
		}
		pthread_mutex_unlock(&var->philos[i].lock);
		i++;
	}
	return (NULL);
}

void *routine(void *philoptr)
{
	t_philo *philo;
	int i;

	i = 0;
	philo = (t_philo *)philoptr;
	philo->timedead = get_time() + philo->ttd;
	while (deadflagstatus(philo) && checkmeal(philo))
	{
		if (philo->var->philonum == 1)
			return (one_philo(philo));
		if (philo->ranging % 2 == 1 && i == 0)
			ft_sleep(philo->tte / 10);
		i = 1;
		take_fork(philo);
		if (deadflagstatus(philo) && checkmeal(philo))
			eating(philo);
		if (deadflagstatus(philo) && checkmeal(philo))
			sleeping(philo);
		if (deadflagstatus(philo) && checkmeal(philo))
			thinking(philo);
		if (!deadflagstatus(philo))
			loose_fork(philo);
	}
	return (NULL);
}

int do_routine(t_var *var)
{
	int i;

	i = 0;
	var->timestart = get_time();
	if (pthread_create(&var->checker, NULL, checker, (void *)var) != 0)
		return (1);
	while (i < var->philonum)
	{
		if (pthread_create(&var->philos[i].thread, NULL, routine,
						   (void *)&var->philos[i]) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < var->philonum)
	{
		if (pthread_join(var->philos[i].thread, NULL) != 0)
			return (1);
		pthread_mutex_destroy(var->philos[i].leftfork);
		pthread_mutex_destroy(&var->philos[i].lock);
		pthread_mutex_destroy(&var->philos[i].meal);
		i++;
	}
	if (pthread_join(var->checker, NULL))
		return (0);
	pthread_mutex_destroy(&var->locktdead);
	pthread_mutex_destroy(&var->write);
	return (0);
}
