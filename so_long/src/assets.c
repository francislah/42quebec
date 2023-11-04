/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:53:41 by flahoud           #+#    #+#             */
/*   Updated: 2022/07/04 12:42:42 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	build_assets_part2(t_img *tmp, t_vars *game)
{
	tmp->exitlocked = mlx_xpm_file_to_image(game->mlx,
			"./mlx/exit_locked.xpm", &game->imgsize, &game->imgsize);
	tmp->exitunlocked = mlx_xpm_file_to_image(game->mlx,
			"./mlx/exit_unlocked.xpm", &game->imgsize, &game->imgsize);
	tmp->key = mlx_xpm_file_to_image(game->mlx, "./mlx/key.xpm",
			&game->imgsize, &game->imgsize);
	tmp->win = mlx_xpm_file_to_image(game->mlx,
			"./mlx/wining_exit.xpm", &game->imgsize, &game->imgsize);
}

void	build_assets(t_vars *game)
{
	t_img	*tmp;

	tmp = malloc(sizeof(*tmp));
	tmp->left = mlx_xpm_file_to_image(game->mlx,
			"./mlx/minotaurleft.xpm", &game->imgsize, &game->imgsize);
	tmp->right = mlx_xpm_file_to_image(game->mlx,
			"./mlx/minotaurright.xpm", &game->imgsize, &game->imgsize);
	tmp->tile = mlx_xpm_file_to_image(game->mlx,
			"./mlx/tile1.xpm", &game->imgsize, &game->imgsize);
	tmp->enemy = mlx_xpm_file_to_image(game->mlx,
			"./mlx/minotaurleftenemy.xpm", &game->imgsize, &game->imgsize);
	tmp->gameover = mlx_xpm_file_to_image(game->mlx,
			"./mlx/explosion-4.xpm", &game->imgsize, &game->imgsize);
	tmp->wall = mlx_xpm_file_to_image(game->mlx,
			"./mlx/wall.xpm", &game->imgsize, &game->imgsize);
	tmp->obstacle = mlx_xpm_file_to_image(game->mlx,
			"./mlx/obstacle.xpm", &game->imgsize, &game->imgsize);
	build_assets_part2(tmp, game);
	game->img = tmp;
}
