/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:45:23 by hai               #+#    #+#             */
/*   Updated: 2024/05/19 10:39:22 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t num, size_t size);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *dest, int c, size_t len);
void			ft_putchar_fd(char c, int fd);
void			ft_putchar(char c);
void			ft_putendl_fd(char *s, int fd);
void			ft_putendl(char *s);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr(int nb);
void			ft_putstr_fd(char *s, int fd);
void			ft_putstr(char *str);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *str, int c);
char			*ft_strdup(const char *s);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size);
size_t			ft_strlen(const char *str);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(char *s1, char *s2, size_t n);
char			*ft_strnstr(char *str1, char *str2, size_t len);
char			*ft_strrchr(const char *str, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *str, unsigned int start, size_t len);
long			ft_atoi_l(const char *str);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
int				ft_tolower(int c);
int				ft_toupper(int c);

int				ft_printf(const char *format, ...);
int				ft_print_format(char specifier, va_list ap);
int				ft_print_char(int c);
int				ft_print_str(char *str);
int				ft_print_ptr(long long unsigned int n);
int				ft_print_digit(long n);
int				ft_printx(long unsigned int n);
int				ft_printupx(long unsigned int n);

char			*get_next_line(int fd);
char			*read_line(int fd, char *left, char *buffer);
char			*cut_line(char *line);

#endif
