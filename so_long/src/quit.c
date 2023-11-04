/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:21:46 by flahoud           #+#    #+#             */
/*   Updated: 2022/07/05 11:52:39 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_map(t_vars *game)
{
	int	x;

	x = 0;
	while (game->map[x])
		free(game->map[x++]);
}

void	free_images(t_vars *game)
{
	mlx_destroy_image(game->mlx, game->img->enemy);
	mlx_destroy_image(game->mlx, game->img->exitlocked);
	mlx_destroy_image(game->mlx, game->img->exitunlocked);
	mlx_destroy_image(game->mlx, game->img->gameover);
	mlx_destroy_image(game->mlx, game->img->win);
	mlx_destroy_image(game->mlx, game->img->obstacle);
	mlx_destroy_image(game->mlx, game->img->wall);
	mlx_destroy_image(game->mlx, game->img->tile);
	mlx_destroy_image(game->mlx, game->img->key);
	mlx_destroy_image(game->mlx, game->img->right);
	mlx_destroy_image(game->mlx, game->img->left);
}

int	quit_game(t_vars *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_map(game);
	if (game->img)
		free_images(game);
	exit(0);
}

void	print_error(t_vars *game, int error)
{
	if (error == 1)
		printf("Error\nFile couldn't be open\n");
	if (error == 2)
		printf("Error\nMap invalid\n");
	if (error == 3)
	{
		printf("Error\nMap contains invalid signs\n");
		free_map(game);
	}
	exit(0);
}

void	quit(t_vars *game, int state)
{
	if (state > 0 && state < 5)
		print_error(game, state);
	free_map(game);
	exit(0);
}
