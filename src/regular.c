/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regular.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 15:48:01 by jgalvani          #+#    #+#             */
/*   Updated: 2017/09/04 17:24:37 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	type_date(t_dir *curr, t_info *dir_info, t_u16 flag)
{
	if (flag & ACCESS)
		get_atime(curr, dir_info, flag);
	else
		get_mtime(curr, dir_info, flag);
	dir_info->type = '-';
	dir_info->link = curr->stat.st_nlink;
}

t_info	*save_reg_info(t_info *dir_info, t_u16 flag, t_dir *curr, char *name)
{
	t_info	*new_info;
	t_info	*begin_info;

	new_info = (t_info*)malloc(sizeof(t_info));
	type_date(curr, new_info, flag);
	owner_group_attr(new_info, curr, name);
	new_info->perm = get_perm(curr);
	new_info->size = curr->stat.st_size;
	new_info->blocks = curr->stat.st_blocks;
	new_info->name = ft_strdup(name);
	new_info->color = WHITE;
	new_info->next = NULL;
	if (!dir_info)
		return (new_info);
	else
	{
		begin_info = dir_info;
		while (dir_info->next)
			dir_info = dir_info->next;
		dir_info->next = new_info;
	}
	return (begin_info);
}

t_info	*get_reg_list(t_rec *d_list, t_info *dir_info, t_u16 flag)
{
	t_dir	curr;

	while (d_list)
	{
		if (flag & LARGE && (curr.dir = opendir(d_list->new_loc)) == NULL)
		{
			if (errno == ENOTDIR)
			{
				if ((stat(d_list->new_loc, &curr.stat)) != -1)
					dir_info = save_reg_info(dir_info, flag, &curr,
							d_list->new_loc);
			}
		}
		else
			closedir(curr.dir);
		d_list = d_list->next;
	}
	return (dir_info);
}

void	print_rec_reg(t_rec *d_list, t_u16 flag)
{
	t_rec	*prev;
	t_info	*dir_info;
	t_max	max;

	dir_info = NULL;
	max = (t_max){0, 0, 0, 0, 0, 0};
	prev = d_list;
	dir_info = get_reg_list(d_list, dir_info, flag);
	get_max(&max, dir_info);
	if (!(flag & NO_SORT))
		sort_info(dir_info, flag);
	print_reg_list(&max, dir_info);
	free_dir_info(dir_info);
	d_list = prev;
}

void	print_reg(char *name, t_u16 flag)
{
	t_info	*dir_info;
	t_dir	curr;

	dir_info = NULL;
	if ((stat(name, &curr.stat)) != -1)
	{
		dir_info = save_reg_info(dir_info, flag, &curr, name);
		ft_printf("%c%s%c %lld %s %s %lld %.24s %s%s%s\n",
				dir_info->type, dir_info->perm, dir_info->attr, dir_info->link,
				dir_info->owner, dir_info->group, dir_info->size,
				dir_info->date, dir_info->color, dir_info->name, STOP);
		free_dir_info(dir_info);
	}
}
