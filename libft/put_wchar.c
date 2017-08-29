/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 11:10:38 by jgalvani          #+#    #+#             */
/*   Updated: 2017/03/22 11:44:11 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		choose_mask(unsigned char dec, char *mask, unsigned int wchar)
{
	if (dec > 7 && dec <= 11)
		ft_strncpy(mask, "110xxxxx10xxxxxx\0", 17);
	else if (dec > 11 && dec <= 16)
		ft_strncpy(mask, "1110xxxx10xxxxxx10xxxxxx\0", 25);
	else if (dec > 16)
		ft_strncpy(mask, "11110xxx10xxxxxx10xxxxxx10xxxxxx\0", 33);
	else
	{
		ft_putchar(wchar);
		return (1);
	}
	return (0);
}

void	put_mask(char *mask, char *bin, int i, int j)
{
	i = ft_strlen(bin);
	i--;
	while (j && i >= 0)
	{
		if (mask[j] == 'x')
		{
			mask[j] = bin[i];
			i--;
			j--;
		}
		else
			j--;
	}
	while (mask[j])
	{
		if (mask[j] == 'x')
			mask[j] = '0';
		j++;
	}
}

int		put_wchar(unsigned int wchar)
{
	char			mask[33];
	int				i;
	unsigned char	dec;
	char			*str;

	i = 0;
	str = ft_uitoa_base(wchar, 2);
	dec = ft_strlen(str);
	if (choose_mask(dec, mask, wchar) == 1)
		return (1);
	put_mask(mask, str, i, ft_strlen(mask));
	free(str);
	str = ft_strnew(8);
	while (i < (int)ft_strlen(mask))
	{
		str = ft_strncpy(str, mask + i, 8);
		dec = bin_to_dec(str);
		write(1, &dec, 1);
		i += 8;
	}
	free(str);
	return (i / 8);
}
