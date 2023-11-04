/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:19:29 by flahoud           #+#    #+#             */
/*   Updated: 2022/07/04 12:27:06 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	print_keys(t_vars *game)
{
	char	*keystr;
	char	*keytotal;
	int		color;

	if (game->key == game->keystofind)
		color = 111111;
	else
		color = 22222;
	keystr = ft_itoa(game->key);
	keytotal = ft_itoa(game->keystofind);
	mlx_string_put(game->mlx, game->win, 0, 0, color, "Keys:");
	mlx_string_put(game->mlx, game->win, 60, 0, color, keystr);
	mlx_string_put(game->mlx, game->win, 80, 0, color, "/");
	mlx_string_put(game->mlx, game->win, 100, 0, color, keytotal);
	free(keystr);
	free(keytotal);
}

void	print_moves(t_vars *game)
{
	int		color[2];
	char	*movestr;
	char	*highscorestr;

	color[0] = 111111;
	color[1] = 111111;
	movestr = ft_itoa(game->moves);
	if (game->moves > game->highscore && game->highscore > 0)
		color[1] = 0xd42500;
	printf("Moves: %d\n", game->moves);
	mlx_string_put(game->mlx, game->win, 0, 32, color[1], "Moves: ");
	mlx_string_put(game->mlx, game->win, 60, 32, color[1], movestr);
	mlx_string_put(game->mlx, game->win, 0, 64, color[0], "Highscore: ");
	if (game->highscore == 0)
		mlx_string_put(game->mlx, game->win, 100, 64, color[0],
			"Play one game...");
	else if (game->highscore == -1)
		mlx_string_put(game->mlx, game->win, 100, 64, color[0], "Loser...");
	else
	{
		highscorestr = ft_itoa(game->highscore);
		mlx_string_put(game->mlx, game->win, 100, 64, color[0], highscorestr);
		free(highscorestr);
	}
	free(movestr);
}

void	number_of_keys(t_vars *game)
{
	int	x;
	int	y;
	int	keys;

	keys = 0;
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'C')
				keys++;
		}
	}
	game->keystofind = keys;
}
