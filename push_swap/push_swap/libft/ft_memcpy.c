/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:20:43 by flahoud           #+#    #+#             */
/*   Updated: 2022/03/31 12:45:48 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*pointer;
	const char	*source;

	source = src;
	pointer = dst;
	if (dst == NULL && src == NULL)
		return (0);
	while (n-- > 0)
		*pointer++ = *source++;
	return (dst);
}
