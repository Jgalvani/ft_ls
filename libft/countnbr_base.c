/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countnbr_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:31:36 by jgalvani          #+#    #+#             */
/*   Updated: 2017/03/27 16:28:02 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countnbr_base(uintmax_t n, uintmax_t base)
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
