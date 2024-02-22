/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:17:55 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/07 11:59:28 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list1
{
	void			*content;
	struct s_list	*next;
}					t_list1;

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t elementCount, size_t elementSize);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				ft_lstadd_back(t_list1 **lst, t_list1 *new);
void				ft_lstadd_front(t_list1 **lst, t_list1 *new);
void				ft_lstclear(t_list1 **lst, void (*del)(void *));
void				ft_lstdelone(t_list1 *lst, void (*del)(void *));
void				ft_lstiter(t_list1 *lst, void (*f)(void *));
t_list1				*ft_lstlast(t_list1 *lst);
t_list1				*ft_lstmap(t_list1 *lst, void *(*f)(void *),
						void (*del)(void *));
t_list1				*ft_lstnew(void *content);
int					ft_lstsize(t_list1 *lst);
void				*ft_memchr(const void *str, int c, size_t size);
int					ft_memcmp(const void *ptr1, const void *ptr2, size_t size);
void				*ft_memcpy(void *dest, const void *src, size_t size);
void				*ft_memmove(void *dest, const void *src, size_t size);
void				*ft_memset(void *dest, int val, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *src);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, char *src, size_t size);
size_t				ft_strlcpy(char *dest, char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *str, const char *to_find,
						size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);

#endif