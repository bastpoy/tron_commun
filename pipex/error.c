/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:25:25 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/23 23:35:31 by bpoyet           ###   ########.fr       */
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

void error_code(t_pipex *pipex, int errcode)
{
    if (errcode == 2)
    {
        perror(pipex->path);
    }
    free_threedim(pipex->args);
    free_twodim(pipex->envp);
    exit(EXIT_FAILURE);
}