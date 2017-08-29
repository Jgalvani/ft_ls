/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:07:04 by jgalvani          #+#    #+#             */
/*   Updated: 2017/03/28 12:42:34 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	diez(t_data *data)
{
	int		i;
	int		j;
	va_list ap2;

	i = B;
	va_copy(ap2, data->ap);
	j = va_arg(ap2, int);
	while (data->buff[i] >= '0' && data->buff[i] <= '9' && data->buff[i])
		i++;
	if ((data->buff[i] == 'x' || data->buff[i] == 'X') && j &&
			data->buff[B] < '1' && data->buff[i] > '9')
		diez_x(data->buff[i], &*data);
	if (data->buff[B] >= '0' && data->buff[B] <= '9' && data->buff[0] != '-')
		num(&*data);
	if ((data->buff[i] == 'x' || data->buff[i] == 'X') && j &&
			data->buff[B] != '0')
		diez_x(data->buff[i], &*data);
	if ((data->buff[i] == 'o' || data->buff[i] == 'O') && (j || !data->pre))
	{
		write(1, "0", 1);
		data->ret += 1;
	}
}

void	octal(va_list ap, char c, t_data *data)
{
	char			*str;
	long			oct;
	int				pre;

	oct = va_arg(ap, uintmax_t);
	str = ft_uitoa_base(oct, 8);
	if (data->pre == 0 && oct == 0)
	{
		if (data->len > 0)
		{
			write(1, " ", 1);
			data->ret++;
		}
		return ;
	}
	data->ret += ft_strlen(str);
	pre = data->pre - ft_countonbr(oct);
	if (data->buff[1] == '#')
		pre--;
	putcharlen('0', pre);
	if (pre > 0)
		data->ret += pre;
	write(1, str, ft_strlen(str));
	free(str);
}

void	castsigned(intmax_t *i, t_data *data, char c)
{
	if (data->buff[4] == 'h' && data->buff[5] == 'h')
		*i = (char)*i;
	else if (data->buff[4] == 'h' && data->buff[5] != 'h')
		*i = (short)*i;
	else if ((data->buff[6] == 'l' && data->buff[7] != 'l') ||
				c == 'D')
		*i = (long)*i;
	else if (data->buff[6] == 'l' && data->buff[7] == 'l')
		*i = (long long)*i;
	else if (data->buff[8] == 'z')
		*i = (size_t)*i;
	else if (data->buff[9] != 'j')
		*i = (int)*i;
	ft_countmax(*i);
}

void	castunsigned(uintmax_t *i, t_data *data, char c)
{
	if (data->buff[4] == 'h' && data->buff[5] == 'h')
		*i = (unsigned char)*i;
	else if (data->buff[4] == 'h' && data->buff[5] != 'h')
		*i = (unsigned short)*i;
	else if ((data->buff[6] == 'l' && data->buff[7] != 'l') ||
			c == 'U')
		*i = (unsigned long)*i;
	else if (data->buff[6] == 'l' && data->buff[7] == 'l')
		*i = (unsigned long long)*i;
	else if (data->buff[8] == 'z')
		*i = (size_t)*i;
	else if (data->buff[9] != 'j')
		*i = (unsigned int)*i;
	ft_countumax(*i);
}
