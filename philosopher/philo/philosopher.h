/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:06:23 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/04 18:07:34 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/time.h>

struct timeval tv;
struct timezone tz;

typedef struct s_philo
{
    pthread_t thread;
    int ttd;
    int tte;
    int tts;
    int ranging;
    int leftfork;
    int rightfork;
} t_philo;

typedef struct s_var
{
    int ttdin;
    int ttein;
    int ttsin;
    int nbeat;
    int die;
    size_t tstart;
    size_t tpasses;
    pthread_mutex_t mutex;
    t_philo *philo;
} t_var;

int check_args(char *argv[]);

int ft_atoi(const char *str, int *error);
char *ft_itoa(int n);
