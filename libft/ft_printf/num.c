/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 18:55:09 by jgalvani          #+#    #+#             */
/*   Updated: 2017/03/15 16:02:54 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	num(t_data *data)
{
	if (data->len != -1)
		data->len = length(*data);
	if (data->len > 0)
		data->ret += data->len;
	if (data->buff[B] == '0')
		putcharlen('0', data->len);
	else if (data->buff[B] >= '1' && data->buff[B] <= '9')
		putcharlen(' ', data->len);
}

void	erasenum(t_data *data, int *l, int k)
{
	int	p;

	p = *l;
	if (p != B && data->fmt[k] >= '0' && data->fmt[k] <= '9')
	{
		p = B;
		while (data->buff[p] >= '0' && data->buff[p] <= '9')
		{
			data->buff[p] = '\0';
			p++;
		}
	}
	*l = B;
}

int		precision(t_data *data, int i)
{
	char	str[20];
	int		j;

	j = 0;
	ft_bzero(str, 20);
	if (data->fmt[i] < '0' && data->fmt[i] > '9')
		data->pre = 0;
	while (data->fmt[i] >= '0' && data->fmt[i] <= '9')
	{
		str[j] = data->fmt[i];
		i++;
		j++;
	}
	if (j)
		data->pre = ft_atoi(str);
	if (data->pre < 0)
		data->pre = 0;
	if (j > 0)
		data->fmt += j + 1;
	if (data->buff[10] == '*' && !data->star)
	{
		data->pre = va_arg(data->ap, int);
		data->star++;
	}
	return (i);
}

void	diez_x(char c, t_data *data)
{
	if (c == 'x')
		write(1, "0x", 2);
	if (c == 'X')
		write(1, "0X", 2);
	data->ret += 2;
}

void	plus(t_data *data, int i)
{
	if (data->buff[i] != 'c' && data->buff[i] != 'C' &&
		data->buff[i] != 'o' && data->buff[i] != 'O' &&
		data->buff[i] != 's' && data->buff[i] != 'S' &&
		data->buff[i] != 'u' && data->buff[i] != 'U' &&
		data->buff[i] != 'p' && data->buff[i] != 'x' &&
		data->buff[i] != 'X' && ((data->buff[B] < '1' ||
		data->buff[B] > '9') || data->buff[0] == '-'))
	{
		write(1, "+", 1);
		data->ret++;
	}
}
