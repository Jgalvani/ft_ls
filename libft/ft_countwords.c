/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 21:02:46 by jgalvani          #+#    #+#             */
/*   Updated: 2016/11/25 17:56:42 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_countwords(char const *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[i] == c)
		i++;
	if (s[i] != c && s[i] != '\0')
		j++;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == c)
		return (j += ft_countwords(s, c, i));
	return (j);
}
