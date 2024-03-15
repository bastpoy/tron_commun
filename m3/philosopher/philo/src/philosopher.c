/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:05:53 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/15 15:26:22 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

long int get_time(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}

void *one_philo(t_philo *philo)
{
	take_right_fork(philo);
	pthread_mutex_lock(&philo->var->write);
	printf("%ld %d died\n", get_time() - philo->var->timestart, philo->ranging);
	pthread_mutex_unlock(&philo->var->write);
	return (NULL);
}
void is_dead(t_var *var, int i)
{
	pthread_mutex_lock(&var->locktdead);
	if (checkmeal(&var->philos[i]))
		var->deadflag = 1;
	pthread_mutex_unlock(&var->locktdead);
	pthread_mutex_lock(&var->write);
	if (checkmeal(&var->philos[i]))
		printf("%ld %d died\n", get_time() - var->timestart, var->philos[i].ranging);
	pthread_mutex_unlock(&var->write);
}

int main(int argc, char *argv[])
{
	t_var var;

	if (!check_args(argv))
		return (0);
	if (argc == 5 || argc == 6)
	{
		if (!init_philo(argv, &var))
			return (1);
		do_routine(&var);
		free(var.philos);
		free(var.forks);
		return (0);
	}
	else
	{
		printf("Wrong number of arguments\n");
		return (0);
	}
}
