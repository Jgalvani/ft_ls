/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_to_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:07:24 by jgalvani          #+#    #+#             */
/*   Updated: 2017/03/21 21:00:33 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	ft_power(int j)
{
	int				i;
	int				res;

	if (j == 0)
		return (1);
	i = 1;
	res = 2;
	while (i < j)
	{
		res *= 2;
		i++;
	}
	return (res);
}

unsigned char	bin_to_dec(char *bin)
{
	int				dec;
	int				i;
	unsigned char	j;

	dec = 0;
	i = 0;
	j = 0;
	while (bin[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (bin[i] == '1')
			dec += ft_power(j);
		i--;
		j++;
	}
	return (dec);
}
