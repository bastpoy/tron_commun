/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:14:29 by bpoyet            #+#    #+#             */
/*   Updated: 2023/12/04 15:57:54 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define NO_FREE 0
# define FREE 1

# define NEXTBACKN 0
# define NONEXTBACKN 1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str, int nextbackn);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2, int freearg);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src, int freesrc, int nextbackn);
char	*get_next_line(int fd);

#endif