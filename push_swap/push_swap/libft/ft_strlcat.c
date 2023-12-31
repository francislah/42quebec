/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:00:51 by flahoud           #+#    #+#             */
/*   Updated: 2022/04/04 12:57:19 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	srclen;
	size_t	dstlen;

	j = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = dstlen;
	if (dstsize == 0)
		return (srclen);
	if (dstsize < dstlen)
		return (srclen + dstsize);
	while (i < dstsize - 1 && src[j])
			dst[i++] = src[j++];
	dst[i] = '\0';
	return (srclen + dstlen);
}
