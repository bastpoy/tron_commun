/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:05:53 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/04 17:58:32 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void *sum(void *mutex)
{
    (void)mutex;
    // pthread_mutex_lock((pthread_mutex_t *)mutex);
    printf("salut le thread\n");
    // pthread_mutex_unlock((pthread_mutex_t *)mutex);
    return (NULL);
}

int init_thread(t_var *var, char **argv)
{
    int i;
    int j;
    t_philo *philo;

    j = 0;
    i = ft_atoi(argv[1], NULL);
    gettimeofday(&tv, &tz);
    var->tstart = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
    printf("Seconds since 1/1/1970: %lu\n", (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
    philo = (t_philo *)malloc(sizeof(t_philo) * i);
    if (!philo)
        return (0);
    var->philo = philo;
    pthread_mutex_init(&var->mutex, NULL);
    var->ttdin = ft_atoi(argv[2], NULL);
    var->ttein = ft_atoi(argv[3], NULL);
    var->ttsin = ft_atoi(argv[4], NULL);
    while (j < i)
    {
        gettimeofday(&tv, &tz);
        var->tpasses = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
        philo[j].ranging = j;
        philo[j].ttd = ft_atoi(argv[2], NULL);
        philo[j].tte = ft_atoi(argv[3], NULL);
        philo[j].tts = ft_atoi(argv[4], NULL);
        pthread_create(&philo[j].thread, NULL, sum, (void *)&var->mutex);
        printf("time %ld\n", var->tpasses - var->tstart);
        j++;
    }
    return (1);
}

void join_thread(t_var *var)
{
    pthread_join(var->philo[0].thread, NULL);
    pthread_join(var->philo[1].thread, NULL);
    pthread_join(var->philo[2].thread, NULL);
    pthread_join(var->philo[3].thread, NULL);
    pthread_join(var->philo[4].thread, NULL);
}

int main(int argc, char *argv[])
{
    t_var var;

    if (!check_args(argv))
        return (0);
    if (argc == 5)
    {
        init_thread(&var, argv);
        printf("good\n");
        join_thread(&var);
        pthread_mutex_destroy(&var.mutex);
        return (0);
    }
    else if (argc == 6)
    {
        printf("good\n");
        return (0);
    }
    else
    {
        printf("Wrong number of arguments\n");
        return (0);
    }
}
