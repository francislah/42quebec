/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:00:21 by flahoud           #+#    #+#             */
/*   Updated: 2022/06/14 13:37:42 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	num_dif(int x, int y)
{
	if ((x - y) < 0)
		return ((x - y) / -1);
	return (x - y);
}

int	find_chunk_ra(t_stack *a, int chunksize, int value)
{
	int				min;
	int				min2;
	t_innerstack	*tmp;

	min = a->p->nb;
	min2 = value;
	tmp = a->p;
	while (tmp && chunksize--)
	{
		if (tmp->nb < value && (num_dif(tmp->nb, value) < num_dif(min2, value)
				|| num_dif(min2, value) == 0))
			min2 = tmp->nb;
		if (num_dif(min, value) > num_dif(tmp->nb, value))
			min = tmp->nb;
		tmp = tmp->next;
	}
	if (min2 != value)
		return (min2);
	return (min);
}

int	find_chunk_rra(t_stack *a, int chunksize, int value, int size)
{
	int				min;
	int				min2;
	t_innerstack	*tmp;

	min = a->p->nb;
	min2 = value;
	tmp = a->p;
	while (tmp && (size-- - chunksize) > 0)
		tmp = tmp->next;
	while (tmp)
	{
		if (tmp->nb < value && (num_dif(tmp->nb, value) < num_dif(min2, value)
				|| num_dif(min2, value) == 0))
			min2 = tmp->nb;
		if (num_dif(min, value) > num_dif(tmp->nb, value))
			min = tmp->nb;
		tmp = tmp->next;
	}
	if (min2 != value)
		return (min2);
	return (min);
}

int	find_way(t_stack *a)
{
	t_innerstack	*tmp;
	int				i;
	int				min;

	min = find_min(a);
	i = 0;
	tmp = a->p;
	while (tmp && tmp->nb != min)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	sort_it_out(t_stack *a, t_stack*b)
{
	int	ext[2];

	while (b->p)
	{
		if (!a->p->next)
			push_a(a, b);
		ext[1] = find_max(a);
		ext[0] = find_min(a);
		if (num_dif(find_last(b), a->p->nb) < num_dif(b->p->nb, a->p->nb)
			|| find_last(b) > a->p->nb)
			reverse_rotate_b(b, 1);
		if (b->p->nb < ext[0])
			while (a->p->nb != ext[0])
				reverse_rotate_a(a, 1);
		else if (b->p->nb > ext[1])
			while (a->p->nb != ext[0])
				rotate_a(a, 1);
		else if (b->p->nb < a->p->nb)
			while (b->p->nb < find_last(a))
				reverse_rotate_a(a, 1);
		else if (b->p->nb > a->p->nb)
			while (b->p->nb > a->p->nb)
				rotate_a(a, 1);
		push_a(a, b);
	}
}
