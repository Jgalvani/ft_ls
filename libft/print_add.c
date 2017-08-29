/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:26:07 by jgalvani          #+#    #+#             */
/*   Updated: 2017/03/27 17:56:34 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	get_add(char *add, unsigned int n, char *base)
{
	int				i;

	i = ft_countxnbr(n);
	ft_bzero(add, 9);
	while (n)
	{
		add[i - 1] = base[n % 16];
		i--;
		n /= 16;
	}
}

int		get_add2(char *add2, unsigned int lim, char *base)
{
	int				i;
	int				j;

	i = countnbr_base(lim, 16);
	j = i;
	ft_bzero(add2, 9);
	while (lim > 0)
	{
		add2[i - 1] = base[lim % 16];
		i--;
		lim /= 16;
	}
	return (j);
}

int		print_add(unsigned long n)
{
	char			*base;
	char			add[10];
	char			add2[10];
	unsigned int	lim;
	int				i;

	lim = 0;
	if (n > 4294967295)
		lim = n / 4294967296;
	if (!n)
	{
		write(1, "0", 1);
		return (1);
	}
	base = "0123456789abcdef";
	get_add(add, n, *&base);
	i = get_add2(add2, lim, *&base);
	i += ft_strlen(add);
	write(1, add2, ft_strlen(add2));
	write(1, add, ft_strlen(add));
	return (i);
}
