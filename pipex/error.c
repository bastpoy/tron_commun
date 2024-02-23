/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:25:25 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/23 15:25:25 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

void error(char *err)
{
    perror(err);
    exit(1);
}

void error_free(const char *err, t_pipex *pipex, int errorcode)
{
    (void)errorcode;
    perror(err);
    free_threedim(pipex->args);
    free_twodim(pipex->envp);
    exit(1);
}

void error_code(t_pipex *pipex)
{
    if(pipex->errorcode == 1)
    {
        fprintf(stderr, "error code %d\n", pipex->errorcode);
        write(1, "ct", 2);
        write(1,": command not found", 19);
    }
    if(pipex->errorcode == 2)
    {
        fprintf(stderr, "error code %d\n", pipex->errorcode);
        perror(pipex->path);
    }
    exit(EXIT_FAILURE);
}