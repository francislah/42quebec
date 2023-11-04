/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:58:52 by flahoud           #+#    #+#             */
/*   Updated: 2022/07/06 11:47:04 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	find_way(int keycode, int way)
{
	if (keycode == RIGHT)
		return (0);
	else if (keycode == LEFT)
		return (1);
	else
		return (way);
}

void	get_x_y(t_vars *game, int key)
{
	int	i;
	int	j;

	i = game->x;
	j = game->y;
	if (key == UP && game->map[game->y / 64 - 1][game->x / 64] != '1'
		&& game->map[game->y / 64 - 1][game->x / 64] != 'W')
		j -= 64;
	else if (key == DOWN && game->map[game->y / 64 + 1][game->x / 64] != '1'
		&& game->map[game->y / 64 + 1][game->x / 64] != 'W')
		j += 64;
	else if (key == LEFT && game->map[game->y / 64][game->x / 64 - 1] != '1'
		&& game->map[game->y / 64][game->x / 64 - 1] != 'W')
		i -= 64;
	else if (key == RIGHT && game->map[game->y / 64][game->x / 64 + 1] != '1'
		&& game->map[game->y / 64][game->x / 64 + 1] != 'W')
		i += 64;
	if (game->map[j / 64][i / 64] == 'E' && game->key != game->keystofind)
		return ;
	if (i == game->x && j == game->y)
		return ;
	game->moves += 1;
	game->x = i;
	game->y = j;
}

int	playgame(int keycode, t_vars *game)
{
	static int	way;
	static int	dead;

	get_x_y(game, keycode);
	way = find_way(keycode, way);
	if (dead == 0 && game->map[game->y / 64][game->x / 64] != 'E')
		dead = print_result(game, way);
	else if ((game->map[game->y / 64][game->x / 64] == 'E'
		&& game->key == game->keystofind) || dead == 1)
	{
		restart_game(game, dead);
		dead = 0;
		return (1);
	}
	return (0);
}
