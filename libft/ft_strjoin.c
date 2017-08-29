/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:51:56 by jgalvani          #+#    #+#             */
/*   Updated: 2017/01/10 19:46:28 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin2(char *p1, char *p2, int i, int j)
{
	char	*p3;

	p3 = (char*)malloc(sizeof(char) * (ft_strlen(p1) + ft_strlen(p2) + 1));
	if (p3)
	{
		while (p1[i])
		{
			p3[i] = p1[i];
			i++;
		}
		while (p2[j])
		{
			p3[i + j] = p2[j];
			j++;
		}
		p3[i + j] = '\0';
		free(p1);
		return (p3);
	}
	return (0);
}

char		*ft_strjoin(const char *s1, const char *s2)
{
	char	*p1;
	char	*p2;
	char	*p3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	p1 = (char*)s1;
	p2 = (char*)s2;
	p3 = ft_strjoin2(p1, p2, i, j);
	return (p3);
}
