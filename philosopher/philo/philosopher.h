/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:06:23 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/06 17:54:39 by bpoyet           ###   ########.fr       */
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
    long int tstart;
    long int tpasses;
    pthread_mutex_t *leftfork;
    pthread_mutex_t *rightfork;
    struct s_var *var;
} t_philo;

typedef struct s_var
{
    int philonum; // nombre de philos
    int nbeat;
    int deadflag; // 0 philo vivant 1 philo morts
    long int tstart;
    long int tpasses;
    pthread_mutex_t *forks;
    t_philo *philos;
} t_var;

int check_args(char *argv[]);
long int ft_atoi(const char *str, int *error);
char *ft_itoa(long int n);

int init_fork(t_var *var, int forknum);
void init_tvar(t_var *var);
int init_philo(char **argv, t_var *var);

int get_time();
int do_routine(t_var *var);
