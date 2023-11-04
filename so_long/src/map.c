/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:15:52 by flahoud           #+#    #+#             */
/*   Updated: 2022/07/04 12:43:50 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	validate_signs(t_vars *game, t_val *val)
{
	if (val->exit != 1 || val->start != 1 || val->coins != 1
		|| val->walls == -1)
	{
		if (val->exit != 1)
			printf("Error\nMap has no Exit (E).\n");
		else if (val->start != 1)
			printf("Error\nMap has no Start (P).\n");
		else if (val->coins != 1)
			printf("Error\nMap has no Coins (C).\n");
		else if (val->walls == -1)
			printf("Error\nMap has no Walls all around (1).\n");
		quit(game, 5);
	}
	game->width = val->x * 64;
	game->height = val->y * 64;
}

void	verify_map_sign(t_vars *game, t_val *val, char sign)
{
	if (sign == '0' || sign == '1')
	{
		if (val->y == 0 || !game->map[val->y + 1] || val->x == 0
			|| game->map[val->y][val->x + 1] == '\n')
			game->map[val->y][val->x] = 'W';
		return ;
	}
	else if (sign == 'E')
		val->exit = 1;
	else if (sign == 'P')
		val->start = 1;
	else if (sign == 'C')
		val->coins = 1;
	else
		quit(game, 3);
}

int	validate_map(t_vars *game, int size)
{
	t_val	val;
	int		width;

	val.y = -1;
	width = 0;
	while (game->map[++val.y])
	{
		val.x = 0;
		while (game->map[val.y][val.x] && game->map[val.y][val.x] != '\n')
		{
			if ((val.y == 0 || !game->map[val.y + 1] || val.x == 0
					|| game->map[val.y][val.x + 1] == '\n')
						&& game->map[val.y][val.x] != '1')
				val.walls = -1;
			verify_map_sign(game, &val, game->map[val.y][val.x]);
			val.x += 1;
		}
		if (width == 0)
			width = val.x;
		if (val.x != width || val.x == size)
			return (1);
	}
	validate_signs(game, &val);
	return (0);
}

void	map_height(t_vars *game, char *mapfile)
{
	char	*line;
	int		size;
	int		fd;

	fd = open(mapfile, O_RDONLY);
	if (fd < 1)
	{
		close(fd);
		quit(game, 1);
	}
	line = get_next_line(fd);
	size = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		size++;
	}
	free(line);
	close(fd);
	game->height = size;
}

void	read_map(t_vars *game, char *mapfile)
{
	int	fd;
	int	size;

	size = 0;
	map_height(game, mapfile);
	fd = open(mapfile, O_RDONLY);
	game->map = ft_calloc(sizeof(char *), game->height + 1);
	game->map[size] = get_next_line(fd);
	while (game->map[size])
		game->map[++size] = get_next_line(fd);
	close(fd);
	if (size == 0 || validate_map(game, size))
		quit(game, 2);
}
