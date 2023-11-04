/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:56:47 by flahoud           #+#    #+#             */
/*   Updated: 2022/07/02 18:56:56 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_argc(int argc)
{
	if (argc == 2)
		return (0);
	printf("Error\nExecute as ./so_long mapfile.ber\n");
	return (1);
}

int	check_file(char *file)
{
	int	i;

	i = 0;
	while (file[i + 1])
		i++;
	if (file[i] == 'r' && file[i - 1] == 'e' && file[i - 2] == 'b'
		&& file[i - 3] == '.')
		return (0);
	printf("Error\nUse .ber map file as argument\n");
	return (1);
}
