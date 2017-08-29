/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 18:49:03 by jgalvani          #+#    #+#             */
/*   Updated: 2017/03/23 13:23:47 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		minus_count(va_list ap2, int len, char c, t_data data)
{
	int		pre;
	int		nbr;

	len = count(ap2, len, c, data);
	if (c == 'o' || c == 'O')
	{
		nbr = va_arg(ap2, unsigned int);
		pre = data.pre - ft_countonbr(nbr);
		if (pre > 0 && data.pre >= 0)
			len -= ft_countonbr(nbr) + pre;
		else
			len -= ft_countonbr(nbr);
	}
	else if (c == 'x' || c == 'X' || c == 'p')
	{
		nbr = va_arg(ap2, uintmax_t);
		pre = data.pre - ft_countxnbr(nbr);
		if (pre > 0 && data.pre >= 0)
			len -= ft_countxnbr(nbr) + pre;
		else
			len -= ft_countxnbr(nbr);
		if (c == 'p')
			len -= 2;
	}
	return (len);
}

int		length(t_data data)
{
	va_list ap2;
	int		len;
	int		i;

	i = B;
	va_copy(ap2, data.ap);
	len = ft_atoi((char*)(&data.buff) + B);
	while (data.buff[i] >= '0' && data.buff[i] <= '9' && data.buff[i])
		i++;
	len = minus_count(ap2, len, data.buff[i], data);
	if (data.buff[i] == 'S')
		len = space_wchar(len, ap2);
	if (data.buff[i] == 'C' || data.buff[i] == 'c' || data.buff[i] == '%')
		len -= 1;
	if (data.buff[1] == '#' && (data.buff[i] == 'x' || data.buff[i] == 'X'))
		len -= 2;
	if (data.buff[1] == '#' && (data.buff[i] == 'o' || data.buff[i] == 'O'))
		len--;
	if (data.buff[3] == ' ')
		len--;
	va_copy(ap2, data.ap);
	if (data.buff[2] == '+' && va_arg(ap2, int) >= 0 && (data.buff[i] == 'd' ||
		data.buff[i] == 'D' || data.buff[i] == 'i'))
		len--;
	return (len);
}

void	bits(t_data data)
{
	unsigned char octet;

	octet = va_arg(data.ap, int);
	octet = (unsigned char)octet;
	print_bits(octet);
}

void	type(t_data *data)
{
	int	i;

	i = B;
	while ((data->buff[i] >= '0' && data->buff[i] <= '9') ||
			data->buff[i] == '.')
		i++;
	if (data->buff[i] == '%')
		percent(&*data, i);
	else if (data->buff[i] == 'b')
		bits(*data);
	else if (data->buff[i] == 'v')
		all(data->ap);
	else if (data->buff[i] == 'p' || data->buff[i] == 'x' ||
			data->buff[i] == 'X')
		hexa(data->ap, data->buff[i], &*data);
	else if (data->buff[i] == 'o' || data->buff[i] == 'O')
		octal(data->ap, data->buff[i], *&data);
	else if (data->buff[i] == 's' || data->buff[i] == 'S')
		string(data->ap, data->buff[i], &*data);
	else if (data->buff[i] == 'd' || data->buff[i] == 'c' ||
			data->buff[i] == 'i' || data->buff[i] == 'u' || data->buff[i] == 'C'
			|| data->buff[i] == 'D' || data->buff[i] == 'U')
		integer(data->ap, data->buff[i], *&data);
}

void	justify(t_data *data)
{
	int		i;
	t_data	copy;

	i = B;
	copy = (t_data){data->len, 0, data->pre, 0, 0, 0, 0};
	ft_memcpy(copy.buff, data->buff, 20);
	copy.fmt = data->fmt;
	va_copy(copy.ap, data->ap);
	if (data->buff[1] == '#')
		diez(*&data);
	while (data->buff[i] >= '0' && data->buff[i] <= '9')
		i++;
	data->buff[B] = data->buff[i];
	type(&*data);
	if (copy.buff[B] >= '0' & copy.buff[B] <= '9')
	{
		copy.len = length(copy);
		if (copy.len > 0)
			data->ret += copy.len;
		if (copy.buff[B] == '0' && copy.buff[0] != '-')
			putcharlen('0', copy.len);
		else if (copy.buff[B] >= '0' && copy.buff[B] <= '9')
			putcharlen(' ', copy.len);
	}
}
