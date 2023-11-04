/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:18:47 by flahoud           #+#    #+#             */
/*   Updated: 2022/07/04 12:43:23 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	find_exit(t_vars *game, int bool)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'E')
			{
				if (bool)
					return (x);
				else
					return (y);
			}
		}
	}
	printf("Error\nPas de point de sortie dans la map...\n");
	exit(0);
}

int	get_x_enemy(t_vars *game, int keycode, int x, int y)
{
	int	i;
	int	j;

	if (x == 0)
	{
		x = find_exit(game, 1) * 64;
		y = find_exit(game, 0) * 64;
	}
	i = x;
	j = y;
	if (keycode == UP && game->map[y / 64 - 1][x / 64] != '1'
		&& game->map[y / 64 - 1][x / 64] != 'W')
		j -= 64;
	else if (keycode == DOWN && game->map[y / 64 + 1][x / 64] != '1'
		&& game->map[y / 64 + 1][x / 64] != 'W')
		j += 64;
	else if (keycode == LEFT && game->map[y / 64][x / 64 - 1] != '1'
		&& game->map[y / 64][x / 64 - 1] != 'W')
		i -= 64;
	else if (keycode == RIGHT && game->map[y / 64][x / 64 + 1] != '1'
		&& game->map[y / 64][x / 64 + 1] != 'W')
		i += 64;
	if (game->map[j / 64][i / 64] == 'E')
		i = x;
	return (i);
}

int	get_y_enemy(t_vars *game, int keycode, int x, int y)
{
	int	i;
	int	j;

	if (y == 0)
		y = find_exit(game, 0) * 64;
	i = x;
	j = y;
	if (keycode == UP && game->map[y / 64 - 1][x / 64] != '1'
		&& game->map[y / 64 - 1][x / 64] != 'W')
		j -= 64;
	else if (keycode == DOWN && game->map[y / 64 + 1][x / 64] != '1'
		&& game->map[y / 64 + 1][x / 64] != 'W')
		j += 64;
	else if (keycode == LEFT && game->map[y / 64][x / 64 - 1] != '1'
		&& game->map[y / 64][x / 64 - 1] != 'W')
		i -= 64;
	else if (keycode == RIGHT && game->map[y / 64][x / 64 + 1] != '1'
		&& game->map[y / 64][x / 64 + 1] != 'W')
		i += 64;
	if (game->map[j / 64][i / 64] == 'E')
		j = y;
	return (j);
}

int	random_enemy_move(int x)
{
	int	random;

	random = (x / 64) % 4;
	if (random == 3)
		random = 13;
	return (random);
}

int	print_enemy(t_vars *game, int way)
{
	static int			enemyx;
	static int			enemyy;
	int					enemymove;

	enemymove = random_enemy_move(game->x);
	enemyx = get_x_enemy(game, enemymove, enemyx, enemyy);
	enemyy = get_y_enemy(game, enemymove, enemyx, enemyy);
	if (enemyx == game->x && enemyy == game->y)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->gameover, game->x, game->y - 32);
		enemyx = 0;
		return (0);
	}
	else if (enemyx >= game->x - 64 && enemyx <= game->x + 64
		&& enemyy >= game->y - 64 && enemyy <= game->y + 64)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->enemy, enemyx, enemyy);
	if (way == 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->right, game->x, game->y);
	else if (way == 1)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->left, game->x, game->y);
	return (1);
}
