/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:05:53 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/05 10:40:07 by bpoyet           ###   ########.fr       */
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

int init_thread(char **argv)
{
    int i;
    int j;
    t_philo *philo;
    t_var *var;

    j = 0;
    i = ft_atoi(argv[1], NULL);
    printf("Seconds since 1/1/1970: %lu\n", (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
    philo = (t_philo *)malloc(sizeof(t_philo) * i);
    if (!philo)
        return (1);
    var = (t_var *)malloc(sizeof(t_var));
    if (!var)
        return (1);
    gettimeofday(&tv, &tz);
    var->tstart = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
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
    return (0);
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
        init_thread(argv);
        printf("good\n");

        join_thread(&var);
        // printf("ranging %d\n", var->philo[4].ranging);
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
