/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 18:41:52 by jgalvani          #+#    #+#             */
/*   Updated: 2017/08/13 18:42:31 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	sort_rec_ascii(t_rec *d_list)
{
	t_rec	*next;

	while (d_list)
	{
		next = d_list->next;
		while (next)
		{
			if ((ft_strcmp(next->new_loc, d_list->new_loc)) < 0)
				swap_rec(next, d_list);
			else
				next = next->next;
		}
		d_list = d_list->next;
	}
}

void	sort_rec_rev_ascii(t_rec *d_list)
{
	t_rec	*next;

	while (d_list)
	{
		next = d_list->next;
		while (next)
		{
			if ((ft_strcmp(next->new_loc, d_list->new_loc)) > 0)
				swap_rec(next, d_list);
			else
				next = next->next;
		}
		d_list = d_list->next;
	}
}

void	sort_info_ascii(t_info *dir_info)
{
	t_info	*next;

	while (dir_info)
	{
		next = dir_info->next;
		while (next)
		{
			if ((ft_strcmp(next->name, dir_info->name)) < 0)
				swap_info(next, dir_info);
			else
				next = next->next;
		}
		dir_info = dir_info->next;
	}
}

void	sort_info_rev_ascii(t_info *dir_info)
{
	t_info	*next;

	while (dir_info)
	{
		next = dir_info->next;
		while (next)
		{
			if ((ft_strcmp(next->name, dir_info->name)) > 0)
				swap_info(next, dir_info);
			else
				next = next->next;
		}
		dir_info = dir_info->next;
	}
}
