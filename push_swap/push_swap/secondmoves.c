/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondmoves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:17:38 by flahoud           #+#    #+#             */
/*   Updated: 2022/06/21 16:03:18 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *a, int bool)
{
	int				tmp;
	int				i;
	t_innerstack	*rot;
	t_innerstack	*rot2;
	t_innerstack	*new;

	i = 0;
	if (a->p == NULL || a->p->next == NULL)
		return ;
	rot = a->p;
	tmp = rot->nb;
	rot2 = rot->next;
	free(rot);
	a->p = rot2;
	new = malloc(sizeof(*new));
	if (!new)
		return ;
	new->nb = tmp;
	new->next = NULL;
	while (rot2->next != NULL)
		rot2 = rot2->next;
	rot2->next = new;
	if (bool)
		ft_printf("ra\n");
}

void	rotate_b(t_stack *b, int bool)
{
	int				tmp;
	int				i;
	t_innerstack	*rot;
	t_innerstack	*rot2;
	t_innerstack	*new;

	i = 0;
	if (b->p == NULL)
		return ;
	rot = b->p;
	if (rot->next == NULL)
		return ;
	tmp = rot->nb;
	rot2 = rot->next;
	free(rot);
	b->p = rot2;
	new = malloc(sizeof(*new));
	new->nb = tmp;
	new->next = NULL;
	while (rot2->next != NULL)
		rot2 = rot2->next;
	rot2->next = new;
	if (bool)
		ft_printf("rb\n");
}

void	rotate(t_stack *a, t_stack *b)
{
	rotate_a(a, 0);
	rotate_b(b, 0);
	ft_printf("rr\n");
}

void	reverse_rotate_a(t_stack *a, int bool)
{
	int				tmp;
	t_innerstack	*rot;
	t_innerstack	*temp;

	if (a->p == NULL)
		return ;
	rot = a->p;
	if (rot->next == NULL)
		return ;
	while (rot->next != NULL)
		rot = rot->next;
	tmp = rot->nb;
	insert(a, tmp);
	rot = a->p;
	while (rot->next->next != NULL)
		rot = rot->next;
	temp = rot->next;
	rot->next = NULL;
	free(temp);
	if (bool)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack *b, int bool)
{
	int				tmp;
	t_innerstack	*rot;
	t_innerstack	*temp;

	if (b->p == NULL)
		return ;
	rot = b->p;
	if (rot->next == NULL)
		return ;
	while (rot->next != NULL)
		rot = rot->next;
	tmp = rot->nb;
	insert(b, tmp);
	rot = b->p;
	while (rot->next->next != NULL)
		rot = rot->next;
	temp = rot->next;
	rot->next = NULL;
	free(temp);
	if (bool)
		ft_printf("rrb\n");
}
