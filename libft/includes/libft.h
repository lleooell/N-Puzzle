/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:33:17 by rpuccine          #+#    #+#             */
/*   Updated: 2015/03/15 09:40:10 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

void				*ft_memset(void *str, int c, size_t len);
void				ft_bzero(void *str, size_t len);
void				*ft_memcpy(void *dst, void const *src, size_t len);
void				*ft_memccpy(void *dst, void const *src, int c, size_t len);
void				*ft_memmove(void *dst, void const *src, size_t len);
void				*ft_memchr(void const *str, int c, size_t len);
int					ft_memcmp(void const *s1, void const *s2, size_t len);

size_t				ft_strlen(char const *str);
char				*ft_strdup(char const *str);
char				*ft_strcpy(char *dst, char const *src);
char				*ft_strncpy(char *dst, char const *src, size_t len);
char				*ft_strcat(char *dst, char const *src);
char				*ft_strncat(char *dst, char const *src, size_t len);
size_t				ft_strlcat(char *dst, char const *src, size_t size);
char				*ft_strconcat(char *s1, char *s2);
int					ft_strnconcat(char **s1, char *s2, size_t n);
char				*ft_strchr(char const *str, int c);
char				*ft_strrchr(char const *str, int c);
char				*ft_strstr(char const *str, char const *chr);
char				*ft_strnstr(char const *str, char const *chr, size_t len);
int					ft_strcmp(char const *s1, char const *s2);
int					ft_strncmp(char const *s1, char const *s2, size_t len);
int					ft_atoi(char const *str);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isspace(char c);

int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *str);

void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strsub(char const *str, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *str);
char				**ft_strsplit(const char *s, char c);
char				*ft_itoa(int n);

void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putendl(char const *str);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *str, int fd);
void				ft_putendl_fd(char const *str, int fd);
void				ft_putnbr_fd(int n, int fd);

#endif
