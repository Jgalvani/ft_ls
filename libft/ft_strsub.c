/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:43:05 by jgalvani          #+#    #+#             */
/*   Updated: 2016/11/25 13:26:02 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	char			*p;
	unsigned int	i;

	str = (char*)s;
	i = 0;
	if (!s)
		return (0);
	p = (char*)malloc(sizeof(char) * len + 1);
	if (p)
	{
		while (len > 0 && str[start])
		{
			p[i++] = str[start++];
			len--;
		}
		p[i] = '\0';
		return (p);
	}
	return (0);
}
