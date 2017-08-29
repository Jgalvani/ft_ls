/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:47:12 by jgalvani          #+#    #+#             */
/*   Updated: 2017/04/21 14:05:12 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *src, int n)
{
	char	*dest;

	dest = malloc(sizeof(char) * n + 1);
	if (dest)
	{
		dest[n] = '\0';
		while (n > 0)
		{
			dest[n - 1] = src[n - 1];
			n--;
		}
		return (dest);
	}
	return (0);
}
