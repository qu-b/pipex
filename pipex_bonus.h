/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcullen <fcullen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:16:26 by fcullen           #+#    #+#             */
/*   Updated: 2022/12/08 16:06:06 by fcullen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>

// Pipex Structure
typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		tube[2];
	int		infile;
	int		outfile;
	char	*env_paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}			t_pipex;

// Utilities
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char *str, char c);

// Child Processes
void	first_child(t_pipex pipex, char *argv[], char *envp[]);
void	second_child(t_pipex pipex, char *argv[], char *envp[]);
void	child_process(t_pipex pipex, char *argv, char *envp[]);
void	redirection(t_pipex pipex, char *argv, char *envp[]);
void	child(t_pipex pipex, char *argv, char *envp[]);

// Free
void	free_pip(t_pipex *pipex);
void	child_free(t_pipex *pipex);

// Error Handling
int		msg(char *err);
void	msg_error(char *err);

#endif