/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 18:33:55 by jgalvani          #+#    #+#             */
/*   Updated: 2017/08/29 20:35:45 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	print_link_list(t_max *max, t_info *dir_info)
{
	t_info	*begin_info;

	begin_info = dir_info;
	while (dir_info)
	{
		ft_printf("%c%s%c %*.lld %*.s %*.s %*.lld %.24s %s%s%s %s\n",
				dir_info->type, dir_info->perm, dir_info->attr, max->link,
				dir_info->link, max->owner, dir_info->owner, max->group,
				dir_info->group, max->size, dir_info->size, dir_info->date,
				dir_info->color, dir_info->name, STOP, dir_info->lpath);
		dir_info = dir_info->next;
	}
	dir_info = begin_info;
}

void	print_reg_list(t_max *max, t_info *dir_info)
{
	t_info	*begin_info;

	begin_info = dir_info;
	while (dir_info)
	{
		ft_printf("%c%s%c %*.lld %*.s %*.s %*.lld %.24s %s%s%s\n",
				dir_info->type, dir_info->perm, dir_info->attr, max->link,
				dir_info->link, max->owner, dir_info->owner, max->group,
				dir_info->group, max->size, dir_info->size, dir_info->date,
				dir_info->color, dir_info->name, STOP);
		dir_info = dir_info->next;
	}
	dir_info = begin_info;
}

void	print_stat_list(t_max *max, t_info *dir_info)
{
	t_info	*begin_info;

	begin_info = dir_info;
	if (dir_info)
		ft_printf("total %zu\n", max->blocks);
	while (dir_info)
	{
		ft_printf("%c%s%c %*.lld %*s %*s %*.lld %.24s %s%s%s ",
				dir_info->type, dir_info->perm, dir_info->attr, max->link,
				dir_info->link, max->owner, dir_info->owner, max->group,
				dir_info->group, max->size, dir_info->size, dir_info->date,
				dir_info->color, dir_info->name, STOP);
		if (dir_info->type == 'l')
			ft_printf("%s\n", dir_info->lpath);
		else
			write(1, "\n", 1);
		dir_info = dir_info->next;
	}
	dir_info = begin_info;
}

void	print_loc_list(t_rec *d_list)
{
	t_rec	*previous_dir;

	while (d_list)
	{
		previous_dir = d_list;
		ft_printf("%s%s%s\n", d_list->color, d_list->new_loc, STOP);
		free(d_list->new_loc);
		d_list = d_list->next;
		free(previous_dir);
	}
}
