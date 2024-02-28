/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:25:25 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/27 18:43:18 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int error_code(t_pipex *pipex, int errcode, char *str)
{
	if (errcode == 0)
		perror(str);
	if (errcode == 1)
	{
		ft_putstr_fd(str, 1);
		exit(EXIT_FAILURE);
	}
	if (errcode == 2)
		perror(pipex->path);
	if (errcode == 3 || errcode == 4)// cas de fd[0] pas ouvert
	{
        if (errcode == 3)
            pipex->errorcode = 1;
		if(errcode == 4)
            pipex->errorcode = 2;
        perror(str);
		return (0);
	}
	close_fd(pipex);
	free_threedim(pipex->args);
	free_twodim(pipex->envp);
	exit(EXIT_FAILURE);
}

void error_code1(t_pipex *pipex, int errcode)
{
	if (errcode == 1 || errcode == 2)
    {
        if(errcode == 1)
		    close(pipex->fd[1]);
        if(errcode == 2)
            close(pipex->fd[0]);
		close(pipex->fdpipe[0]);
		close(pipex->fdpipe[1]);
	}
    if(errcode == 3 || errcode == 4)
    {
        if(errcode == 3)
            close(pipex->fdpipe[1]);
        if(errcode == 4)
            close(pipex->fdpipe[0]);
        close(pipex->fd[1]);
        close(pipex->fd[0]);
    }
    free_threedim(pipex->args);
    free_twodim(pipex->envp);
    exit(1);
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
