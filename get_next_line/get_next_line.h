/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:14:29 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/30 14:16:34 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#define NO_FREE 0
#define FREE 1

#define NEXTBACKN 0
#define NONEXTBACKN 1

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

#include <stdlib.h>
#include <unistd.h>

size_t ft_strlen(const char *str);
size_t ft_strlcpy(char *dest, char *src, size_t size);
char *ft_strjoin(char const *s1, char const *s2);
char *get_next_line(int fd);

#endif