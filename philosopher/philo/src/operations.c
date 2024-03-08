/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:09:13 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/08 18:06:03 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void take_fork(t_philo *philo)
{
    if (philo->ranging == philo->maxphilo)
    {
        pthread_mutex_lock(philo->leftfork);
        printf("%ld %d has taken a fork\n", get_time() - philo->timestart, philo->ranging);
        pthread_mutex_lock(philo->rightfork);
        printf("%ld %d has taken a fork\n", get_time() - philo->timestart, philo->ranging);
    }
    else
    {
        pthread_mutex_lock(philo->rightfork);
        printf("%ld %d has taken a fork\n", get_time() - philo->timestart, philo->ranging);
        pthread_mutex_lock(philo->leftfork);
        printf("%ld %d has taken a fork\n", get_time() - philo->timestart, philo->ranging);
    }
}