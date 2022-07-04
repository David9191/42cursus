/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:55:20 by jislim            #+#    #+#             */
/*   Updated: 2021/11/09 15:55:20 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "limits.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_stacknode_type
{
	int						data;
	int						index;
	struct s_stacknode_type	*p_link;
}							t_stacknode;

typedef struct s_linked_satck_type
{
	int			*arr;
	int			current_element_cnt;
	t_stacknode	*p_top_element;
}				t_stack;

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
size_t			ft_strlen(const char *s);
void			*ft_memset(void *dest, int c, size_t n);
void			ft_bzero(void *b, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_memchr(const void *b, int c, size_t n);
int				ft_memcmp(const void *b1, const void *b2, size_t n);
char			*ft_strnstr(const char *s1, const char *s2, size_t size);
int				ft_atoi(const char *str);
long long		ft_atoll(const char *nptr);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);

char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putusnbr_fd(unsigned int n, int fd);

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

size_t			ft_strchr_gnl(char *str, int to_find);
size_t			ft_strlen_gnl(char *str);
char			*ft_strjoin_gnl(char *backup, char *buf);
char			*get_line_endl(char *str);
char			*save_backup(char *str);
char			*get_line(int fd, char *backup);
char			*get_next_line(int fd);

int				ft_printf(const char *format, ...);
int				print_usnbr(unsigned int us_nbr);
int				print_str(char *str);
int				print_hexa(unsigned int hexa, char conv);
int				print_nbr(int nbr);
int				print_char(int ch);
int				print_hexa_ptr(unsigned long hexa);
char			*printf_hexa(void *v_ptr);

t_stack			*create_linked_stack(void);
int				push_linked_stack(t_stack *p_stack, t_stacknode element);
t_stacknode		*pop_linked_stack(t_stack *p_stack);
t_stacknode		*peek_linked_stack(t_stack *p_stack);
void			delete_linked_stack(t_stack *p_stack);
int				is_linked_stack_empty(t_stack *p_stack);

int             ft_double_free(char **ptr);
int				ft_doublep_len(char **dp);

# define TRUE	1
# define FALSE	0
# define BUFFER_SIZE 42

#endif
