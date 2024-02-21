/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:44:06 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/21 23:06:39 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#define BYTESREAD 5000

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#include "libft/libft.h"

typedef struct s_pipex
{
    char ***args;
    char **envp;
    char *path;
    int argcount;
    int fd[2];
} t_pipex;

void free_threedim(char ***array);
void free_twodim(char **array);

#endif