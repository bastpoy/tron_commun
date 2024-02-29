/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:05:53 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/29 17:29:49 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void sum(void *num)
{
    int *ptr = num;
    ptr[2] = ptr[0] + ptr[1];
    printf("%d\n", ptr[0] + ptr[1]);
}

int init_thread(t_var *var, char **argv)
{
    int i;
    int j;
    t_philo *philo;

    j = 0;
    i = ft_atoi(argv[1], NULL);
    philo = (t_philo *)malloc(sizeof(t_philo) * i);
    if (!philo)
        return (0);
    var->philo = philo;
    var->ttdin = ft_atoi(argv[2], NULL);
    var->ttein = ft_atoi(argv[3], NULL);
    var->ttsin = ft_atoi(argv[4], NULL);
    pthread_mutex_init(&var->mutex, NULL);
    while (j < i)
    {
        philo[j].ranging = j;
        philo[j].ttd = ft_atoi(argv[2], NULL);
        philo[j].tte = ft_atoi(argv[3], NULL);
        philo[j].tts = ft_atoi(argv[4], NULL);
        // pthread_create(&philo[j].thread, NULL, NULL, NULL);
        j++;
    }
    return (1);
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
