/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 18:28:32 by jgalvani          #+#    #+#             */
/*   Updated: 2017/09/04 17:25:57 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

time_t	get_rec_time(t_rec *d_list, t_u16 flag)
{
	struct stat	st;
	char		buf[1];

	if (readlink(d_list->new_loc, buf, 1) == 1)
		lstat(d_list->new_loc, &st);
	else
		stat(d_list->new_loc, &st);
	if (flag & ACCESS)
		return (st.st_atime);
	else if (flag & STATUS)
		return (st.st_ctime);
	else
		return (st.st_mtime);
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
		sort_rec_time(d_list);
	else if ((flag & REVERSE) && ((flag & TIME) || (flag & ACCESS) ||
				(flag & STATUS)))
		sort_rec_rev_time(d_list);
}

void	swap_info(t_info *next, t_info *dir_info)
{
	t_info	tmp;

	tmp = (t_info){dir_info->attr, dir_info->blocks, dir_info->type,
		dir_info->perm, dir_info->link, dir_info->owner, dir_info->group,
		dir_info->size, dir_info->date, dir_info->name, dir_info->color,
		dir_info->lpath, dir_info->time, dir_info->major, 0};
	*dir_info = (t_info){next->attr, next->blocks, next->type, next->perm,
		next->link, next->owner, next->group, next->size,
		next->date, next->name, next->color, next->lpath, next->time,
		next->major, dir_info->next};
	*next = (t_info){tmp.attr, tmp.blocks, tmp.type, tmp.perm, tmp.link,
		tmp.owner, tmp.group, tmp.size, tmp.date, tmp.name, tmp.color,
		tmp.lpath, tmp.time, tmp.major, next->next};
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
