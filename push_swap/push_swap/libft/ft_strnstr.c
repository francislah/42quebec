/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:25:42 by flahoud           #+#    #+#             */
/*   Updated: 2022/06/10 15:43:50 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hayt_stack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(needle[i]))
		return ((char *) hayt_stack);
	while (hayt_stack[i] && i < len)
	{
		j = 0;
		while (hayt_stack[i + j] == needle[j] && (i + j) < len)
		{
			j++;
			if (needle[j] == '\0')
				return ((char *) &hayt_stack[i]);
		}
		i++;
	}
	return (0);
}
