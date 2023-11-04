/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:38:47 by flahoud           #+#    #+#             */
/*   Updated: 2022/06/14 13:53:24 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Tri 3 nombres
void	magic_sort(t_stack *a)
{
	int	max;
	int	min;

	max = find_max(a);
	min = find_min(a);
	if (dance_time(a))
		return ;
	if (find_last(a) != max || find_last(a) != min)
	{
		if (a->p->nb == max)
			rotate_a(a, 1);
		else if (a->p->nb == min)
			reverse_rotate_a(a, 1);
	}
	if (a->p->nb > a->p->next->nb)
		swap_a(a, 1);
	if (find_last(a) == min)
		reverse_rotate_a(a, 1);
}

// Tri 4 ou 5 nombres
void	simple_sort(t_stack *a, t_stack *b, int size)
{
	int	min;

	while (size-- > 3)
	{
		min = find_min(a);
		while (a->p->nb != min)
		{
			if (a->p->next->nb == min || a->p->next->next->nb == min)
				rotate_a(a, 1);
			else
				reverse_rotate_a(a, 1);
		}
		if (dance_time(a) && !b->p)
			return ;
		push_b(a, b);
	}
	magic_sort(a);
	while (b->p)
		push_a(a, b);
}

//Tri toute une vie
void	push_others(t_stack *a, t_stack *b, int chunksize, int size)
{
	int		ra;
	int		rra;
	int		newsize;

	newsize = size;
	while (a->p->next)
	{
		ra = find_chunk_ra(a, chunksize, b->p->nb);
		rra = find_chunk_rra(a, chunksize, b->p->nb, newsize--);
		if (ra < rra)
			while (a->p->nb != ra)
				rotate_a(a, 1);
		else
			while (a->p->nb != rra)
				reverse_rotate_a(a, 1);
		push_b(a, b);
	}
}

void	push_first(t_stack *a, t_stack *b, int chunksize, int size)
{
	int	ra;
	int	rra;

	ra = find_chunk_ra(a, chunksize, find_min(a));
	rra = find_chunk_rra(a, chunksize, find_min(a), size);
	if (ra < rra)
		while (a->p->nb != ra)
			rotate_a(a, 1);
	else
		while (a->p->nb != rra)
			reverse_rotate_a(a, 1);
	push_b(a, b);
}

void	true_sort(t_stack *a, t_stack *b, int chunksize, int size)
{
	int	min;

	push_first(a, b, chunksize, size);
	push_others(a, b, chunksize, size);
	sort_it_out(a, b);
	min = find_min(a);
	if (find_way(a) > (size / 2))
		while (a->p->nb != min)
			reverse_rotate_a(a, 1);
	else
		while (a->p->nb != min)
			rotate_a(a, 1);
}
