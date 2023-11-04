/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:51:43 by flahoud           #+#    #+#             */
/*   Updated: 2022/11/08 12:54:44 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_usec / 1000 + current_time.tv_sec * 1000);
}

int	init_table_feast(t_table *table)
{
	int	i;

	i = -1;
	table->begintime = get_time();
	pthread_mutex_init(&table->mutex, NULL);
	while (++i < table->nphilo)
	{
		pthread_mutex_init(&table->philo[i]->mutex, NULL);
		init_philo(table->philo[i], i);
	}
	i = -1;
	while (++i < table->nphilo)
	{
		table->philo[i]->t = malloc(sizeof(*table->philo[i]->t));
		if (!table->philo[i]->t)
			return (1);
		if (pthread_create(table->philo[i]->t, NULL, &routine, table->philo[i]))
			return (1);
	}
	i = -1;
	while (++i < table->nphilo)
	{
		if (pthread_join(*table->philo[i]->t, NULL))
			return (1);
		else
			pthread_mutex_destroy(&table->philo[i]->mutex);
		free(table->philo[i]->t);
	}
	pthread_mutex_destroy(&table->mutex);
	return (0);
}

void	init_philo(t_philo *philo, int i)
{
	philo->lastmeal = philo->table->begintime;
	philo->fork = 1;
	if (i == 0)
		philo->prevp = philo->table->nphilo - 1;
	else
		philo->prevp = i - 1;
	if (i == philo->table->nphilo - 1)
		philo->nextp = 0;
	else
		philo->nextp = i + 1;
}
