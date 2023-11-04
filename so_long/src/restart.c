/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restart.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:21:00 by flahoud           #+#    #+#             */
/*   Updated: 2022/07/04 12:36:05 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	reset_stats(t_vars *game)
{
	game->key = 0;
	game->moves = 0;
	set_up_start(game);
}

void	restart_game(t_vars *game, int dead)
{
	if (dead == 1 && game->highscore == 0)
		game->highscore = -1;
	if (dead == 0)
	{
		print_tiles(game);
		print_rest(game);
		print_enemy(game, 3);
		print_moves(game);
		print_keys(game);
		mlx_put_image_to_window(game->mlx, game->win, game->img->win,
			game->x, game->y);
		if (game->highscore == -1 || game->highscore == 0
			|| game->moves < game->highscore)
			game->highscore = game->moves;
	}
	reset_stats(game);
	print_result(game, 0);
}
