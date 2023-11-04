/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:25:28 by flahoud           #+#    #+#             */
/*   Updated: 2022/04/05 13:24:30 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newinput;

	newinput = malloc(sizeof(t_list));
	if (newinput == NULL)
		return (NULL);
	newinput->next = NULL;
	newinput->content = content;
	return (newinput);
}
