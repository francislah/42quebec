/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:37:16 by flahoud           #+#    #+#             */
/*   Updated: 2022/06/20 13:49:25 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_list(t_stack *a, t_stack *b)
{
	t_innerstack	*tmp;
	t_innerstack	*del;

	del = a->p;
	while (del)
	{
		tmp = del;
		del = del->next;
		free(tmp);
	}
	free(a);
	del = b->p;
	while (del)
	{
		tmp = del;
		del = del->next;
		free(tmp);
	}
	free(b);
	return ;
}

int	dance_time(t_stack *a)
{
	t_innerstack	*tmp;

	tmp = a->p;
	while (tmp && tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	find_last(t_stack *x)
{
	t_innerstack	*find;
	int				tmp;

	find = x->p;
	tmp = find->nb;
	while (find->next)
	{
		tmp = find->next->nb;
		find = find->next;
	}
	return (tmp);
}

int	find_max(t_stack *x)
{
	t_innerstack	*find;
	int				tmp;

	find = x->p;
	tmp = find->nb;
	while (find->next)
	{
		if (find->next->nb > tmp)
			tmp = find->next->nb;
		find = find->next;
	}
	return (tmp);
}

int	find_min(t_stack *x)
{
	t_innerstack	*find;
	int				tmp;

	find = x->p;
	tmp = find->nb;
	while (find->next)
	{
		if (find->next->nb < tmp)
			tmp = find->next->nb;
		find = find->next;
	}
	return (tmp);
}
