/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:25:25 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/01 19:32:41 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int error_code(t_pipex *pipex, int errcode)
{
	if (errcode == 1)
	{
		pipex->errorcode[0] = 1;
		perror(pipex->args[0][0]);
	}
	if (errcode == 2)
	{
		pipex->errorcode[1] = 1;
	}
	return (0);
}

int print_error(int errcode, t_pipex *pipex, int path)
{
	if (errcode == 1)
	{
		free_all(pipex);
		ft_putstr_fd(pipex->path, 2);
		// fprintf(stderr, "%s\n", strerror(errno));
		// perror(pipex->path);
		ft_putstr_fd(strerror(errno), 2);
		// perror("");
		exit(EXIT_FAILURE);
	}
	if (errcode == 2)
	{
		ft_putstr_fd("command not found : ", STDOUT_FILENO);
		ft_putstr_fd(pipex->args[path][0], STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		free_all(pipex);
		exit(EXIT_FAILURE);
	}
	return (0);
}

char *check_access(t_pipex *pipex, int indice)
{
	char *path;
	int i;

	i = 0;
	if (ft_strncmp(pipex->args[indice][0], "/", 1) == 0 || ft_strncmp(pipex->args[indice][0], ".", 1) == 0)
	{
		fprintf(stderr, "la %s\n", pipex->args[indice][0]);
		return (pipex->args[indice][0]);
	}

	while (pipex->envp[i])
	{
		path = ft_strjoin(pipex->envp[i], pipex->args[indice][0]);
		if (!access(path, F_OK))
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}
