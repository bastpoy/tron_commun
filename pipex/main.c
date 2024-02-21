/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:12:50 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/22 00:17:58 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Je vai fork une premiere fois dans mon main
// Dans le processus fils je vais appeler la fonction qui va pipe
// je pipe avant puis je fork ce pipe
// ce qui va dupliquer mon pipe

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
    i = 0;
    // while (pipex->args[1])
    // {
    // j = 0;
    // while (pipex->args[1][j])
    // {
    //     printf("%s\n", pipex->args[1][j]);
    //     j++;
    // }
    //     i++;
    // }
}

static int run_pipe(int argc, char *argv[], t_pipex pipex)
{
    int fd[2];
    pid_t pid;

    pipex.fd[0] = open(argv[1], O_RDONLY);
    pipex.fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    get_args(argv, &pipex, argc);
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
        printf("processecus fils\n");
        if (dup2(pipex.fd[0], STDIN_FILENO) == -1)
            strerror(errno);
        if (dup2(fd[1], STDOUT_FILENO) == -1)
            strerror(errno);
        close(fd[0]);
        pipex.path = check_access(&pipex, 1);
        fprintf(stderr, "la %s\n", pipex.path);

        execve(pipex.path, pipex.args[1], NULL);
        free(pipex.path);
        strerror(errno);
        perror("Fail creating processus");
    }
    waitpid(pid, NULL, 0);
    printf("processecus pere\n");
    if (dup2(fd[0], STDIN_FILENO) == -1)
        printf("erreur ici\n");
    close(fd[1]);
    if (dup2(pipex.fd[1], STDOUT_FILENO) == -1)
        printf("ou la");
    pipex.path = check_access(&pipex, 2);
    execve(pipex.path, pipex.args[2], NULL);
    free(pipex.path);
    perror("Fail creating processus");
    return (0);
}

int main(int argc, char *argv[], char *envp[])
{
    t_pipex pipex;

    pipex.envp = get_env(envp);
    get_args(argv, &pipex, argc);

    run_pipe(argc, argv, pipex);

    free_threedim(pipex.args);
    free_twodim(pipex.envp);
    return (0);
}
