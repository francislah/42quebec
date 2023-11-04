/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firstmoves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:19:25 by flahoud           #+#    #+#             */
/*   Updated: 2022/06/21 16:04:06 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *a, int bool)
{
	t_innerstack	*swap;
	int				tmp;

	if (a->p == NULL)
		return ;
	swap = a->p;
	tmp = swap->nb;
	if (swap->next == NULL)
		return ;
	swap->nb = swap->next->nb;
	swap->next->nb = tmp;
	a->p = swap;
	if (bool)
		ft_printf("sa\n");
}

void	swap_b(t_stack *b, int bool)
{
	t_innerstack	*swap;
	int				tmp;

	if (b->p == NULL)
		return ;
	swap = b->p;
	tmp = swap->nb;
	if (swap->next == NULL)
		return ;
	swap->nb = swap->next->nb;
	swap->next->nb = tmp;
	b->p = swap;
	if (bool)
		printf("sb\n");
}

void	swap(t_stack *a, t_stack *b)
{
	swap_a(a, 0);
	swap_b(b, 0);
	ft_printf("ss\n");
}

void	push_a(t_stack *a, t_stack *b)
{
	int				tmp;
	t_innerstack	*push;

	if (b->p == NULL)
		return ;
	tmp = 0;
	if (b != NULL)
	{
		tmp = b->p->nb;
		push = b->p;
		b->p = b->p->next;
		free(push);
	}
	insert(a, tmp);
	ft_printf("pa\n");
}

void	push_b(t_stack *a, t_stack *b)
{
	int				tmp;
	t_innerstack	*push;

	if (a == NULL)
		return ;
	tmp = 0;
	if (a != NULL && a->p != NULL)
	{
		tmp = a->p->nb;
		push = a->p;
		a->p = push->next;
		free(push);
	}
	insert(b, tmp);
	ft_printf("pb\n");
}
