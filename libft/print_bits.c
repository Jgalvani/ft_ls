/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:33:47 by jgalvani          #+#    #+#             */
/*   Updated: 2017/03/28 12:29:21 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	unsigned char	size;
	unsigned char	max;
	unsigned char	b;
	unsigned char	i;

	i = 0;
	size = sizeof(unsigned char);
	max = 1 << (size * 8 - 1);
	while (i < size * 8)
	{
		i++;
		b = !!(octet & max) + '0';
		write(1, &b, 1);
		octet = octet << 1;
	}
}
