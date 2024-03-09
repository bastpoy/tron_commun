/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:09:13 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/09 18:11:09 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void take_fork(t_philo *philo)
{

    // je prends ma premiere fourchette
    pthread_mutex_lock(philo->rightfork);
    pthread_mutex_lock(&philo->var->locktdead);
    if (philo->var->deadflag == 0)
        printf("%ld %d has taken a fork\n", get_time() - philo->timestart, philo->ranging);
    pthread_mutex_unlock(&philo->var->locktdead);

    // je prends ma deuxieme fourchette
    // printf("%d attend sa fourchette gauche\n", philo->ranging);
    pthread_mutex_lock(philo->leftfork);
    // printf("%d attend sa fourchette droite\n", philo->ranging);
    pthread_mutex_lock(&philo->var->locktdead);
    if (philo->var->deadflag == 0)
        printf("%ld %d has taken a fork\n", get_time() - philo->timestart, philo->ranging);
    pthread_mutex_unlock(&philo->var->locktdead);
}

void loose_fork(t_philo *philo)
{
    pthread_mutex_unlock(philo->leftfork);
    pthread_mutex_unlock(philo->rightfork);
}