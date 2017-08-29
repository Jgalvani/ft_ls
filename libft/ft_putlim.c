/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlng.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 14:39:15 by jgalvani          #+#    #+#             */
/*   Updated: 2017/03/10 16:21:51 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putlim(intmax_t n)
{
	intmax_t	nb;

	nb = n;
	if (n == 0)
		ft_putchar('0');
	if (n < 0)
	{
		ft_putchar('-');
		if (nb == LONG_MIN)
		{
			ft_putlim(922337203685477580);
			write(1, "8", 1);
		}
		nb = -nb;
	}
	if (nb < 10 && nb > 0)
		ft_putchar(nb + '0');
	if (nb >= 10)
	{
		ft_putlim(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}
