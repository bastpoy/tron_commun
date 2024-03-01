/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:12:50 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/01 18:58:54 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void get_args(char *argv[], t_pipex *pipex, int argc)
{
	int i;
	int j;

	i = 0;
	j = 1;
	pipex->args = (char ***)malloc(sizeof(char **) * argc);
	pipex->errorcode[0] = 0;
	pipex->errorcode[1] = 0;
	if (!pipex->args)
		perror("Malloc error");
	while (argv[j])
	{
		pipex->args[i] = ft_split(argv[j], ' ');
		i++;
		j++;
	}
	pipex->args[i] = NULL;
}

static void get_env_args(char *envp[], t_pipex *pipex, char **argv, int argc)
{
	int i;
	int j;
	char *temp;

	i = -1;
	j = 0;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			pipex->envp = ft_split(envp[i] + 5, ':');
			while (pipex->envp[j])
			{
				temp = ft_strjoin(pipex->envp[j], "/");
				free(pipex->envp[j]);
				pipex->envp[j] = temp;
				j++;
			}
			pipex->envp[j] = NULL;
		}
	}
	get_args(argv, pipex, argc);
}

static void second_child(t_pipex *pipex)
{
	pipex->pid2 = fork();
	if (pipex->pid2 == -1)
		perror("Proc error");
	if (pipex->pid2 == 0)
	{
		pipex->path = check_access(pipex, 2);
		if (!pipex->path)
			print_error(2, pipex, 2);
		dup2(pipex->fd[1], STDOUT_FILENO);
		dup2(pipex->fdpipe[0], STDIN_FILENO);
		close(pipex->fdpipe[1]);
		close(pipex->fdpipe[0]);
		close(pipex->fd[1]);
		execve(pipex->path, pipex->args[2], NULL);
		print_error(1, pipex, 0);
	}
}

static void first_child(t_pipex *pipex)
{
	pipex->pid1 = fork();
	if (pipex->pid1 == -1)
		perror("Proc error");
	if (pipex->pid1 == 0)
	{
		pipex->path = check_access(pipex, 1);
		fprintf(stderr, "%s\n", pipex->path);
		if (!pipex->path)
			print_error(2, pipex, 1);
		dup2(pipex->fd[0], STDIN_FILENO);
		dup2(pipex->fdpipe[1], STDOUT_FILENO);
		close(pipex->fdpipe[1]);
		close(pipex->fdpipe[0]);
		close(pipex->fd[0]);
		execve(pipex->path, pipex->args[1], NULL);
		print_error(1, pipex, 0);
	}
}

int main(int argc, char *argv[], char *envp[])
{
	t_pipex pipex;

	if (argc == 5)
	{
		get_env_args(envp, &pipex, argv, argc);
		if (pipe(pipex.fdpipe) == -1)
			exit(EXIT_FAILURE);
		pipex.fd[0] = open(argv[1], O_RDONLY, 0644);
		if (pipex.fd[0] < 0)
			error_code(&pipex, 1);
		if (pipex.errorcode[0] == 0)
			first_child(&pipex);
		pipex.fd[1] = open(argv[argc - 1], O_TRUNC | O_CREAT | O_WRONLY, 0644);
		if (pipex.fd[1] < 0)
			error_code(&pipex, 2);
		if (pipex.errorcode[1] == 0)
			second_child(&pipex);
		close_fd(&pipex);
		if (pipex.errorcode[0] == 0)
			waitpid(pipex.pid1, NULL, 0);
		if (pipex.errorcode[1] == 0)
			waitpid(pipex.pid2, NULL, 0);
		free_all(&pipex);
	}
	return (0);
}
