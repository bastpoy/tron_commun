/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:06:23 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/09 17:49:16 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct s_philo
{
    pthread_t thread;
    pthread_t checker;
    int ttd;
    int tte;
    int tts;
    long int timedead;
    long int timestart;
    long int timethink;
    int maxphilo;
    int ranging;
    pthread_mutex_t *leftfork;
    pthread_mutex_t *rightfork;
    pthread_mutex_t lock;
    struct s_var *var;
} t_philo;

typedef struct s_var
{
    pthread_mutex_t locktdead;
    pthread_mutex_t *forks;
    t_philo *philos;
    int philonum;
    int deadflag;
} t_var;

int check_args(char *argv[]);
long int ft_atoi(const char *str, int *error);
char *ft_itoa(long int n);

int init_fork(t_var *var, int forknum);
void init_tvar(t_var *var);
int init_philo(char **argv, t_var *var);

long int get_time();
int do_routine(t_var *var);

void take_fork(t_philo *philo);
void loose_fork(t_philo *philo);