/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:53:06 by flahoud           #+#    #+#             */
/*   Updated: 2022/07/06 16:46:49 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*ft_strndup(char *str, unsigned int n)
{
	char				*dup;
	unsigned int		i;

	i = 0;
	dup = malloc(sizeof(char) * (n + 1));
	while (i < n)
		dup[i++] = *str++;
	dup[n] = 0;
	return (dup);
}

int	ft_strichr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != (char) c)
		i++;
	if (s[i] == c)
		return (i);
	return (-1);
}

char	*join_path(char *path, char *bin)
{
	char	*joined;
	int		i;
	int		j;

	joined = malloc(sizeof(char)
			* (ft_strichr(path, 0) + ft_strichr(bin, 0) + 2));
	i = 0;
	j = 0;
	while (path[j])
		joined[i++] = path[j++];
	joined[i++] = '/';
	j = 0;
	while (bin[j])
		joined[i++] = bin[j++];
	joined[i] = '\0';
	return (joined);
}

char	*get_dir(char *command)
{
	char	*path[10];
	char	*commandpath;
	int		i;

	i = -1;
	path[0] = "/usr/bin/";
	path[1] = "/bin/";
	path[2] = "/usr/sbin/";
	path[3] = "/usr/local/bin/";
	path[4] = "/sbin/";
	path[5] = "/usr/local/sbin/";
	path[6] = "/snap/bin/";
	while (path[++i])
	{
		commandpath = ft_strjoin(path[i], command);
		if (access(commandpath, X_OK) != -1)
			return (commandpath);
		free(commandpath);
	}
	return (NULL);
}

char	*get_path(char *cmnd, char **envp)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (cmnd);
	path = envp[i] + 5;
	while (path && ft_strichr(path, ':') > -1)
	{
		dir = ft_strndup(path, ft_strichr(path, ':'));
		bin = join_path(dir, cmnd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += ft_strichr(path, ':') + 1;
	}
	path = get_dir(cmnd);
	if (path)
		cmnd = path;
	return (cmnd);
}
