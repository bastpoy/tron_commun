/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:25:25 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/06 14:44:10 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error_code(t_pipex *pipex, char **argv, int argc, int errcode)
{
	if (errcode == 1)
	{
		pipex->errorcode[0] = 1;
		perror(pipex->args[0][0]);
	}
	if (errcode == 2)
	{
		if (argv[argc - 1][0] == '\0')
			pipex->errorcode[1] = 2;
		else
			pipex->errorcode[1] = 1;
	}
	return (0);
}

int	print_error(int errcode, t_pipex *pipex, int path)
{
	if (errcode == 1)
	{
		if (pipex->errorcode[2] == 1)
			perror(" ");
		else
			perror(pipex->path);
	}
	if (errcode == 3)
	{
		if (pipex->errorcode[3] == 1)
			perror(" ");
		else
			perror(pipex->path);
	}
	if (errcode == 2)
	{
		ft_putstr_fd("command not found : ", STDOUT_FILENO);
		if (pipex->args[path][0])
			ft_putstr_fd(pipex->args[path][0], STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	close_fd(pipex, 1);
	free_all(pipex);
	exit(errno);
	return (0);
}

char	*check_access(t_pipex *pipex, int indice)
{
	char	*path;
	int		i;

	i = 0;
	if (!pipex->envp)
		return (NULL);
	if (pipex->args[indice][0] && (ft_strchr(pipex->args[indice][0], '/') != 0
			|| ft_strncmp(pipex->args[indice][0], ".", 1) == 0))
		return (pipex->args[indice][0]);
	while (pipex->envp[i] && pipex->args[indice][0])
	{
		path = ft_strjoin(pipex->envp[i], pipex->args[indice][0]);
		if (!access(path, F_OK))
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

void	get_fd(t_pipex *pipex, char **argv, int argc)
{
	pipex->fd[0] = open(argv[1], O_RDONLY, 0644);
	if (pipex->fd[0] < 0)
		error_code(pipex, argv, argc, 1);
	pipex->fd[1] = open(argv[argc - 1], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (pipex->fd[1] < 0)
		error_code(pipex, argv, argc, 2);
}
