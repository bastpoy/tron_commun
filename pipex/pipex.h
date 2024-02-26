/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:44:06 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/23 23:24:41 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	char	***args;
	char	**envp;
	char	*path;
	int		argcount;
	int		errorcode;
	int		fd[2];
	int		fdpipe[2];
	pid_t	pid1;
	pid_t	pid2;
}			t_pipex;

void		free_all(char ***args, char **envp);
void		free_threedim(char ***array);
void		free_twodim(char **array);

void		error_code(t_pipex *pipex, int errcode, char *str);
void		error_free(const char *err, t_pipex *pipex);
char		*check_access(t_pipex *pipex, int indice);
void		close_fd(t_pipex *pipex);

#endif