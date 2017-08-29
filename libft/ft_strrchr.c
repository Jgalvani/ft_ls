/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:44:24 by jgalvani          #+#    #+#             */
/*   Updated: 2016/11/25 15:05:00 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_zero(char *ptr, int i)
{
	while (ptr[i])
		i++;
	return (&ptr[i]);
}

char		*ft_strrchr(char const *s, int c)
{
	int		i;
	int		j;
	int		t;
	char	*ptr;

	i = 0;
	j = 0;
	t = 0;
	ptr = (char*)s;
	if (c == '\0')
		return (ft_zero(ptr, i));
	while (ptr[i])
	{
		if (ptr[i] == c)
		{
			j = i;
			t++;
		}
		i++;
		if (ptr[i] == '\0' && t != 0)
			return (&ptr[j]);
	}
	return (0);
}
