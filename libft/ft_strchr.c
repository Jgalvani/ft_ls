/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:54:10 by jgalvani          #+#    #+#             */
/*   Updated: 2016/11/24 15:56:12 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *s, int c)
{
	int		i;
	char	*p;

	i = 0;
	p = (char*)s;
	if (c == '\0')
	{
		while (p[i])
			i++;
		return (&p[i]);
	}
	while (p[i])
	{
		if (p[i] == c)
			return (&p[i]);
		i++;
	}
	return (0);
}
