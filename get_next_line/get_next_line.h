/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:14:29 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/28 18:53:08 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#define NO_FREE 0
#define FREE 1

#define WITH 0
#define WITHOUT 1

#define NEXTBACKN 1
#define NONEXTBACKN 0

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

#include <stdlib.h>
#include <unistd.h>

size_t ft_strlen(const char *str);
size_t ft_strlcpy(char *dest, char *src, size_t size);
char *ft_strjoin(char const *s1, char const *s2);

#endif