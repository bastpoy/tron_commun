/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:35:09 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/05 17:58:32 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void init_tvar(t_var *var, char **argv)
{
    pthread_mutex_init(&var->mutex, NULL);
    var->ttdin = ft_atoi(argv[2], NULL);
    var->ttein = ft_atoi(argv[3], NULL);
    var->ttsin = ft_atoi(argv[4], NULL);
}

int init_fork(t_var *var, int forknum)
{
    int i;

    i = 0;
    var->philonum = forknum;
    var->forks = malloc(sizeof(pthread_mutex_t) * forknum);
    if (!var->forks)
        return (1);
    var->philo[i].rightfork = &var->forks[0];
    var->philo[i].leftfork = &var->forks[forknum - 1];
    i++;
    while (i < forknum)
    {
        var->philo[i].leftfork = &var->forks[i];
        var->philo[i].rightfork = var->philo[i - 1].leftfork;
        i++;
    }
    return (0);
}

int init_philo(char **argv, t_var *var)
{
    int i;
    int j;
    t_philo *philo;
    struct timeval tv;

    j = 0;
    i = ft_atoi(argv[1], NULL);
    philo = (t_philo *)malloc(sizeof(t_philo) * i);
    if (!philo)
        return (1);
    gettimeofday(&tv, NULL);
    var->tstart = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
    philo->var = var;
    init_fork(var, i);
    init_tvar(var, argv);
    while (j < i)
    {
        var->tpasses = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
        philo[j].ranging = j;
        philo[j].ttd = ft_atoi(argv[2], NULL);
        philo[j].tte = ft_atoi(argv[3], NULL);
        philo[j].tts = ft_atoi(argv[4], NULL);
        philo[j].dead = 0;
        gettimeofday(&tv, NULL);
        printf("time %ld\n", var->tpasses - var->tstart);
        j++;
    }
    return (0);
}
