/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:46:57 by jgalvani          #+#    #+#             */
/*   Updated: 2017/05/04 15:22:48 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hexa(va_list ap, char c, t_data *data)
{
	uintmax_t		add;

	add = va_arg(ap, uintmax_t);
	if (c == 'p')
	{
		write(1, "0x", 2);
		data->ret += 2;
		if (!data->pre && !add)
			return ;
		if (data->pre > 0 && data->pre > ft_countxnbr(add))
		{
			putcharlen('0', data->pre - ft_countxnbr(add));
			data->ret += data->pre - ft_countxnbr(add);
		}
		data->ret += print_add(add);
	}
	else if (c == 'x' || c == 'X')
		hexa2(&*data, add, c);
}

void	integer(va_list ap, char c, t_data *data)
{
	wchar_t				w;
	intmax_t			i;
	int					len;

	if ((c == 'c' && data->buff[6] == 'l') || c == 'C')
	{
		w = va_arg(ap, wchar_t);
		data->ret += put_wchar(w);
	}
	else if (c != 'u' && c != 'U')
	{
		i = va_arg(data->ap, intmax_t);
		int2(&*data, len, i, c);
	}
	else
		ft_uint(ap, c, &*data, len);
}

void	string(va_list ap, char c, t_data *data)
{
	wchar_t	*ptr;
	size_t	len;

	if (!(len = 0) && c == 's' && data->buff[6] != 'l')
		string2(&*data, len, ap);
	else
	{
		ptr = va_arg(ap, wchar_t*);
		if (!ptr)
		{
			write(1, "(null)", 6);
			data->ret += 6;
			return ;
		}
		while (*ptr)
		{
			data->ret += put_wchar(*ptr);
			ptr++;
		}
	}
}

void	modulo(t_data *data)
{
	int		i;
	int		v;
	va_list	ap2;

	i = B;
	va_copy(ap2, data->ap);
	v = va_arg(ap2, int);
	while ((data->buff[i] >= '0' && data->buff[i] <= '9') ||
			data->buff[i] == '.')
		i++;
	if (data->buff[2] == '+' && v >= 0)
		plus(&*data, i);
	if (data->buff[3] == ' ')
		space(&*data, i, v);
	if (data->buff[0] == '-')
		justify(*&data);
	else if (data->buff[1] == '#')
		diez(*&data);
	if (data->buff[B] >= '0' && data->buff[B] <= '9')
		num_space(&*data);
	if (data->buff[0] != '-')
		type(&*data);
}

int		ft_printf(const char *format, ...)
{
	int		len;
	t_data	data;

	data = (t_data){0, 0, -1, "0", "%pxXoOsSdDcCiuUbv0", format, 0, 0};
	va_start(data.ap, format);
	while (!(len = 0) && data.fmt[len])
	{
		while (data.fmt[len] && data.fmt[len] != '%')
			len++;
		if (len)
			write(1, data.fmt, len);
		data.ret += len;
		data.fmt += len;
		if (data.fmt[0] == '%')
			parse(&data);
		if (data.ret == -1)
			return (-1);
		data.pre = -1;
		data.star = 0;
	}
	va_end(data.ap);
	return (data.ret);
}
