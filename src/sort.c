/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 18:28:32 by jgalvani          #+#    #+#             */
/*   Updated: 2017/08/29 19:19:04 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	get_rec_time(t_rec *d_list, t_u16 flag)
{
	t_rec		*prev;
	struct stat	st;
	char		buf[1];

	prev = d_list;
	while (d_list)
	{
		if (readlink(d_list->new_loc, buf, 1) == 1)
			lstat(d_list->new_loc, &st);
		else
			stat(d_list->new_loc, &st);
		if (flag & ACCESS)
			d_list->time = st.st_atime;
		else if (flag & STATUS)
			d_list->time = st.st_ctime;
		else
			d_list->time = st.st_mtime;
		d_list = d_list->next;
	}
	d_list = prev;
}

void	sort_info(t_info *dir_info, t_u16 flag)
{
	if (!(flag & REVERSE) && !(flag & TIME) && !(flag & ACCESS) &&
				!(flag & STATUS))
		sort_info_ascii(dir_info);
	else if ((flag & REVERSE) && !(flag & TIME) && !(flag & ACCESS) &&
				!(flag & STATUS))
		sort_info_rev_ascii(dir_info);
	else if (!(flag & REVERSE) && ((flag & TIME) || (flag & ACCESS) ||
					(flag & STATUS)))
		sort_info_time(dir_info);
	else if ((flag & REVERSE) && ((flag & TIME) || (flag & ACCESS) ||
					(flag & STATUS)))
		sort_info_rev_time(dir_info);
}

void	sort_rec(t_rec *d_list, t_u16 flag)
{
	if (!(flag & REVERSE) && !(flag & TIME) && !(flag & ACCESS) &&
				!(flag & STATUS))
		sort_rec_ascii(d_list);
	else if ((flag & REVERSE) && !(flag & TIME) && !(flag & ACCESS) &&
				!(flag & STATUS))
		sort_rec_rev_ascii(d_list);
	else if (!(flag & REVERSE) && ((flag & TIME) || (flag & ACCESS) ||
					(flag & STATUS)))
	{
		get_rec_time(d_list, flag);
		sort_rec_time(d_list);
	}
	else if ((flag & REVERSE) && ((flag & TIME) || (flag & ACCESS) ||
					(flag & STATUS)))
	{
		get_rec_time(d_list, flag);
		sort_rec_rev_time(d_list);
	}
}

void	swap_info(t_info *next, t_info *dir_info)
{
	t_info	tmp;

	tmp = (t_info){dir_info->attr, dir_info->blocks, dir_info->type,
		dir_info->perm, dir_info->link, dir_info->owner, dir_info->group,
		dir_info->size, dir_info->date, dir_info->name, dir_info->color,
		dir_info->lpath, dir_info->time, 0};
	*dir_info = (t_info){next->attr, next->blocks, next->type, next->perm,
		next->link, next->owner, next->group, next->size,
		next->date, next->name, next->color, next->lpath, next->time,
		dir_info->next};
	*next = (t_info){tmp.attr, tmp.blocks, tmp.type, tmp.perm, tmp.link,
		tmp.owner, tmp.group, tmp.size, tmp.date, tmp.name, tmp.color,
		tmp.lpath, tmp.time, next->next};
	next = dir_info->next;
}

void	swap_rec(t_rec *next, t_rec *d_list)
{
	t_rec	tmp;

	tmp.new_loc = d_list->new_loc;
	tmp.color = d_list->color;
	tmp.time = d_list->time;
	d_list->new_loc = next->new_loc;
	d_list->color = next->color;
	d_list->time = next->time;
	next->new_loc = tmp.new_loc;
	next->color = tmp.color;
	next->time = tmp.time;
	next = d_list->next;
}
