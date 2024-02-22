/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:14:29 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/22 13:40:49 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define NO_FREE 0
# define FREE 1

# define NEXTBACKN 0
# define NONEXTBACKN 1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlcpy(char *dest, char *src, size_t size);
char	*ft_strjoin1(char const *s1, char const *s2, int pi);
char	*ft_strchr1(const char *s, int c);
char	*ft_strdup1(const char *src, int freesrc, int nextbackn, int pi);
char	*get_next_line(int fd);
void	*ft_free(const char *a, int pi);
char	*ft_modifyoverflow(char *buffer, char *overflow, char **ptrbuffer);
char	*ft_readline(char *buffer, int fd);
char	*ft_nextoverflow(char *overflow);

#endif