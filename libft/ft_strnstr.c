/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:57:48 by jgalvani          #+#    #+#             */
/*   Updated: 2016/11/25 20:29:34 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strnstr2(char *b, char const *little, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (b[i])
	{
		while (b[i + j] == little[j])
		{
			j++;
			if ((i + j) > n)
				return (0);
			if (little[j] == '\0')
				return (b + i);
		}
		j = 0;
		i++;
	}
	return (0);
}

char		*ft_strnstr(char const *big, char const *little, size_t n)
{
	char	*b;

	b = (char*)big;
	if (n == 0)
		return (0);
	if (*little == '\0')
		return (b);
	return (ft_strnstr2(b, little, n));
}
