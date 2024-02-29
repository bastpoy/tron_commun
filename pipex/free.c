/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:11:42 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/27 18:24:41 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(char ***args, char **envp)
{
	free_threedim(args);
	free_twodim(envp);
}

void	free_threedim(char ***array)
{
	int	i;
	int	j;

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

void	free_twodim(char **array)
{
	int	i;

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

void	close_fd(t_pipex *pipex)
{
	if (pipex->errorcode == 0)
	{
		close(pipex->fdpipe[0]);
		close(pipex->fdpipe[1]);
		close(pipex->fd[1]);
		close(pipex->fd[0]);
	}
	if (pipex->errorcode == 1)
	{
		close(pipex->fdpipe[0]);
		close(pipex->fdpipe[1]);
		close(pipex->fd[1]);
	}
	if (pipex->errorcode == 2)
	{
		close(pipex->fdpipe[0]);
		close(pipex->fdpipe[1]);
		close(pipex->fd[0]);
	}
}
