/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:06:23 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/29 16:57:00 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_philo
{
    pthread_t thread;
    int ttd;
    int tte;
    int tts;
    int ranging;
} t_philo;

typedef struct s_var
{
    int ttdin;
    int ttein;
    int ttsin;
    int nbeat;
    pthread_mutex_t mutex;
    t_philo *philo;
} t_var;

int check_args(char *argv[]);

int ft_atoi(const char *str, int *error);
char *ft_itoa(int n);
