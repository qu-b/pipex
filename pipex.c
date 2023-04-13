/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcullen <zaphod42@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:06:21 by fcullen           #+#    #+#             */
/*   Updated: 2023/03/20 17:43:33 by fcullen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	openfile(char *filename, int mode)
{
	if (mode == INFILE)
	{
		if (access(filename, F_OK))
		{
			write(STD_ERR, "pipex: ", 7);
			write(STD_ERR, filename, ft_strlen(filename));
			write(STD_ERR, ": No such file or directory\n", 28);
			return (0);
		}
		if (access(filename, R_OK))
		{
			write(STD_ERR, "pipex: ", 7);
			write(STD_ERR, filename, ft_strlen(filename));
			write(STD_ERR, ": Permission denied\n", 20);
			return (0);
		}
		else
			return (open(filename, O_RDONLY));
	}
	else
		return (open(filename, O_TRUNC | O_CREAT | O_RDWR, 0000644));
}

int	main(int ac, char **av, char **envp)
{
	int	fdin;
	int	fdout;

	if (ac == 5)
	{
		fdin = openfile(av[1], INFILE);
		fdout = openfile(av[4], OUTFILE);
		dup2(fdin, STD_IN);
		dup2(fdout, STD_OUT);
		redirect(av[2], envp, fdin);
		exec(av[3], envp);
	}
	else
		write(STD_ERR, "Invalid number of arguments.\n", 29);
	return (1);
}
