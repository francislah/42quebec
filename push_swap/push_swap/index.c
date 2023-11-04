/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:55:48 by flahoud           #+#    #+#             */
/*   Updated: 2022/06/15 11:43:46 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(int *array, int size)
{
	int	max;
	int	i;
	int	index;

	i = 0;
	index = 0;
	max = array[0];
	while (i < size)
	{
		if (array[i] > max)
		{
			max = array[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	get_min(int *array, int size)
{
	int	min;
	int	i;
	int	index;

	i = 0;
	index = 0;
	min = array[0];
	while (i < size)
	{
		if (array[i] < min)
		{
			min = array[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	get_next_smaller(int *array, int size, int bigger)
{
	int	next;
	int	index;
	int	i;

	index = 0;
	i = 0;
	next = array[bigger];
	while (i < size)
	{
		if (array[i] < array[bigger] && (array[i] > next
				|| next == array[bigger]))
		{
			next = array[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	index_array(int *array, int size)
{
	int	i;
	int	index;
	int	tmp;
	int	*new;

	new = malloc(sizeof(int) * size);
	if (!array || !new)
		return ;
	tmp = get_max(array, size);
	i = size;
	index = size;
	while (i-- > 0)
	{
		new[tmp] = index--;
		if (i != 0)
			tmp = get_next_smaller(array, size, tmp);
	}
	while (size--)
		array[size] = new[size];
	free(new);
}
