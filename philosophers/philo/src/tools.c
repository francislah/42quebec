/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:13:11 by flahoud           #+#    #+#             */
/*   Updated: 2022/08/10 15:35:10 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_sleep(int time)
{
	long	start;

	start = get_time();
	while (1)
	{
		if (get_time() - start >= time)
			break ;
		usleep(50);
	}
}

void	give_fork(t_table *table, t_philo *philo)
{
	if (table->philo[philo->nextp]->fork < 2)
	{
		table->philo[philo->nextp]->fork += 1;
		print(get_time() - table->begintime, philo->nextp + 1, FORK);
		philo->fork -= 1;
		if (table->philo[philo->nextp]->fork == 2)
			table->philo[philo->nextp]->state = TIME_TO_EAT;
	}
	if (table->philo[philo->prevp]->fork < 2)
	{
		table->philo[philo->prevp]->fork += 1;
		print(get_time() - table->begintime, philo->prevp + 1, FORK);
		philo->fork -= 1;
		if (table->philo[philo->prevp]->fork == 2)
			table->philo[philo->prevp]->state = TIME_TO_EAT;
	}
}

void	print(long time, int philo, int action)
{
	if (action == FORK)
		printf("%ld %d has taken a fork 🍴\n", time, philo);
	else if (action == TIME_TO_EAT)
		printf("%ld %d is eating 🍪\n", time, philo);
	else if (action == TIME_TO_THINK)
		printf("%ld %d is thinking 🧙\n", time, philo);
	else if (action == TIME_TO_SLEEP)
		printf("%ld %d is sleeping 😴\n", time, philo);
	else if (action == DEAD)
		printf("%ld	%d died 💀\n", time, philo);
}
