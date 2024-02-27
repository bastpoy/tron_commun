/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:25:25 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/27 11:26:54 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void error_free(const char *err, t_pipex *pipex)
{
	(void)err;
	// perror(err);
	free_threedim(pipex->args);
	free_twodim(pipex->envp);
	exit(1);
}

int error_code(t_pipex *pipex, int errcode, char *str)
{
	if (errcode == 0)
	{
		perror(str);
	}
	if (errcode == 1)
	{
		ft_putstr_fd(str, 1);
		exit(EXIT_FAILURE);
	}
	if (errcode == 2)
		perror(pipex->path);
	if (errcode == 3)
	{
		perror(str);
		return (0);
		// exit(1);
	}
	if (errcode == 4)
	{

		exit(1);
	}
	close_fd(pipex);
	free_threedim(pipex->args);
	free_twodim(pipex->envp);
	exit(EXIT_FAILURE);
	return (0);
}

char *check_access(t_pipex *pipex, int indice)
{
	char *path;
	int i;

	i = 0;
	if (ft_strncmp(pipex->args[indice][0], "/", 1) == 0 || ft_strncmp(pipex->args[indice][0], "./", 2) == 0 || ft_strncmp(pipex->args[indice][0], "../", 3) == 0)
		return (pipex->args[indice][0]);
	while (pipex->envp[i])
	{
		path = ft_strjoin(pipex->envp[i], pipex->args[indice][0]);
		if (!access(path, X_OK))
			return (path);
		free(path);
		i++;
	}
	return (pipex->args[indice][0]);
}
