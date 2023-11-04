/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:51:57 by flahoud           #+#    #+#             */
/*   Updated: 2022/07/04 12:41:03 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/inc/libft.h"
# include <mlx.h>
# include <stdio.h>

# define ESC 53
# define UP		13
# define DOWN	1
# define LEFT	0
# define RIGHT	2

typedef struct s_img {
	void	*left;
	void	*right;
	void	*tile;
	void	*enemy;
	void	*gameover;
	void	*wall;
	void	*obstacle;
	void	*exitlocked;
	void	*exitunlocked;
	void	*key;
	void	*win;
}t_img;

typedef struct s_val {
	int	x;
	int	y;
	int	walls;
	int	coins;
	int	exit;
	int	start;
}t_val;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	char	*mapfile;
	int		imgsize;
	int		height;
	int		width;
	int		key;
	int		keystofind;
	int		moves;
	int		highscore;
	int		x;
	int		y;
	int		printx;
	int		printy;
	t_img	*img;
}t_vars;

//assets.c
void	build_assets(t_vars *game);

//enemy.c
int		print_enemy(t_vars *game, int way);

//map.c
void	read_map(t_vars *game, char *mapfile);

//play.c
int		playgame(int keycode, t_vars *game);
void	find_start(char **map);

//print.c
int		print_result(t_vars *game, int way);
void	print_tiles(t_vars *game);
void	print_rest(t_vars *game);
void	put_tile(t_vars *game, int print);
void	print_exit(t_vars *game, int unlocked);

//print_string.c
void	number_of_keys(t_vars *game);
void	print_moves(t_vars *game);
void	print_keys(t_vars *game);

//quit.c
void	quit(t_vars *game, int state);
int		quit_game(t_vars *game);
void	free_map(t_vars *game);

//restart.c
void	restart_game(t_vars *game, int dead);

//so_long.c
void	set_up_start(t_vars *game);

//validation.c
int		check_file(char *file);
int		check_argc(int argc);

#endif
