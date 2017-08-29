/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:44:47 by jgalvani          #+#    #+#             */
/*   Updated: 2016/11/25 15:12:09 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	j = i;
	while (src[i - j] && i < (size - 1))
	{
		dst[i] = src[i - j];
		i++;
	}
	if (j <= size)
		dst[i] = '\0';
	if (size < i)
		return (ft_strlen(src) + size);
	return (ft_strlen(src) + j);
}
