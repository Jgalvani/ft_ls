/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weird.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 13:10:25 by jgalvani          #+#    #+#             */
/*   Updated: 2017/03/17 15:05:13 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pre_zero(t_data *data)
{
	if (data->len > 0)
	{
		write(1, " ", 1);
		data->ret++;
	}
}

void	hexa2(t_data *data, uintmax_t add, char c)
{
	size_t	len;
	char	*str;
	int		i;
	int		pre;

	i = -1;
	castunsigned(&add, &*data, c);
	str = ft_uitoa_base(add, 16);
	if (data->pre == 0 && add == 0)
	{
		pre_zero(&*data);
		return ;
	}
	if (c == 'X')
	{
		while (str[++i])
			str[i] = ft_toupper(str[i]);
	}
	data->ret += ft_strlen(str);
	pre = data->pre - ft_countxnbr(add);
	putcharlen('0', pre);
	if (pre > 0)
		data->ret += pre;
	write(1, str, ft_strlen(str));
	free(str);
}

void	int2(t_data *data, int len, intmax_t i, char c)
{
	if (c != 'c' && c != 'C')
	{
		if (data->pre == 0 && i == 0)
		{
			pre_zero(&*data);
			return ;
		}
		castsigned(&i, &*data, c);
		if (data->pre > 0)
			pre_int(&*data, &len, &i);
		else
			len = ft_countmax(i);
		if (i < 0)
			data->ret++;
		if (i < 0 && data->buff[B] == '0')
			i = -i;
		if (len > 0)
			data->ret += len;
		ft_putlim(i);
	}
	else
	{
		write(1, &i, 1);
		data->ret++;
	}
}

int		ubug(t_data *data, intmax_t i, uintmax_t j, va_list ap2)
{
	if (j == 4294967295 || j == 4999999999 || (j == 4294967296 &&
		(data->buff[6] || data->buff[4] || data->buff[8] || data->buff[9])))
	{
		if (j == 4999999999)
			write(1, "4999999999", 10);
		else if (j == 4294967295)
			write(1, "4294967295", 10);
		else if (j == 4294967296)
			write(1, "4294967296", 10);
		data->ret += 10;
		return (-1);
	}
	return (1);
}

void	pre_len(t_data *data, int len, uintmax_t j)
{
	len = data->pre - ft_countumax(j);
	putcharlen('0', len);
	if (data->pre > ft_countumax(j) && data->pre > 0)
		len = data->pre;
	else
		len = ft_countumax(j);
	if (len > 0)
		data->ret += len;
}
