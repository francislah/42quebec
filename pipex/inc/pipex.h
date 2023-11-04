/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:37:47 by flahoud           #+#    #+#             */
/*   Updated: 2022/07/07 10:23:44 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/inc/libft.h"
# include <stdio.h>

# define INFILE 0
# define OUTFILE 1

typedef struct s_vars{
	int		fdin;
	int		fdout;
	char	**args;
	char	*path;
}t_vars;

//clean.c
void	free_stack(t_vars *pipepath);

//tools.c
char	*get_path(char *cmnd, char **envp);
int		ft_strichr(const char *s, int c);

//validation.c
int		check_file(char *filename, int mode);

#endif
