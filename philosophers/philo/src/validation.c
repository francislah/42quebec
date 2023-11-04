/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:24:11 by flahoud           #+#    #+#             */
/*   Updated: 2022/08/10 12:01:06 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	set_to_int(char *n)
{
	int		i;
	long	num;

	i = 0;
	while (n && n[i] >= '0' && n[i] <= '9')
		i++;
	if (!n || n[i] || i > 11)
		return (-1);
	i = -1;
	num = 0;
	while (n[++i])
		num = num * 10 + n[i] - '0';
	if (num > INT_MAX || num == 0)
		return (-1);
	return ((int)num);
}

char	*validate(t_table *table, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return ("Error: Execute as ./philo <philo> <time to die> <time to eat> \
 <time to sleep> +(optional)<eat times>");
	table->nphilo = set_to_int(argv[1]);
	if (table->nphilo < 1)
		return ("Error: 1st argument invalid (Number of philosophers)");
	table->timetodie = set_to_int(argv[2]);
	if (table->timetodie < 0)
		return ("Error: 2nd argument invalid (Time to die)");
	table->timetoeat = set_to_int(argv[3]);
	if (table->timetoeat < 0)
		return ("Error: 3rd argument invalid (Time to eat)");
	table->timetosleep = set_to_int(argv[4]);
	if (table->timetosleep < 0)
		return ("Error: 4th argument invalid (Time to sleep)");
	if (argc == 6)
	{
		table->eatrep = set_to_int(argv[5]);
		if (table->eatrep < 0)
			return ("Error: 5th argument invalid (Number of repetitions)");
	}
	else
		table->eatrep = -1;
	return (NULL);
}

int	validate_total(t_table *table, int argc, char **argv)
{
	char	*error_msg;

	error_msg = validate(table, argc, argv);
	if (error_msg)
	{
		printf("%s\n", error_msg);
		return (1);
	}
	return (0);
}

int	validate_args(t_table *table, int argc, char **argv)
{
	if (!validate_total(table, argc, argv))
	{
		if (table->timetoeat < table->timetosleep)
			table->timetothink = table->timetoeat;
		else
			table->timetothink = table->timetodie;
		return (0);
	}
	free(table);
	return (1);
}
