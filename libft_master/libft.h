/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkanaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:06:33 by alkanaev          #+#    #+#             */
/*   Updated: 2019/11/25 16:24:41 by alkanaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
								void (*del)(void *));
char				*ft_strtrim(char const *s1, char const *set);
int					ft_atoi(const char *str);
void				ft_bzero(void *smt, size_t len);
void				*ft_calloc(size_t num, size_t size);
int					ft_isalnum(int sym);
int					ft_isalpha(int sym);
int					ft_isascii(int sym);
int					ft_isdigit(int sym);
int					ft_isprint(int sym);
char				*ft_itoa(int n);
void				*ft_memccpy(void *dest, const void *src, int sym,
								size_t len);
void				*ft_memchr(const void *smt, int sym, size_t len);
int					ft_memcmp(const void *smt1, const void *smt2, size_t len);
void				*ft_memcpy(void *dest, const void *src, size_t len);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memset(void *smt, int sym, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *str, int sym);
char				*ft_strdup(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *str1, const char *str2, size_t len);
char				*ft_strnstr(const char *where, const char *obj, size_t len);
char				*ft_strrchr(const char *str, int sym);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int sym);
int					ft_toupper(int sym);

#endif
