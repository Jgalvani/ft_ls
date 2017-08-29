/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:16:52 by jgalvani          #+#    #+#             */
/*   Updated: 2016/11/24 15:18:58 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				*ft_zero(char *str)
{
	if (!(str = ft_strnew(2)))
		return (0);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static unsigned int		ft_num(unsigned int num, int n)
{
	if (n < 0 && n != -2147483648)
		num = -n;
	else if (n > 0)
		num = n;
	else if (n == -2147483648)
		num = 2147483648;
	return (num);
}

static int				ft_countnbr(int n)
{
	int i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		if (n == -2147483648)
			n += 1;
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char					*ft_itoa(int n)
{
	char			*str;
	unsigned int	num;
	int				i;

	num = 0;
	str = 0;
	i = ft_countnbr(n);
	if (n == 0)
	{
		str = ft_zero(str);
		return (str);
	}
	if (!(str = ft_strnew(i)))
		return (0);
	num = ft_num(num, n);
	while (num)
	{
		str[--i] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
