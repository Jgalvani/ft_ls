/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 18:42:42 by jgalvani          #+#    #+#             */
/*   Updated: 2017/08/29 18:54:56 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	dir_error(char *location)
{
	write(2, "ft_ls: ", 7);
	perror(location);
}

void	flag_error(char *str)
{
	t_u8	i;
	char	*flag_tab;

	i = 1;
	flag_tab = "1lRartucfF\0";
	while (str[i])
	{
		if (!ft_strchr(flag_tab, str[i]))
		{
			ft_printf("ft_ls: illegal option -- %c\n", str[i]);
			ft_printf("usage: ft_ls [-lRartucfF] [file ...]\n");
			exit(-1);
		}
		i++;
	}
	if (i == 1)
		write(2, "ft_ls: -: No such file or directory\n", 36);
}
