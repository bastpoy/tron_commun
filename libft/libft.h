#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
#include <string.h>

int ft_atoi(char *str);
void ft_bzero(void *s, size_t n);
void *ft_calloc(size_t elementCount, size_t elementSize);
int ft_isalnum(int c);
int ft_isalpha(int c);
int ft_isascii(int c);
int ft_isdigit(int c);
int ft_isprint(int c);
void *ft_memchr(const void *str, int c, size_t size);
int ft_memcmp(const void *ptr1, const void *ptr2, size_t size);
void *ft_memcpy(void *dest, const void *src, size_t size);
void *ft_memmove(void *dest, const void *src, size_t size);
void *ft_memset(void *dest, int val, size_t len);
char *ft_strchr(const char *s, int c);
char *ft_strdup(const char *src);
char *ft_strjoin(char const *s1, char const *s2);
size_t ft_strlcat(char *dest, char *src, size_t size);
size_t ft_strlcpy(char *dest, char *src, size_t size);
size_t ft_strlen(char *str);
int ft_strncmp(char *s1, char *s2, unsigned int n);
char *ft_strnstr(const char *str, const char *to_find, size_t len);
char *ft_strrchr(const char *s, int c);
char *ft_substr(char const *s, unsigned int start, size_t len);
int ft_tolower(int c);
int ft_toupper(int c);

#endif