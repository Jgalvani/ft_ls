/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 17:33:06 by jgalvani          #+#    #+#             */
/*   Updated: 2017/08/29 18:45:18 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void		get_rec_dir_loc(t_rec *d_list, t_u16 flag)
{
	t_rec	*previous_dir;
	char	buf[1];

	sort_rec(d_list, flag);
	if (flag & LARGE)
	{
		print_rec_link(d_list, flag, buf);
		print_rec_reg(d_list, flag);
	}
	while (d_list)
	{
		previous_dir = d_list;
		if (!(flag & LARGE) || readlink(d_list->new_loc, buf, 1) == -1)
			print_dir(d_list->new_loc, flag, 1);
		free(d_list->new_loc);
		d_list = d_list->next;
		free(previous_dir);
		if (d_list)
			write(1, "\n", 1);
	}
}

void		single_print(char *name, t_u16 flag)
{
	char	buf[1];
	t_dir	curr;

	if (flag & LARGE && readlink(name, buf, 1) == 1)
		print_link(name, flag);
	else if (flag & LARGE && (curr.dir = opendir(name)) == NULL)
	{
		if (errno == ENOTDIR)
			print_reg(name, flag);
	}
	if (curr.dir != NULL)
		closedir(curr.dir);
	print_dir(name, flag, 0);
}

void		get_dir_loc(int ac, char **av, t_u16 flag, int i)
{
	t_rec	*d_list;

	d_list = NULL;
	if (ac - i > 1)
	{
		while (i < ac)
		{
			d_list = save_argument(av[i], d_list);
			i++;
		}
		get_rec_dir_loc(d_list, flag);
	}
	else
		single_print(av[i], flag);
}

t_rec		*print_loc(t_dir *curr, t_rec *d_list, t_u16 flag, char *loc)
{
	t_rec	*rec_list;
	bool	boolean;

	rec_list = NULL;
	while ((curr->dirent = readdir(curr->dir)))
	{
		if ((boolean = choose_rec_stat(loc, curr)))
		{
			if ((!(flag & ALL) && curr->dirent->d_name[0] != '.') ||
					((flag & ALL)))
				d_list = save_dir(curr, d_list);
			if ((flag & RECURSIVE && curr->dirent->d_type == DT_DIR) &&
					((ft_strcmp(curr->dirent->d_name, ".") &&
					ft_strcmp(curr->dirent->d_name, "..") && flag & ALL) ||
					(curr->dirent->d_name[0] != '.' && !(flag & ALL))))
				rec_list = save_rec(loc, curr->dirent->d_name, rec_list);
		}
	}
	if (!(flag & NO_SORT))
		sort_rec(d_list, flag);
	print_loc_list(d_list);
	return (rec_list);
}

void		print_dir(char *location, t_u16 flag, bool boolean)
{
	t_dir	curr;
	t_rec	*d_list;
	t_rec	*rec_list;

	d_list = NULL;
	rec_list = NULL;
	if ((curr.dir = opendir(location)) > 0)
	{
		if (flag & RECURSIVE || boolean)
			ft_printf("%s%s:%s\n", GREEN, location, STOP);
		if (flag & LARGE)
			rec_list = print_stat(&curr, flag, location);
		else if (!(flag & LARGE))
			rec_list = print_loc(&curr, d_list, flag, location);
		if (closedir(curr.dir) == -1)
			dir_error(location);
	}
	else if (!curr.dir && errno != ENOTDIR)
		dir_error(location);
	else if (!curr.dir && errno == ENOTDIR && !(flag & LARGE))
		ft_printf("%s\n", location);
	if (flag & RECURSIVE)
		get_rec_dir_loc(rec_list, flag);
}
