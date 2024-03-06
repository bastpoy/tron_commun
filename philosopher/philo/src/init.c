/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:35:09 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/06 17:55:12 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void init_tvar(t_var *var)
{
    var->deadflag = 0;
}

int init_fork(t_var *var, int forknum)
{
    int i;

    i = 0;
    var->philonum = forknum;
    var->forks = malloc(sizeof(pthread_mutex_t) * forknum);
    if (!var->forks)
        return (1);
    var->philos[i].rightfork = &var->forks[0];
    var->philos[i].leftfork = &var->forks[forknum - 1];
    i++;
    while (i < forknum)
    {
        var->philos[i].leftfork = &var->forks[i];
        var->philos[i].rightfork = var->philos[i - 1].leftfork;
        i++;
    }
    return (0);
}

int init_philo(char **argv, t_var *var)
{
    int i;
    int j;
    t_philo *philo;

    j = 0;
    i = ft_atoi(argv[1], NULL);
    philo = (t_philo *)malloc(sizeof(t_philo) * i);
    if (!philo)
        return (0);
    var->philos = philo;
    philo->var = var;
    init_fork(var, i);
    init_tvar(var);
    while (j < i)
    {
        philo[j].ranging = j;
        philo[j].ttd = ft_atoi(argv[2], NULL);
        philo[j].tte = ft_atoi(argv[3], NULL);
        philo[j].tts = ft_atoi(argv[4], NULL);
        philo[j].dead = 0;
        j++;
    }
    return (1);
}
