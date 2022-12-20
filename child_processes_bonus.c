/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcullen <fcullen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:44:11 by fcullen           #+#    #+#             */
/*   Updated: 2022/12/08 20:12:33 by fcullen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, F_OK) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}
void	child(t_pipex pipex, char *argv, char *envp[])
{
	pipex.cmd_args = ft_split(argv, ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		child_free(&pipex);
		msg("Command not found\n");
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	redirection(t_pipex pipex, char *argv, char *envp[])
{
	pipe(pipex.tube);
	pipex.pid1 = fork();
	if (pipex.pid1)
	{
		close(pipex.tube[1]);
		dup2(pipex.tube[0], 0);
		waitpid(pipex.pid1, NULL, 0);
	}
	else
	{
		close(pipex.tube[0]);
		dup2(pipex.tube[1], 1);
		if (pipex.infile == 0)
			exit(1);
		else
			child(pipex, argv, envp);
	}
}
