/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:02:26 by flahoud           #+#    #+#             */
/*   Updated: 2022/07/04 12:39:43 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	key_hook(int keycode, t_vars *game)
{
	static int	restart;

	if (restart == 1)
	{
		free_map(game);
		free(game->map);
		read_map(game, game->mapfile);
	}
	if (keycode == ESC)
		quit_game(game);
	else
		restart = playgame(keycode, game);
	return (0);
}

void	set_up_start(t_vars *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = 0;
		while (game->map[y][x] && game->map[y][x] != '\n'
			&& game->map[y][x] != 'P')
			x++;
		if (game->map[y][x] == 'P')
		{
			game->x = x * 64;
			game->y = y * 64;
		}
	}
}

void	init_values(t_vars *game)
{
	game->key = 0;
	game->moves = 0;
	number_of_keys(game);
	set_up_start(game);
	game->imgsize = 64;
}

int	main(int argc, char **argv)
{
	t_vars	game;

	if (check_argc(argc) || check_file(argv[1]))
		return (0);
	read_map(&game, argv[1]);
	game.mapfile = argv[1];
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width, game.height,
			"so_long");
	init_values(&game);
	build_assets(&game);
	print_result(&game, 0);
	mlx_hook(game.win, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.win, 17, 0, quit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
