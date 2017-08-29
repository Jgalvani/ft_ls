/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 13:27:44 by jgalvani          #+#    #+#             */
/*   Updated: 2017/08/29 20:34:50 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse(t_data *data)
{
	int i;

	ft_bzero(data->buff, 20);
	ftob(&*data);
	modulo(&*data);
	while ((!(i = 0) && (data->fmt[0] >= '0' && data->fmt[0] <= '9')) ||
		data->fmt[0] == '#' || data->fmt[0] == '-' || data->fmt[0] == 'h' ||
		data->fmt[0] == ' ' || data->fmt[0] == '+' || data->fmt[0] == 'l' ||
		data->fmt[0] == 'z' || data->fmt[0] == 'j' || data->fmt[0] == '.' ||
		data->fmt[0] == '*')
		data->fmt++;
	while (data->flag[i])
	{
		if (data->fmt[0] == data->flag[i])
		{
			data->fmt++;
			break ;
		}
		i++;
	}
}

void	flag(t_data *data, int i)
{
	if (data->fmt[i] == '-')
		data->buff[0] = '-';
	if (data->fmt[i] == '#')
		data->buff[1] = '#';
	if (data->fmt[i] == '+')
		data->buff[2] = '+';
	if (data->fmt[i] == ' ')
		data->buff[3] = ' ';
	if (data->fmt[i] == 'h')
		data->buff[4] = 'h';
	if (data->fmt[i - 1] == 'h' && data->fmt[i] == 'h')
		data->buff[5] = 'h';
	if (data->fmt[i] == 'l')
		data->buff[6] = 'l';
	if (data->fmt[i - 1] == 'l' && data->fmt[i] == 'l')
		data->buff[7] = 'l';
	if (data->fmt[i] == 'z')
		data->buff[8] = 'z';
	if (data->fmt[i] == 'j')
		data->buff[9] = 'j';
	if (data->fmt[i] == '*')
		data->buff[10] = '*';
	if (data->fmt[i] == '.' || data->fmt[i] == '*')
		precision(&*data, ++i);
}

void	numbers(int *j, t_data *data, int *i)
{
	int	k;
	int	l;

	k = *i;
	l = *j;
	if (l != B && data->fmt[k] >= '0' && data->fmt[k] <= '9' &&
		data->fmt[k - 1] != '.')
		erasenum(&*data, &l, k);
	while (data->fmt[k] >= '0' && data->fmt[k] <= '9' &&
			data->fmt[k - 1] != '.')
	{
		data->buff[l] = data->fmt[k];
		l++;
		k++;
		while (data->fmt[k] == '+')
		{
			data->buff[2] = '+';
			k++;
		}
	}
	if (data->fmt[k] == '.')
		precision(&*data, k + 1);
	*i = k;
	*j = l;
}

void	ftob(t_data *data)
{
	int i;
	int j;

	i = 1;
	j = B;
	ft_bzero(data->buff, 20);
	while ((data->fmt[i] >= '0' && data->fmt[i] <= '9') ||
			data->fmt[i] == '+' || data->fmt[i] == '-' ||
			data->fmt[i] == '#' || data->fmt[i] == ' ' ||
			data->fmt[i] == 'h' || data->fmt[i] == 'l' ||
			data->fmt[i] == 'j' || data->fmt[i] == 'z' ||
			data->fmt[i] == '.' || data->fmt[i] == '*')
	{
		numbers(&j, *&data, &i);
		flag(*&data, i);
		if (data->fmt[i - 1] < '0' || data->fmt[i - 1] > '9' ||
				data->fmt[i] == ' ' || data->fmt[i] == '-' ||
				data->fmt[i] == '#' || data->fmt[i] == '+' ||
				data->fmt[i] == '.')
			i++;
	}
	data->buff[j] = data->fmt[i];
	if (data->buff[j] == 'U')
		data->buff[6] = 'l';
	data->fmt++;
}

void	all(va_list ap)
{
	void	*all;
	int		len;

	all = va_arg(ap, void*);
	if (write(1, all, 1) == -1)
		ft_putlim((intmax_t)all);
	else
	{
		len = ft_strlen(all) - 1;
		write(1, (all + 1), len);
	}
}
