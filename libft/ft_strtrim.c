/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:56:06 by jgalvani          #+#    #+#             */
/*   Updated: 2016/11/25 13:22:07 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		first_char(char *p1, int i)
{
	while (p1[i] == ',' || p1[i] == ' ' || p1[i] == '\n' || p1[i] == '\t')
	{
		i++;
		if (p1[i] == '\0')
			return (0);
	}
	return (i);
}

static	int		last_char(char *p1, int i)
{
	while (p1[i + 1] != '\0')
		i++;
	while (p1[i] == ',' || p1[i] == ' ' || p1[i] == '\n' || p1[i] == '\t')
		i--;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	char	*p1;
	char	*p2;
	int		i;
	int		begin;
	int		end;

	i = 0;
	if (!s)
		return (0);
	p1 = (char*)s;
	begin = first_char(p1, i);
	end = last_char(p1, i);
	p2 = (char*)malloc(sizeof(char) * (end - begin) + 2);
	if (p2)
	{
		while (begin <= end)
		{
			p2[i] = p1[begin];
			i++;
			begin++;
		}
		p2[i] = '\0';
		return (p2);
	}
	return (0);
}
