/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 18:24:58 by jgalvani          #+#    #+#             */
/*   Updated: 2017/08/31 16:36:55 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	sort_info_time(t_info *dir_info)
{
	t_info		*next;

	while (dir_info)
	{
		next = dir_info->next;
		while (next)
		{
			if (next->time == dir_info->time)
			{
				if ((ft_strcmp(next->name, dir_info->name)) < 0)
					swap_info(next, dir_info);
			}
			if (next->time > dir_info->time)
				swap_info(next, dir_info);
			else
				next = next->next;
		}
		dir_info = dir_info->next;
	}
}

void	sort_info_rev_time(t_info *dir_info)
{
	t_info		*next;

	while (dir_info)
	{
		next = dir_info->next;
		while (next)
		{
			if (next->time == dir_info->time)
			{
				if ((ft_strcmp(next->name, dir_info->name)) > 0)
					swap_info(next, dir_info);
			}
			if (next->time < dir_info->time)
				swap_info(next, dir_info);
			else
				next = next->next;
		}
		dir_info = dir_info->next;
	}
}

void	sort_rec_rev_time(t_rec *d_list)
{
	t_rec		*next;

	while (d_list)
	{
		next = d_list->next;
		while (next)
		{
			if (next->time == d_list->time)
			{
				if ((ft_strcmp(next->new_loc, d_list->new_loc)) > 0)
					swap_rec(next, d_list);
			}
			if (next->time < d_list->time)
				swap_rec(next, d_list);
			else
				next = next->next;
		}
		d_list = d_list->next;
	}
}

void	sort_rec_time(t_rec *d_list)
{
	t_rec		*next;

	while (d_list)
	{
		next = d_list->next;
		while (next)
		{
			if (next->time == d_list->time)
			{
				if ((ft_strcmp(next->new_loc, d_list->new_loc)) < 0)
					swap_rec(next, d_list);
			}
			if (next->time > d_list->time)
				swap_rec(next, d_list);
			else
				next = next->next;
		}
		d_list = d_list->next;
	}
}

void	get_ctime(t_dir *curr, t_info *dir_info, t_u16 flag)
{
	char	*date;
	time_t	timer;

	if (!(flag & FULL_TIME))
	{
		date = ft_strdup(ctime(&curr->stat.st_ctime) + 4);
		timer = time(&timer);
		dir_info->date = ft_strnew(12);
		if (timer - curr->stat.st_ctime < SIX_MONTHS)
			dir_info->date = ft_strncpy(dir_info->date, date, 12);
		else
		{
			dir_info->date = ft_strncpy(dir_info->date, date, 7);
			dir_info->date = ft_strncat(dir_info->date, date + 15, 5);
		}
		free(date);
	}
	else
		dir_info->date = ft_strdup(ctime(&curr->stat.st_ctime));
	dir_info->time = curr->stat.st_ctime;
}
