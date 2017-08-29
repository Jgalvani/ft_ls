/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:58:03 by jgalvani          #+#    #+#             */
/*   Updated: 2016/11/24 15:50:18 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*s1;
	unsigned char		*s2;

	s1 = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	if (n == 0)
		return (dst);
	if (dst > src)
	{
		while (n--)
			s1[n] = s2[n];
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
