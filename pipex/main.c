/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:12:50 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/22 11:33:44 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char *check_access(t_pipex *pipex, int indice)
{
    char *path;
    int i;

    i = 0;
    while (pipex->envp[i])
    {
        path = ft_strjoin(pipex->envp[i], pipex->args[indice][0]);
        if (!access(path, X_OK))
            return (path);
        i++;
    }
    free(path);
    return (NULL);
}

static char **get_env(char *envp[])
{
    int i;
    int j;
    char **envsplit;

    j = 0;
    i = 0;
    while (envp[i])
    {
        if (ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])))
        {
            envsplit = ft_split(ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])) + 5, ':');
            while (envsplit[j])
            {
                envsplit[j] = ft_strjoin(envsplit[j], "/");
                printf("%s\n", envsplit[j]);
                j++;
            }
            envsplit[j] = NULL;
            return (envsplit);
        }
        i++;
    }
    return (NULL);
}

static void get_args(char *argv[], t_pipex *pipex, int argc)
{
    int i = 0;
    int j = 1;
    pipex->args = (char ***)malloc(sizeof(char **) * argc);
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

static int run_pipe(t_pipex pipex)
{
    int fd[2];
    pid_t pid;

    if (pipe(fd) == -1)
    {
        close(fd[0]);
        close(fd[1]);
        perror("Pipe Error");
    }
    pid = fork();
    if (pid == -1)
        perror("Fork error");
    if (pid == 0)
    {
        if (dup2(pipex.fd[0], STDIN_FILENO) == -1)
            error_free("error", &pipex);
        if (dup2(fd[1], STDOUT_FILENO) == -1)
            error_free("error", &pipex);
        close(fd[0]);
        pipex.path = check_access(&pipex, 1);
        if (!pipex.path)
            error_free(pipex.path, &pipex);
        fprintf(stderr, "path %s\n", pipex.path);
        execve(pipex.path, pipex.args[1], NULL);
        error_free("error", &pipex);
    }
    waitpid(pid, NULL, 0);
    if (dup2(fd[0], STDIN_FILENO) == -1)
        error_free("error", &pipex);
    close(fd[1]);
    if (dup2(pipex.fd[1], STDOUT_FILENO) == -1)
        error_free("error", &pipex);
    pipex.path = check_access(&pipex, 2);
    execve(pipex.path, pipex.args[2], NULL);
    error_free("error", &pipex);
    return (0);
}

int main(int argc, char *argv[], char *envp[])
{
    t_pipex pipex;
    int i = 0;
    while (pipex.envp[i])
    {
        printf("%s\n", envp[i]);
        i++;
    }
    pipex.fd[0] = open(argv[1], O_RDONLY);
    if (pipex.fd[0] < 0)
        error(argv[1]);
    pipex.fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (pipex.fd[1] < 0)
        error(argv[argc - 1]);
    pipex.envp = get_env(envp);
    get_args(argv, &pipex, argc);
    run_pipe(pipex);

    free_threedim(pipex.args);
    free_twodim(pipex.envp);
    return (0);
}
