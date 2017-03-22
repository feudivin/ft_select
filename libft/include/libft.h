/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:43:18 by jfourne           #+#    #+#             */
/*   Updated: 2017/03/10 16:09:33 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <time.h>
# include <dirent.h>
# include <sys/types.h>
# include <uuid/uuid.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>
# include <time.h>

typedef struct		s_size
{
	int				x;
	int				y;
}					t_size;


typedef struct		s_list
{
	int				cursor;
	int				select;
	char			*content;
	size_t			content_size;
	t_size			coord;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, int a);
char				*ft_strdup_clean(char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *litlle);
char				*ft_strnstr(const char *big, const char *litlle,
								size_t len);
char				*ft_itoa(int n);
int					ft_atoi(const char *str);
void				ft_putchar(char c);
void				ft_putnbr(int n);
void				ft_putstr(const char *s);
void				ft_putendl(char const *s);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strnjoin(char *s1, char *s2, int length);
char				*ft_strjoin_and_clean(char *s1, char *s2, int clean);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
t_list				*ft_lstnew(char const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alist, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_ispos(int nb);
int					ft_isneg(int nb);
int					ft_isspace(char *str);
void				ft_lstback(t_list **alst, t_list *elem);
void				ft_lstback_circle(t_list **alst, t_list *elem,
					int nb_elem);
void				ft_lstprint(t_list *lst);
void				ft_lstprintl(t_list *lst);
int					ft_count_word(const char *str);
void				ft_tab_clean(char ***tab);
t_list				*ft_tab_to_list(char **tab);
t_list				*ft_tab_to_list_circle(char **tab);
char				**ft_lst_to_tab(t_list *lst);
int					get_next_line(const int fd, char **line);
void				ft_lstfree(t_list **first);
int					ft_lstfree_one(t_list **alst, t_list **tmp);
t_list				*ft_lstcpy(t_list *alst);
int					ft_strisalpha(char *str);
int					ft_strisalnum(char *str);

#endif
