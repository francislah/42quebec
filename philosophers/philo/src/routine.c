/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:58:42 by flahoud           #+#    #+#             */
/*   Updated: 2022/11/08 13:00:01 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*routine(void *philo_void)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *) philo_void;
	table = philo->table;
	while (validate_feast(table))
	{
		pthread_mutex_lock(&table->mutex);
		get_state(table, philo);
		pthread_mutex_unlock(&table->mutex);
		if (do_action(table, philo))
			return (NULL);
	}
	return (NULL);
}

void	get_state(t_table *table, t_philo *philo)
{
	if (philo->state == START)
	{
		if (philo->philn % 2 == 1 && philo->philn < table->nphilo)
		{
			pthread_mutex_unlock(&philo->mutex);
			pthread_mutex_lock(&philo->table->philo[philo->nextp]->mutex);
			table->philo[philo->nextp]->fork -= 1;
			philo->fork += 1;
			print(get_time() - table->begintime, philo->philn, FORK);
			print(get_time() - table->begintime, philo->philn, FORK);
			philo->state = TIME_TO_EAT;
			pthread_mutex_unlock(&philo->table->philo[philo->nextp]->mutex);
			pthread_mutex_unlock(&philo->mutex);
		}
	}
	if (philo->fork == 2)
		philo->state = TIME_TO_EAT;
	else if (philo->state == THINKING)
		return ;
	else
		philo->state = TIME_TO_THINK;
}

int	do_action(t_table *table, t_philo *philo)
{
	if (philo->state == TIME_TO_EAT)
	{
		print(get_time() - table->begintime, philo->philn, philo->state);
		philo->lastmeal = get_time();
		philo_sleep(table->timetoeat);
		philo->mealn += 1;
		philo->state = TIME_TO_SLEEP;
	}
	if (validate_philo(table, philo))
		return (1);
	if (philo->state == TIME_TO_SLEEP)
	{
		give_fork(table, philo);
		print(get_time() - table->begintime, philo->philn, TIME_TO_SLEEP);
		philo_sleep(table->timetosleep);
	}
	else if (philo->state == TIME_TO_THINK || philo->state == THINKING)
	{
		if (philo->state == TIME_TO_THINK)
			print(get_time() - table->begintime, philo->philn, philo->state);
		philo->state = THINKING;
		usleep(50);
	}
	return (0);
}

int	validate_philo(t_table *table, t_philo *philo)
{
	int	dead;

	pthread_mutex_lock(&table->mutex);
	dead = 0;
	if (!table->feast)
	{
		pthread_mutex_unlock(&table->mutex);
		return (1);
	}
	if (philo->state == TIME_TO_SLEEP)
	{
		
		if (get_time() + table->timetosleep <= philo->lastmeal \
		+ table->timetodie)
		{
			pthread_mutex_unlock(&table->mutex);
			return (0);
		}
	}
	if (get_time() - philo->lastmeal > table->timetodie)
		dead = 1;
	if (dead && table->feast)
	{
		print(get_time() - table->begintime, philo->philn, philo->state);
		pthread_mutex_unlock(&table->mutex);
		philo_sleep(philo->lastmeal - get_time() + table->timetodie);
		pthread_mutex_lock(&table->mutex);
		if (table->feast) {
			print(get_time() - table->begintime, philo->philn, DEAD);
		}
		table->feast = 0;
		pthread_mutex_unlock(&table->mutex);
		return (1);
	}
	pthread_mutex_unlock(&table->mutex);
	return (0);
}

int	validate_feast(t_table *table)
{
	int	i;

	i = 0;
		pthread_mutex_lock(&table->mutex);
	if (!table->feast)
	{
		pthread_mutex_unlock(&table->mutex);
		return (1);
	}
	if (table->eatrep > 0)
		while (i < table->nphilo && table->philo[i]->mealn >= table->eatrep)
			i++;
	if (i == table->nphilo)
	{
		pthread_mutex_unlock(&table->mutex);
		return (0);
	}
	pthread_mutex_unlock(&table->mutex);
	return (1);
}
