/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:04:03 by flahoud           #+#    #+#             */
/*   Updated: 2022/05/09 13:07:01 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clean(char *buf)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (buf[++i])
	{
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			break ;
		}
		buf[i] = '\0';
	}
	while (buf[++i])
	{
		buf[++j] = buf[i];
		buf[i] = '\0';
	}
}
