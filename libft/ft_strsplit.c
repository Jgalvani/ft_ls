/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:18:13 by jgalvani          #+#    #+#             */
/*   Updated: 2016/11/25 18:39:42 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char const *s, int i, char c)
{
	int begin;

	begin = i;
	while (s[i] && s[i] != c)
		i++;
	return (i - begin);
}

static char	*ft_putwords(char *tab, int i, char c, char const *s)
{
	int j;

	j = 0;
	while (s[i] != c && s[i] != '\0')
		tab[j++] = s[i++];
	tab[j] = '\0';
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		w;

	w = 0;
	if ((i = 0) || !c || !s)
		return (0);
	if (!(tab = (char**)malloc(sizeof(char*) * ft_countwords(s, c, i) + 1)))
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			if ((tab[w] = ft_strnew(ft_len(s, i, c))))
				ft_putwords(tab[w++], i, c, s);
			else
				return (0);
			i += ft_len(s, i, c);
		}
	}
	tab[w] = 0;
	return (tab);
}
