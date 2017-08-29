/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:34:45 by jgalvani          #+#    #+#             */
/*   Updated: 2016/11/24 15:48:41 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*u;
	size_t			i;

	i = 0;
	u = (unsigned char*)str;
	while (i < n)
	{
		u[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
