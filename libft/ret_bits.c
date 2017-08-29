/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_bits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:52:47 by jgalvani          #+#    #+#             */
/*   Updated: 2017/03/16 16:06:43 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ret_bits(unsigned int bin)
{
	unsigned int	size;
	unsigned int	max;
	unsigned char	b;
	unsigned int	i;
	char			*str;

	str = ft_strnew(32);
	i = 0;
	size = sizeof(unsigned int);
	max = 1 << (size * 8 - 1);
	while (i < size * 8)
	{
		b = !!(bin & max) + '0';
		str[i] = b;
		i++;
		bin = bin << 1;
	}
	return (str);
}
