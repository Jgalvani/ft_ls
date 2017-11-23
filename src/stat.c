/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 18:29:37 by jgalvani          #+#    #+#             */
/*   Updated: 2017/09/04 17:23:23 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

bool	get_stat(char *loc, struct stat *st, char *d_name)
{
	char	*new_loc;

	if (!ft_strcmp(loc, ""))
	{
		if (stat(d_name, st) == -1)
			return (0);
		return (1);
	}
	new_loc = get_new_loc(loc, d_name);
	if (stat(new_loc, st) == -1)
	{
		perror("ft_ls");
		free(new_loc);
		return (0);
	}
	free(new_loc);
	return (1);
}

bool	get_lstat(char *location, struct stat *st, char *d_name)
{
	char	*new_loc;

	if (!ft_strcmp(location, ""))
	{
		if (lstat(d_name, st) == -1)
		{
			perror("ft_ls");
			return (0);
		}
		return (1);
	}
	new_loc = get_new_loc(location, d_name);
	if (lstat(new_loc, st) == -1)
	{
		perror("ft_ls");
		free(new_loc);
		return (0);
	}
	free(new_loc);
	return (1);
}

bool	choose_stat(char *loc, t_dir *curr)
{
	bool		boolean;

	if (curr->dirent->d_type != DT_LNK)
		boolean = get_stat(loc, &curr->stat, curr->dirent->d_name);
	else
		boolean = get_lstat(loc, &curr->stat, curr->dirent->d_name);
	return (boolean);
}

void	print_info(t_info *dir_info, t_max *max, t_u16 flag)
{
	get_max(max, dir_info);
	if (!(flag & NO_SORT))
		sort_info(dir_info, flag);
	print_stat_list(max, dir_info);
	free_dir_info(dir_info);
}

t_rec	*print_stat(t_dir *curr, t_u16 flag, char *loc)
{
	t_info			*dir_info;
	t_max			max;
	t_rec			*r_lst;

	max = (t_max){0, 0, 0, 0, 0, 0};
	dir_info = NULL;
	r_lst = NULL;
	while ((curr->dirent = readdir(curr->dir)))
	{
		if ((!(flag & ALL) && curr->dirent->d_name[0] != '.') || ((flag & ALL)))
		{
			if ((choose_stat(loc, curr) == 1))
			{
				dir_info = info(dir_info, curr, loc, flag);
				if ((flag & RECURSIVE && curr->dirent->d_type == DT_DIR) &&
					((ft_strcmp(curr->dirent->d_name, ".") &&
					ft_strcmp(curr->dirent->d_name, "..") && flag & ALL) ||
					(curr->dirent->d_name[0] != '.' && !(flag & ALL))))
					r_lst = save_rec(loc, curr->dirent->d_name, r_lst, flag);
			}
		}
	}
	if (dir_info)
		print_info(dir_info, &max, flag);
	return (r_lst);
}
