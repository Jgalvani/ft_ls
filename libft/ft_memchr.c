/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 21:04:13 by jgalvani          #+#    #+#             */
/*   Updated: 2016/11/24 15:50:42 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	unsigned char	*u;
	size_t			i;

	i = 0;
	u = (unsigned char*)s;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (u[i] == (unsigned char)c)
			return (&u[i]);
		i++;
	}
	return (0);
}
