/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:11:42 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/02 16:18:22 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void free_all(t_pipex *pipex)
{
	if (pipex->errorcode[1] == 1)
	{
		ft_putstr_fd(pipex->args[3][0], 1);
		ft_putstr_fd(" : Permission denied\n", 1);
	}
	// free(pipex->path);
	free_threedim(pipex->args);
	free_twodim(pipex->envp);
}

void free_threedim(char ***array)
{
	int i;
	int j;

	i = -1;
	if (array)
	{
		while (array[++i])
		{
			j = -1;
			while (array[i][++j])
				free(array[i][j]);
			free(array[i]);
		}
		free(array);
		array = NULL;
	}
}

void free_twodim(char **array)
{
	int i;

	i = -1;
	if (array)
	{
		while (array[++i])
		{
			free(array[i]);
		}
		free(array);
		array = NULL;
	}
}

void close_fd(t_pipex *pipex)
{
	if (pipex->errorcode[0] == 0)
		close(pipex->fd[0]);
	if (pipex->errorcode[1] == 0)
		close(pipex->fd[1]);
	close(pipex->fdpipe[0]);
	close(pipex->fdpipe[1]);
}
