/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:46:44 by jgalvani          #+#    #+#             */
/*   Updated: 2017/08/29 21:12:06 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

# define B	11

typedef enum	e_color
{
	BLACK,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	PURPLE,
	CYAN,
	WHITE,
	STOP,
}				t_color;

typedef struct	s_data
{
	int			len;
	int			ret;
	int			pre;
	char		buff[20];
	char		flag[18];
	const char	*fmt;
	va_list		ap;
	int			star;
}				t_data;

int				ft_printf(char const *fmt, ...);
int				length(t_data data);
int				precision(t_data *data, int i);
int				count(va_list ap2, int len, char c, t_data data);
int				space_wchar(int len, va_list ap2);
int				count2(va_list ap2, int len, char c, t_data data);
int				ubug(t_data *data, intmax_t i, uintmax_t j, va_list ap2);

void			color(int color);
void			percent(t_data *data, int i);
void			space_len(t_data *data, intmax_t i);
void			plus(t_data *data, int i);
void			modulo(t_data *data);
void			num_space(t_data *data);
void			space(t_data *data, int i, int v);
void			string2(t_data *data, size_t len, va_list ap);
void			hexa2(t_data *data, uintmax_t add, char c);
void			pre_len(t_data *data, int len, uintmax_t j);
void			int2(t_data *data, int len, intmax_t i, char c);
void			ft_uint(va_list ap, char c, t_data *data, int len);
void			pre_int(t_data *data, int *len, intmax_t *i);
void			big_oct(size_t len, t_data *data);
void			num(t_data *data);
void			diez_x(char c, t_data *data);
void			erasenum(t_data *data, int *l, int k);
void			parse(t_data *data);
void			castsigned(intmax_t *i, t_data *data, char c);
void			castunsigned(uintmax_t *i, t_data *data, char c);
void			type(t_data *data);
void			flag(t_data *data, int i);
void			diez(t_data *data);
void			justify(t_data *data);
void			hexa(va_list ap, char c, t_data *data);
void			all(va_list ap);
void			string(va_list ap, char c, t_data *data);
void			integer(va_list ap, char c, t_data *data);
void			octal(va_list ap, char c, t_data *data);
void			ftob(t_data *data);
void			string_protection(char *str, t_data *data);

#endif
