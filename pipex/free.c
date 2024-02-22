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

void free_threedim(char ***array)
{
    int i;
    int j;

    i = 0;
    if (array)
    {
        while (array[i])
        {
            j = 0;
            while (array[i][j])
            {
                free(array[i][j]);
                j++;
            }
            free(array[i]);
            i++;
        }
        free(array);
    }
}

void free_twodim(char **array)
{
    int i;

    i = 0;
    if (array)
    {
        while (array[i])
        {
            free(array[i]);
            i++;
        }
        free(array);
    }
}

void error(char *err)
{
    perror(err);
    exit(1);
}

void error_free(char *err, t_pipex *pipex)
{
    free_threedim(pipex->args);
    free_twodim(pipex->envp);
    perror(err);
    exit(1);
}