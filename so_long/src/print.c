/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:16:20 by flahoud           #+#    #+#             */
/*   Updated: 2022/07/04 12:39:59 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	print_exit(t_vars *game, int unlocked)
{
	int	x;
	int	y;

	y = -1;
	x = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img->exitlocked, x * 64, y * 64);
			else if (game->map[y][x] == 'E' && unlocked == 1)
				mlx_put_image_to_window(game->mlx, game->win,
					game->img->exitlocked, x * 64, y * 64);
		}
	}
}

void	put_tile(t_vars *game, int print)
{
	if (print == 1)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->wall, game->printx, game->printy);
	else if (print == 2)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->obstacle, game->printx, game->printy);
	else if (print == 3)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->exitlocked, game->printx, game->printy);
	else if (print == 4)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->key, game->printx, game->printy);
	else if (print == 5)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->exitunlocked, game->printx, game->printy);
}

void	print_rest(t_vars *game)
{
	int	i;
	int	j;

	i = -2;
	while (++i < 2)
	{
		j = -2;
		while (++j < 2)
		{
			game->printx = game->x + j * 64;
			game->printy = game->y + i * 64;
			if (game->map[game->y / 64 + i][game->x / 64 + j] == 'W')
				put_tile(game, 1);
			else if (game->map[game->y / 64 + i][game->x / 64 + j] == '1')
				put_tile(game, 2);
			else if (game->map[game->y / 64 + i][game->x / 64 + j] == 'E'
				&& game->key != game->keystofind)
				put_tile(game, 3);
			else if (game->map[game->y / 64 + i][game->x / 64 + j] == 'C')
				put_tile(game, 4);
			else if (game->map[game->y / 64 + i][game->x / 64 + j] == 'E'
				&& game->key == game->keystofind)
				put_tile(game, 5);
		}
	}
}

void	print_tiles(t_vars *game)
{
	int	i;

	i = -2;
	mlx_clear_window(game->mlx, game->win);
	while (++i <= 1)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->tile, game->x + i * 64, game->y + 64);
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->tile, game->x + i * 64, game->y);
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->tile, game->x + i * 64, game->y - 64);
	}
	if (game->map[game->y / 64][game->x / 64] == 'C')
	{
		game->map[game->y / 64][game->x / 64] = '0';
		game->key += 1;
	}
}

int	print_result(t_vars *game, int way)
{
	int	tmp;

	tmp = way;
	print_tiles(game);
	print_rest(game);
	if (print_enemy(game, way) == 0)
		return (1);
	print_moves(game);
	print_keys(game);
	return (0);
}
