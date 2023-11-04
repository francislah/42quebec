/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:37:11 by flahoud           #+#    #+#             */
/*   Updated: 2022/07/07 10:39:50 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_stack(t_vars *pipepath)
{
	int	i;

	i = 0;
	if (pipepath->args)
	{
		while (pipepath->args[i])
			free(pipepath->args[i++]);
		free(pipepath->args);
	}
	if (pipepath->path)
		free(pipepath->path);
}

void	execute(t_vars *pipepath, char **envp, char *cmd)
{
	pipepath->args = ft_split(cmd, ' ');
	if (ft_strichr(pipepath->args[0], '/') > -1)
		pipepath->path = pipepath->args[0];
	else
		pipepath->path = get_path(pipepath->args[0], envp);
	execve(pipepath->path, pipepath->args, envp);
	ft_putstr_fd("Error: Command not found (", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(")\n", STDERR_FILENO);
	exit(127);
}

void	child_processing(t_vars *pipepath, char **envp, char *cmd)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		if (pipepath->fdin == STDIN_FILENO)
			exit(1);
		else
			execute(pipepath, envp, cmd);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_vars	pipepath;

	if (argc == 5)
	{
		pipepath.fdin = check_file(argv[1], INFILE);
		pipepath.fdout = check_file(argv[4], OUTFILE);
		dup2(pipepath.fdin, STDIN_FILENO);
		dup2(pipepath.fdout, STDOUT_FILENO);
		child_processing(&pipepath, envp, argv[2]);
		execute(&pipepath, envp, argv[3]);
		free_stack(&pipepath);
	}
	else
		ft_putstr_fd("Error: Execute as ./pipex file1 cmd1 cmd2 file2\n",
			STDERR_FILENO);
	return (0);
}
