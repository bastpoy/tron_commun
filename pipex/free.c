/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:11:42 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/22 11:27:17 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void free_all (char ***args, char **envp)
{
    free_threedim(args);
    free_twodim(envp);
}

void free_threedim(char ***array)
{
    int i;
    int j;

    i = -1;
    if (array)
    {
        while (array[++i])
        {
            j = -1;
            while (array[i][++j])
                free(array[i][j]);
            free(array[i]);
        }
        free(array);
    }
}

void free_twodim(char **array)
{
    int i;

    i = -1;
    if (array)
    {
        while (array[++i])
            free(array[i]);
        free(array);
    }
}

void close_fd(int fd[2])
{
    close(fd[0]);
    close(fd[1]);
}