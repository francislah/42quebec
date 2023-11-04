/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:07:27 by flahoud           #+#    #+#             */
/*   Updated: 2022/08/10 15:40:52 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

# define MILLISECONDS 1000
# define START 0
# define TIME_TO_THINK 1
# define THINKING 2
# define TIME_TO_EAT 3
# define TIME_TO_SLEEP 4
# define FORK 5
# define DEAD 6

typedef struct s_table	t_table;

typedef struct s_philo
{
	pthread_t		*t;
	pthread_mutex_t	mutex;
	int				philn;
	int				fork;
	long			lastmeal;
	int				hungry;
	int				state;
	int				mealn;
	int				nextp;
	int				prevp;
	t_table			*table;
}t_philo;

typedef struct s_table
{
	t_philo			**philo;
	pthread_mutex_t	mutex;
	int				nphilo;
	int				timetodie;
	int				timetoeat;
	int				timetosleep;
	int				timetothink;
	int				eatrep;
	long			begintime;
	int				feast;
}t_table;

//free.c

void	free_list(t_table *table);

//main.c
int		init_table(t_table *table);
void	clean_table(t_table *table);

//routine.
void	*routine(void *philo_void);
void	get_state(t_table *table, t_philo *philo);
int		do_action(t_table *table, t_philo *philo);
int		validate_feast(t_table *table);
int		validate_philo(t_table *table, t_philo *philo);

//thread.c
int		init_table_feast(t_table *table);
void	init_philo(t_philo *philo, int i);
int		get_time(void);

//tools.c
void	philo_sleep(int time);
void	give_fork(t_table *table, t_philo *philo);
void	print(long time, int philo, int action);

//validation.c
int		validate_args(t_table *table, int argc, char **argv);

#endif
