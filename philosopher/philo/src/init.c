/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:35:09 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/12 17:31:55 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

static void init_tvar(t_var *var, char **argv)
{
    var->deadflag = 0;
    if (argv[5] != NULL)
        var->mealstoeat = atoi(argv[5]);
    else
        var->mealstoeat = 0;
    pthread_mutex_init(&var->locktdead, NULL);
}

static int init_fork(t_var *var, int forknum)
{
    int i;

    i = 0;
    var->philonum = forknum;
    var->forks = malloc(sizeof(pthread_mutex_t) * forknum);
    if (!var->forks)
        return (0);
    pthread_mutex_init(&var->forks[0], NULL);
    pthread_mutex_init(&var->philos[0].write, NULL);
    // pthread_mutex_init(&var->forks[forknum - 1], NULL);
    var->philos[i].rightfork = &var->forks[forknum - 1];
    var->philos[i].leftfork = &var->forks[0];
    i++;
    while (i < forknum)
    {
        pthread_mutex_init(&var->forks[i], NULL);
        pthread_mutex_init(&var->philos[i].write, NULL);
        var->philos[i].leftfork = &var->forks[i];
        var->philos[i].rightfork = var->philos[i - 1].leftfork;
        i++;
    }
    return (1);
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
    if (!init_fork(var, i))
        return (0);
    init_tvar(var, argv);
    while (j < i)
    {
        philo[j].ranging = j + 1;
        philo[j].ttd = ft_atoi(argv[2], NULL);
        philo[j].tte = ft_atoi(argv[3], NULL);
        philo[j].tts = ft_atoi(argv[4], NULL);
        philo[j].var = var;
        philo[j].mealseat = 0;
        pthread_mutex_init(&philo[j].lock, NULL);
        j++;
    }
    return (1);
}
