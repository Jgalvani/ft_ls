/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 18:32:13 by jgalvani          #+#    #+#             */
/*   Updated: 2017/09/04 17:42:12 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	get_mtime(t_dir *curr, t_info *dir_info, t_u16 flag)
{
	char			*date;
	time_t			timer;

	if (!(flag & FULL_TIME))
	{
		date = ft_strdup(ctime(&curr->stat.st_mtime) + 4);
		timer = time(&timer);
		dir_info->date = ft_strnew(12);
		if (timer - curr->stat.st_mtime < SIX_MONTHS)
			dir_info->date = ft_strncpy(dir_info->date, date, 12);
		else
		{
			dir_info->date = ft_strncpy(dir_info->date, date, 7);
			dir_info->date = ft_strncat(dir_info->date, date + 15, 5);
		}
		free(date);
	}
	else
		dir_info->date = ft_strdup(ctime(&curr->stat.st_mtime));
	dir_info->time = curr->stat.st_mtime;
}

void	get_atime(t_dir *curr, t_info *dir_info, t_u16 flag)
{
	char			*date;
	time_t			timer;

	if (!(flag & FULL_TIME))
	{
		date = ft_strdup(ctime(&curr->stat.st_atime) + 4);
		timer = time(&timer);
		dir_info->date = ft_strnew(12);
		if (timer - curr->stat.st_atime < SIX_MONTHS)
			dir_info->date = ft_strncpy(dir_info->date, date, 12);
		else
		{
			dir_info->date = ft_strncpy(dir_info->date, date, 7);
			dir_info->date = ft_strncat(dir_info->date, date + 15, 5);
		}
		free(date);
	}
	else
		dir_info->date = ft_strdup(ctime(&curr->stat.st_atime));
	dir_info->time = curr->stat.st_atime;
}

void	tld(t_dir *curr, t_info *dir_info, t_u16 flag, char *loc)
{
	if (flag & ACCESS)
		get_atime(curr, dir_info, flag);
	else if (flag & STATUS)
		get_ctime(curr, dir_info, flag);
	else
		get_mtime(curr, dir_info, flag);
	get_type(curr, dir_info, loc);
	dir_info->link = curr->stat.st_nlink;
	if (dir_info->type != 'c' && dir_info->type != 'b')
	{
		dir_info->size = curr->stat.st_size;
		dir_info->major = 0;
	}
	else
	{
		dir_info->size = minor(curr->stat.st_rdev);
		dir_info->major = major(curr->stat.st_rdev);
	}
}

void	get_max(t_max *max, t_info *dir_info)
{
	t_info	*begin_info;
	int		len;

	begin_info = dir_info;
	while (dir_info)
	{
		if ((len = ft_countmax(dir_info->link)) > max->link)
			max->link = len;
		if ((len = ft_countmax(dir_info->size)) > max->size)
			max->size = len;
		if ((len = ft_countmax(dir_info->major)) > max->major)
			max->major = len;
		if ((len = ft_strlen(dir_info->owner)) > max->owner)
			max->owner = len;
		if ((len = ft_strlen(dir_info->group)) > max->group)
			max->group = len;
		max->blocks += dir_info->blocks;
		dir_info = dir_info->next;
	}
	dir_info = begin_info;
}

void	free_dir_info(t_info *dir_info)
{
	t_info	*prev_info;

	while (dir_info)
	{
		prev_info = dir_info;
		free(dir_info->perm);
		free(dir_info->owner);
		free(dir_info->group);
		free(dir_info->name);
		free(dir_info->date);
		if (dir_info->type == 'l')
			free(dir_info->lpath);
		dir_info = dir_info->next;
		free(prev_info);
	}
}
