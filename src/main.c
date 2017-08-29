/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 17:18:43 by jgalvani          #+#    #+#             */
/*   Updated: 2017/08/29 22:54:54 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_u8		assign_color(unsigned char type)
{
	t_u8	color;

	if (type == DT_DIR)
		color = CYAN;
	else if (type == DT_FIFO)
		color = RED;
	else if (type == DT_BLK || type == DT_CHR)
		color = BLUE;
	else if (type == DT_LNK)
		color = PURPLE;
	else if (type == DT_SOCK)
		color = YELLOW;
	else
		color = WHITE;
	return (color);
}

char		*get_new_loc(char *location, char *d_name)
{
	char	*new_loc;
	size_t	len;

	len = ft_strlen(location);
	new_loc = ft_strnew(len + ft_strlen(d_name) + 1);
	new_loc = ft_strcat(new_loc, location);
	if (location[len - 1] != '/')
		new_loc[len] = '/';
	new_loc = ft_strcat(new_loc, d_name);
	return (new_loc);
}

t_u16		set_flag(char *str)
{
	t_u8	i;
	t_u16	flag;
	char	*flag_tab;

	i = 0;
	flag = 0;
	flag_tab = "lRartucfF\0";
	flag_error(str);
	while (flag_tab[i])
	{
		flag >>= 1;
		if (ft_strchr(str, flag_tab[i]))
			flag |= 1 << 8;
		i++;
	}
	return (flag);
}

int			main(int ac, char **av)
{
	t_u16	flag;
	int		i;

	i = 1;
	flag = 0;
	if (ac == 1)
		print_dir("./", flag);
	else if (ac > 1)
	{
		while (i < ac && av[i][0] == '-')
		{
			flag |= set_flag(av[i]);
			i++;
		}
		if (i == ac)
			print_dir("./", flag);
		else
			get_dir_loc(ac, av, flag, i);
	}
}
