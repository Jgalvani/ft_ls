/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 13:49:38 by jgalvani          #+#    #+#             */
/*   Updated: 2017/02/10 15:42:21 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str);
	dst = ft_strnew(j);
	j--;
	while (j >= 0)
	{
		dst[i] = str[j];
		i++;
		j--;
	}
	j = 0;
	while (dst[j])
	{
		str[j] = dst[j];
		j++;
	}
	free(dst);
	return (str);
}
