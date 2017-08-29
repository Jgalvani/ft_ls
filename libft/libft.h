/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:02:55 by jgalvani          #+#    #+#             */
/*   Updated: 2017/07/31 15:35:22 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <strings.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <time.h>
# include "libtype.h"
# include "get_next_line.h"
# include "./ft_printf/ft_printf.h"

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_isnoint(long long int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_countnumbers(int n);
int					ft_countlonglong(long long int n);
unsigned int		ft_countunbr(unsigned int n);
unsigned int		ft_countonbr(unsigned int n);
unsigned int		ft_countxnbr(uintmax_t n);
int					countnbr_base(uintmax_t n, uintmax_t base);
size_t				ft_countmax(long long int n);
uintmax_t			ft_countumax(uintmax_t n);
size_t				ft_strlen(char const *str);
int					*ft_range(int min, int max);
int					ft_atoi(char const *str);
int					ft_countwords(char const *s, char c, int i);
int					ft_iswhitespace(char const *str, int i);
int					ft_strcmp(char const *s1, char const *s2);
int					ft_strequ(char const *s1, char const *s2);
int					ft_memcmp(void const *s1, void const *s2, size_t n);
int					ft_strnequ(char const *s1, char const *s2i, size_t n);
int					ft_strncmp(char const *s1, char const *s2, size_t n);
int					get_next_line(const int fd, char **line);

char				*ft_itoa(int n);
char				*ft_strrev(char *str);
unsigned char		bin_to_dec(char *bin);
char				*ft_itoa_base(intmax_t n, intmax_t base);
char				*ft_uitoa_base(uintmax_t n, uintmax_t base);
void				ft_strdel(char **as);
char				*ft_strdup(char *src);
char				*ft_strndup(char *src, int i);
char				*ft_strnew(size_t size);
char				*ft_strlower(char *str);
char				*ft_strtrim(char const *s);
char				*ft_strcpy(char *dst, char const *src);
char				*ft_strchr(char const *s, int c);
char				*ft_strrchr(char const *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strcat(char *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strncpy(char *dst, char *src, size_t n);
char				*ft_strstr(char const *big, char const *little);
char				*ft_strncat(char *s1, char const *s2, size_t n);
size_t				ft_strlcat(char *dst, char const *src, size_t size);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strnstr(char const *big, char const *little, size_t n);

void				ft_putnbr(int n);
void				error(char *str);
int					put_wchar(unsigned int bin);
void				ft_putlim(intmax_t n);
void				print(void *p);
int					print_add(unsigned long n);
void				print_bits(unsigned char n);
char				*ret_bits(unsigned int bin);
void				ft_putunbr(unsigned int n);
void				ft_putulim(uintmax_t n);
void				ft_putchar(char c);
void				putcharlen(char c, int len);
void				ft_strclr(char *as);
void				ft_memdel(void **ap);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				*ft_memalloc(size_t size);
void				ft_bzero(void *s, size_t n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_striter(char *s, void (*f)(char*));
void				ft_lstadd(t_list **alst, t_list *new);
void				*ft_memset(void *str, int c, size_t n);
void				*ft_memchr(void const *s, int c, size_t n);
void				*ft_memcpy(void *dst, void const *src, size_t n);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *d, void const *s, int c, size_t n);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_striteri(char *s, void(*f)(unsigned int, char*));
void				free_list(t_list *list);

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);

#endif
