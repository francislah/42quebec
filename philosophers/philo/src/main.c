/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:45:41 by flahoud           #+#    #+#             */
/*   Updated: 2022/08/10 13:05:57 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	table = malloc(sizeof(*table));
	if (!table)
		return (1);
	if (validate_args(table, argc, argv))
		return (2);
	if (init_table(table))
		return (3);
	if (init_table_feast(table))
		return (4);
	clean_table(table);
	return (0);
}

//Initialize structure with argument's informations
int	init_table(t_table *table)
{
	t_philo	**philo;
	int		i;

	i = -1;
	philo = malloc(sizeof(*philo) * table->nphilo);
	if (!philo)
		return (1);
	while (++i < table->nphilo)
	{
		philo[i] = malloc(sizeof(*philo[i]));
		if (!philo[i])
			return (1);
		philo[i]->philn = i + 1;
		philo[i]->table = table;
		philo[i]->state = 0;
		philo[i]->mealn = 0;
	}	
	table->philo = &*philo;
	table->feast = 1;
	return (0);
}

void	clean_table(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nphilo)
		free(table->philo[i]);
	free(table->philo);
	free(table);
}
