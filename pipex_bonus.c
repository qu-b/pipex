/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcullen <fcullen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:59:47 by fcullen           #+#    #+#             */
/*   Updated: 2022/12/09 14:32:00 by fcullen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	close_pipes(t_pipex *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;
	int		i;

	i = 3;
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		msg_error(argv[1]);
	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex.outfile < 0)
		msg_error(argv[argc - 1]);
	if (pipe(pipex.tube) < 0)
		msg_error("Pipe");
	pipex.env_paths = find_path(envp);
	pipex.cmd_paths = ft_split(pipex.env_paths, ':');
	dup2(pipex.infile, 0);
	dup2(pipex.outfile, 1);
	redirection(pipex, argv[2], envp);
	while (i < argc - 2)
		redirection(pipex, argv[i++], envp);
	child(pipex, argv[i], envp);
	close_pipes(&pipex);
	wait(0);
	free_pip(&pipex);
	return (0);
}
