/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 13:34:50 by jgalvani          #+#    #+#             */
/*   Updated: 2017/03/27 16:27:54 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa_base(uintmax_t n, uintmax_t base)
{
	char			*str;
	char			*ref;
	int				count;

	ref = "0123456789abcdefghijklmnopqrstuvwxyz\0";
	if (base < 2 || base > 37)
		return (0);
	count = countnbr_base(n, base);
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
