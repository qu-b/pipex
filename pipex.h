/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcullen <fcullen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:07:29 by fcullen           #+#    #+#             */
/*   Updated: 2023/01/09 15:21:14 by fcullen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>

# define STD_IN 0
# define STD_OUT 1
# define STD_ERR 2

# define INFILE 0
# define OUTFILE 1

# define ERR_ARGS "Invalid number of arguments"

char	*find_path(char **envp);
void	exec(char *cmd, char **envp);
void	redirect(char *cmd, char **env, int fdin);

int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char *str, char c);

#endif