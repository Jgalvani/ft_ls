/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   something.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 16:23:33 by jgalvani          #+#    #+#             */
/*   Updated: 2017/08/29 21:14:52 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string2(t_data *data, size_t len, va_list ap)
{
	char	*str;
	int		col;
	va_list	ap2;

	va_copy(ap2, ap);
	col = va_arg(ap2, int);
	str = va_arg(ap, char *);
	if (col >= 0 && col <= 8)
	{
		color(col);
		return ;
	}
	if (!str || !*str)
	{
		string_protection(str, data);
		return ;
	}
	len = ft_strlen(str);
	if (data->buff[10] == '*')
		putcharlen(' ', data->pre - len);
	if (data->pre != -1 && data->pre < len)
		len = data->pre;
	data->ret += len;
	write(1, str, len);
}

void	space(t_data *data, int i, int v)
{
	char	*type;
	int		j;

	j = 0;
	type = "%bvpxXoOsSdciuCDU\0";
	while (data->buff[i] != type[j] && type[j])
		j++;
	if (!type[j])
		return ;
	if (data->buff[3] == ' ' && data->buff[i] != '%' && data->buff[i] != 'c'
		&& v >= 0 && data->buff[2] != '+' && data->buff[i] != 'u' &&
		data->buff[i] != 's' && data->buff[i] != 'C' && data->buff[i] != 'S'
		&& data->buff[i] != 'p' && data->buff[i] != 'o' &&
		data->buff[i] != 'O' && data->buff[i] != 'x' && data->buff[i] != 'X')
	{
		write(1, " ", 1);
		data->ret++;
	}
}

void	num_space(t_data *data)
{
	intmax_t	i;
	uintmax_t	k;
	int			j;
	va_list		ap2;

	va_copy(ap2, data->ap);
	j = B;
	while (data->buff[j] >= '0' && data->buff[j] <= '9')
		j++;
	if (data->buff[j] == 'd' || data->buff[j] == 'D' || data->buff[j] == 'i')
	{
		i = va_arg(ap2, intmax_t);
		castsigned(&i, data, data->buff[j]);
	}
	else
	{
		k = va_arg(ap2, uintmax_t);
		castunsigned(&k, data, data->buff[j]);
	}
	if (data->buff[0] != '-' && data->buff[1] != '#')
		space_len(&*data, i);
}

int		count(va_list ap2, int len, char c, t_data data)
{
	char	*str;
	int		pre;
	int		nbr;

	len = count2(ap2, len, c, data);
	if (c == 'd' || c == 'D' || c == 'i')
	{
		nbr = va_arg(ap2, int);
		pre = data.pre - ft_countnumbers(nbr);
		if (nbr < 0 && pre > 0)
			pre++;
		if (pre > 0 && data.pre >= 0)
			len -= ft_countnumbers(nbr) + pre;
		else if (nbr < 0)
			len -= ft_countnumbers(nbr) + 1;
		else
			len -= ft_countnumbers(nbr);
	}
	return (len);
}

void	percent(t_data *data, int i)
{
	i = 0;
	while (i < B)
	{
		if (data->buff[i] != ' ' && data->buff[i] < '0' &&
				data->buff[i] > '9' && data->buff[i] != '-')
			return ;
		i++;
	}
	write(1, "%", 1);
	data->ret++;
}
