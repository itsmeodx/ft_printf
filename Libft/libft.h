/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:34:17 by oouaadic          #+#    #+#             */
/*   Updated: 2024/04/16 18:32:38 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <limits.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

/* ************************************************************************** */
/*                                 STRUCT                                     */
/* ************************************************************************** */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* ************************************************************************** */
/*                                  CHECK                                     */
/* ************************************************************************** */

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);

/* ************************************************************************** */
/*                                 MEMORY                                     */
/* ************************************************************************** */

void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t n);
void				*ft_memchr(void const *str, int c, size_t n);
int					ft_memcmp(void const *s1, void const *s2, size_t n);
void				*ft_memcpy(void *dest, void const *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *str, int c, size_t n);

/* ************************************************************************** */
/*                                  PRINT                                     */
/* ************************************************************************** */

int					ft_putchar_fd(char c, int fd);
int					ft_putchar(char c);
int					ft_putendl_fd(char *s, int fd);
int					ft_putendl(char *s);
int					ft_putnbr_fd(int n, int fd);
int					ft_putnbr(int n);
int					ft_putnbr_base(long n, int base);
int					ft_putstr_fd(char *s, int fd);
int					ft_putstr(char *s);

/* ************************************************************************** */
/*                                 STRING                                     */
/* ************************************************************************** */

int					ft_atoi(char const *str);
char				*ft_itoa(int n);
char				**ft_split(char const *s, char c);
char				*ft_strchr(char const *str, int c);
char				*ft_strdup(char const *src);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
size_t				ft_strlcpy(char *dest, char const *src, size_t n);
size_t				ft_strlen(char const *str);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(char const *s1, char const *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strnstr(char const *haystack, char const *needle,
						size_t n);
char				*ft_strrchr(char const *str, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);

/* ************************************************************************** */
/*                                   LIST                                     */
/* ************************************************************************** */

void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);

#endif
