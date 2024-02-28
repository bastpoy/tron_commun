/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:12:50 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/27 18:41:21 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void get_env(char *envp[], t_pipex *pipex)
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
}

static void get_args(char *argv[], t_pipex *pipex, int argc)
{
	int i;
	int j;

	i = 0;
	j = 1;
	pipex->args = (char ***)malloc(sizeof(char **) * argc);
	pipex->errorcode = 0;
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

static void second_child(t_pipex *pipex)
{
	pipex->pid2 = fork();
	if (pipex->pid2 == -1)
		perror("Proc error");
	if (pipex->pid2 == 0)
	{
		if (dup2(pipex->fd[1], STDOUT_FILENO) == -1) // envoie le contenu de la sortie standard dans le fichier en écriture
			error_code1(pipex, 2);
		if (dup2(pipex->fdpipe[0], STDIN_FILENO) == -1) // envoie le contenu du pipe dans l'entrée standard en lecture
			error_code1(pipex, 3);
		close(pipex->fdpipe[0]);
		close(pipex->fd[1]);
		pipex->path = check_access(pipex, 2);
		execve(pipex->path, pipex->args[2], NULL);
		error_code(pipex, 2, "");
	}
}

static void first_child(t_pipex *pipex)
{
	pipex->pid1 = fork();
	if (pipex->pid1 == -1)
		perror("Proc error");
	if (pipex->pid1 == 0)
	{
		if (dup2(pipex->fd[0], STDIN_FILENO) == -1)
            error_code1(pipex, 1);
		if (dup2(pipex->fdpipe[1], STDOUT_FILENO) == -1)
            error_code1(pipex, 4);
		close(pipex->fdpipe[1]);
        close(pipex->fd[0]);
		pipex->path = check_access(pipex, 1);
		execve(pipex->path, pipex->args[1], NULL);
		error_code(pipex, 2, "");
	}
}

int main(int argc, char *argv[], char *envp[])
{
	t_pipex pipex;

	if (argc == 5)
	{
		get_env(envp, &pipex);
		get_args(argv, &pipex, argc);
		if (pipe(pipex.fdpipe) == -1)
			error_code(&pipex, 0, "Pipe error");
		pipex.fd[0] = open(argv[1], O_RDONLY, 0644);
		if (pipex.fd[0] < 0)
			error_code(&pipex, 3, argv[1]);
		pipex.fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (pipex.fd[1] < 0)
			error_code(&pipex, 4, argv[argc - 1]);
		first_child(&pipex);
		second_child(&pipex);
		close_fd(&pipex);
		waitpid(pipex.pid1, NULL, 0);
		waitpid(pipex.pid2, NULL, 0);
		free_all(pipex.args, pipex.envp);
	}
	else
		error_code(&pipex, 1, "Bad arguments");
	return (0);
}
