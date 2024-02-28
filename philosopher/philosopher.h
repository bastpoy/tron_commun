/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:06:23 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/24 19:06:23 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_philo
{
    int ttd;
    int tte;
    int tts;
    int ranging;
}t_philo;

typedef  struct s_thread
{
    pthread_mutex_t mutex;
    int ttdin;
    int ttein;
    int ttsin;
    t_philo *philo;
} t_thread;