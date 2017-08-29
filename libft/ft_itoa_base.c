/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:29:02 by jgalvani          #+#    #+#             */
/*   Updated: 2017/03/22 13:16:21 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_base(intmax_t n, intmax_t base)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(intmax_t n, intmax_t base)
{
	char			*str;
	char			*ref;
	int				count;

	ref = "0123456789abcdefghijklmnopqrstuvwxyz\0";
	if (base < 2 || base > 37)
		return (0);
	count = count_base(n, base);
	str = ft_strnew(count);
	if (n == 0)
	{
		*str = '0';
		str[1] = 0;
	}
	while (n)
	{
		str[count - 1] = ref[n % base];
		count--;
		n /= base;
	}
	return (str);
}
