/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:12:50 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/23 23:34:24 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char *check_access(t_pipex *pipex, int indice)
{
    char *path;
    int i;

    i = 0;
    if (ft_strncmp(pipex->args[indice][0], "/", 1) == 0)
        return (pipex->args[indice][0]);
    while (pipex->envp[i])
    {
        path = ft_strjoin(pipex->envp[i], pipex->args[indice][0]);
        if (!access(path, X_OK))
            return (path);
        free(path);
        i++;
    }
    fprintf(stderr, "%s\n\n\n", pipex->args[indice][0]);
    return (pipex->args[2][0]);
}

static char **get_env(char *envp[])
{
    int i = -1;
    int j;

    j = 0;
    char **envsplit;
    while (envp[++i])
    {
        if (ft_strncmp(envp[i], "PATH=", 5) == 0)
        {
            envsplit = ft_split(ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i]) + 5), ':');
            while (envsplit[j])
            {
                envsplit[j] = ft_strjoin(envsplit[j], "/");
                j++;
            }
            envsplit[j] = NULL;
            return (envsplit);
        }
    }
    return NULL;
}

static void get_args(char *argv[], t_pipex *pipex, int argc)
{
    int i = 0;
    int j = 1;
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

static void second_child(t_pipex *pipex, int fd[2])
{
    pipex->pid2 = fork();
    if (pipex->pid2 == -1)
        perror("Proc error");
    if (pipex->pid2 == 0)
    {
        if (dup2(fd[0], STDIN_FILENO) == -1)
            error_free("error", pipex, 0);
        close(fd[1]);
        if (dup2(pipex->fd[1], STDOUT_FILENO) == -1)
            error_free("error", pipex, 0);
        pipex->path = check_access(pipex, 2);
        execve(pipex->path, pipex->args[2], NULL);
    }
    error_code(pipex, 2);
}

static void first_child(t_pipex *pipex, int fd[2])
{
    pipex->pid1 = fork();
    if (pipex->pid1 == -1)
        perror("Proc error");
    if (pipex->pid1 == 0)
    {
        if (dup2(pipex->fd[0], STDIN_FILENO) == -1)
            error_free("error", pipex, 0);
        if (dup2(fd[1], STDOUT_FILENO) == -1)
            error_free("error", pipex, 0);
        close(fd[0]);
        pipex->path = check_access(pipex, 1);
        execve(pipex->path, pipex->args[1], NULL);
    }
    error_code(pipex, 2);
}

int main(int argc, char *argv[], char *envp[])
{
    t_pipex pipex;
    int fd[2];

    if (pipe(fd) == -1)
    {
        close_fd(fd);
        perror("Pipe Error");
    }
    pipex.fd[0] = open(argv[1], O_RDONLY);
    if (pipex.fd[0] < 0)
        error(argv[1]);
    pipex.fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (pipex.fd[1] < 0)
        error(argv[argc - 1]);
    pipex.envp = get_env(envp);
    get_args(argv, &pipex, argc);
    first_child(&pipex, fd);
    second_child(&pipex, fd);
    close_fd(fd);
    waitpid(pipex.pid1, NULL, 0);
    waitpid(pipex.pid2, NULL, 0);
    return (0);
}
