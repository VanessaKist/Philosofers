/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:46:04 by coder             #+#    #+#             */
/*   Updated: 2023/02/08 02:27:23 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_element
{
	int					content;
	long long			index; 
	int					stack_pos; 
	struct s_element	*next;
}	t_element;

long int	ft_atoi(const char *str, t_bool *error);
void		ft_bzero(void *s, size_t len);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
char		*ft_itoa(int nb);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *str, int c);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *d, const char *s, size_t n);
size_t		ft_strlcpy(char *dest, const char *src, size_t n);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strrchr(const char *str, int c);
char		*ft_strtrim(char const *s, char const *set);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_substr(char const *str, unsigned int start, size_t len);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_tolower(int c);
int			ft_toupper(int c);
char		*ft_get_next_line(int fd);
int			ft_splitlen(char **split);
void		ft_matrixfree(void **matrix);
void		ft_pointerfree(void *pointer);
int			ft_htoi(char s[]);
int			ft_lstsize(t_element *element);
t_element	*ft_lstnew(int content, int stack_pos);
t_element	*ft_lstlast(t_element *element);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_element **stack, t_element *new);

#endif
