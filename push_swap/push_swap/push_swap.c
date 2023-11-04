/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:08:58 by flahoud           #+#    #+#             */
/*   Updated: 2022/06/20 13:49:50 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rra et rrb en même temps.
void	reverse_rotate(t_stack *a, t_stack *b)
{
	reverse_rotate_a(a, 0);
	reverse_rotate_b(b, 0);
	ft_printf("rrr\n");
}

// si déjà trier = 0 / si 2 arguments = 1 movement max / si + que 3 sa dérape...
void	sort_t_stack(t_stack *a, t_stack *b, int size)
{
	if (dance_time(a) || size == 1)
		return ;
	if (size == 2)
	{
		if (a->p->nb > a->p->next->nb)
			swap_a(a, 1);
	}
	else if (size == 3)
		magic_sort(a);
	else if (size == 4 || size == 5)
		simple_sort(a, b, size);
	else if (size > 5 && size <= 100)
		true_sort(a, b, 8, size);
	else if (size > 100)
		true_sort(a, b, 16, size);
}

t_stack	*initialize_t_stack(void)
{
	t_innerstack	*new;
	t_innerstack	*del;
	t_stack			*controlt_stack;

	new = malloc(sizeof(*new));
	controlt_stack = malloc(sizeof(*controlt_stack));
	if (new == NULL || controlt_stack == NULL)
		return (NULL);
	new->next = NULL;
	controlt_stack->p = new;
	del = controlt_stack->p;
	controlt_stack->p = controlt_stack->p->next;
	free(del);
	return (controlt_stack);
}

void	insert(t_stack *x, int nb)
{
	t_innerstack	*tmp;

	tmp = malloc(sizeof(*tmp));
	if (x == NULL || tmp == NULL)
		return ;
	tmp->nb = nb;
	if (!x->p)
		tmp->next = NULL;
	else
		tmp->next = x->p;
	x->p = tmp;
}

int	main(int argc, char **argv)
{
	int		*tmp;
	int		size;
	int		i;
	t_stack	*a;
	t_stack	*b;

	i = 0;
	size = 0;
	if (argc == 1)
		return (0);
	tmp = check_args(argc, argv, &size);
	if (!tmp)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	index_array(tmp, size);
	a = initialize_t_stack();
	while (size - i++)
		insert(a, tmp[size - i]);
	free(tmp);
	b = initialize_t_stack();
	sort_t_stack(a, b, size);
	clean_list(a, b);
	return (0);
}
