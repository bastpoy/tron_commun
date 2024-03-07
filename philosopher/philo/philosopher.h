/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:06:23 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/07 14:48:16 by bpoyet           ###   ########.fr       */
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
    int ttd;
    int tte;
    int tts;
    long int timedead;
    long int timestart;
    int dead;
    int ranging;
    pthread_mutex_t *leftfork;
    pthread_mutex_t *rightfork;
    struct s_var *var;
} t_philo;

typedef struct s_var
{
    int philonum;
    int deadflag;
    pthread_mutex_t lock;
    pthread_mutex_t *forks;
    t_philo *philos;
} t_var;

int check_args(char *argv[]);
long int ft_atoi(const char *str, int *error);
char *ft_itoa(long int n);

int init_fork(t_var *var, int forknum);
void init_tvar(t_var *var);
int init_philo(char **argv, t_var *var);

long int get_time();
int do_routine(t_var *var);
