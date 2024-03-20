/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:06:23 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/19 16:50:09 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				ttd;
	int				tte;
	int				tts;
	long int		mealseat;
	long int		timedead;
	int				ranging;
	pthread_mutex_t	*leftfork;
	pthread_mutex_t	*rightfork;
	pthread_mutex_t	lock;
	pthread_mutex_t	meal;
	pthread_mutex_t	startmutex;
	struct s_var	*var;
}					t_philo;

typedef struct s_var
{
	pthread_mutex_t	locktdead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	pthread_mutex_t	startmutex;
	t_philo			*philos;
	pthread_t		checker;
	long int		timestart;
	int				philonum;
	int				deadflag;
	long int		mealstoeat;
	int				nomeat;
}					t_var;

int					check_args(char *argv[]);
long int			ft_atoi(const char *str, int *error);
char				*ft_itoa(long int n);

int					init_philo(char **argv, t_var *var);
long int			get_time(void);
int					do_routine(t_var *var);
void				*one_philo(t_philo *philo);
int					checkmeal(t_philo *philo);
int					deadflagstatus(t_philo *philo);

void				take_right_fork(t_philo *philo);
void				take_fork(t_philo *philo);
void				loose_fork(t_philo *philo);

void				ft_sleep(int time);
void				eating(t_philo *philo);
void				sleeping(t_philo *philo);
void				thinking(t_philo *philo);
void				is_dead(t_var *var, int i);
int					destroy_mutex(t_var *var);