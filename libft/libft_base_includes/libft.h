/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:32:16 by juuttera          #+#    #+#             */
/*   Updated: 2020/07/09 01:14:06 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE_GNL 16
# define FD_MAX_GNL 4096

# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar_fd(char c, int fd);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_toupper(int arg);
int					ft_tolower(int argument);
size_t				ft_strlen(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *src);
int					ft_isprint(int arg);
int					ft_isdigit(int arg);
int					ft_iscntrl(int argument);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
void				ft_putstr(char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
void				ft_putchar(char c);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr_fd(char *str, int fd);
char				*ft_strcat(char *dest, const char *src);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strrchr(const char *s, int c);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strnstr(const char *str, const char *to_find, \
					size_t len);
char				*ft_strstr(const char *str, const char *to_find);
void				ft_putnbr(int nb);
void				*ft_memmove(void *dst, const void *src, size_t len);
char				*ft_strnew(size_t size);
void				ft_putendl(char const *s);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
void				ft_putnbr_fd(int nb, int fd);
void				ft_striter(char *s, void (*f)(char *));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strmap(char const *s, char (*f)(char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				*ft_duplicate_content(void const *content, \
					size_t content_size);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				**ft_strsplit(char const *s, char c);
int					ft_get_word_number(char *s, char c);
int					ft_iswhitespace(char c);
char				*ft_itoa_base_low(unsigned int n, int base);
char				*ft_itoa_base_up(unsigned int n, int base);
char				*ft_itoa_base_long_low(unsigned long int n, int base);
char				*ft_itoa_base_long_up(unsigned long int n, int base);
char				*ft_itoa_base_up(unsigned int n, int base);
char				*ft_itoa_uint(unsigned int n);
char				*ft_itoa_base(int n, int base);
char				*ft_itoa_base_uint(unsigned int n, int base);
char				*ft_itoa_base_uint_long(unsigned long int n, int base);
int					nb_size_long_base(unsigned long int nb, int base);
char				*ft_strjoin_f(char *s1, char *s2);
int					get_next_line(const int fd, char **line);
int					ft_printf(const char *format, ...);
int					ft_fprintf(int fd, const char *format, ...);
int					ft_snprintf(char **buf, const char *format, ...);
void				free_n(int n, ...);
void				free_arr(void **arr);

#endif
