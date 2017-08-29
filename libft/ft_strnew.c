/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:38:44 by jgalvani          #+#    #+#             */
/*   Updated: 2016/11/24 16:05:39 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new_str;

	new_str = (char*)malloc(sizeof(char) * size + 1);
	if (new_str)
	{
		ft_memset(new_str, '\0', size + 1);
		return (new_str);
	}
	return (0);
}
