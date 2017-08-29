/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:01:29 by jgalvani          #+#    #+#             */
/*   Updated: 2017/04/19 12:12:18 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	if (n == 0)
		return (dst);
	s1 = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	while (0 < n)
	{
		*s1++ = *s2++;
		n--;
	}
	return (dst);
}
