/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:54:58 by flahoud           #+#    #+#             */
/*   Updated: 2022/04/04 13:09:10 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char		*pointer;
	size_t		i;

	i = 0;
	pointer = (char *) s;
	while (i < n)
	{
		if (pointer[i] == (char) c)
			return (pointer + i);
		i++;
	}
	return (0);
}
