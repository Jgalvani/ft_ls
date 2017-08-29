/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:04:34 by jgalvani          #+#    #+#             */
/*   Updated: 2017/04/13 13:51:40 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pre_int(t_data *data, int *len, intmax_t *i)
{
	intmax_t	j;
	int			l;

	l = *len;
	j = *i;
	l = data->pre - ft_countmax(j);
	if (data->pre > ft_countmax(j))
	{
		if (j < 0 && data->buff[B] != '0')
		{
			write(1, "-", 1);
			j = -j;
			data->pre++;
		}
		if (data->buff[10] != '*')
			putcharlen('0', l);
		else
			putcharlen(' ', l);
		l = data->pre;
	}
	else
		l = ft_countmax(j);
	*i = j;
	*len = l;
}

void	space_len(t_data *data, intmax_t i)
{
	if (i < 0 && data->buff[B] == '0')
		write(1, "-", 1);
	data->len = length(*data);
	if (data->len > 0)
		data->ret += data->len;
	if (data->buff[B] == '0')
	{
		if (data->pre > 0 && i >= 0)
			putcharlen(' ', data->len);
		else
		{
			putcharlen('0', data->len);
			data->pre -= data->len;
		}
	}
	else if (data->buff[B] >= '1' && data->buff[B] <= '9')
	{
		putcharlen(' ', data->len);
		if (data->buff[2] == '+')
		{
			write(1, "+", 1);
			data->ret++;
		}
	}
}

int		count2(va_list ap2, int len, char c, t_data data)
{
	char	*str;
	int		pre;
	int		nbr;

	if (c == 's')
	{
		str = va_arg(ap2, char *);
		pre = ft_strlen(str) - data.pre;
		if (pre > 0 && data.pre >= 0 && *str)
			len -= data.pre;
		else if (*str)
			len -= ft_strlen(str);
	}
	else if (c == 'u' || c == 'U')
	{
		nbr = va_arg(ap2, unsigned int);
		pre = data.pre - ft_countnumbers(nbr);
		if (pre > 0 && data.pre >= 0)
			len -= ft_countnumbers(nbr) + pre;
		else
			len -= ft_countunbr(nbr);
	}
	return (len);
}

void	ft_uint(va_list ap, char c, t_data *data, int len)
{
	uintmax_t	j;
	intmax_t	i;
	va_list		ap2;

	i = 0;
	va_copy(ap2, ap);
	j = va_arg(ap, uintmax_t);
	if (data->pre == 0 && j == 0)
		return ;
	if (ubug(&*data, i, j, ap2) < 1)
		return ;
	castunsigned(&j, &*data, c);
	pre_len(&*data, len, j);
	ft_putulim(j);
}

int		space_wchar(int len, va_list ap2)
{
	wchar_t	*ptr;

	ptr = va_arg(ap2, wchar_t*);
	while (*ptr)
	{
		len -= (ft_strlen((char*)ptr) * 2);
		ptr++;
	}
	len += 2;
	return (len);
}
