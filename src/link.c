/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 21:56:18 by jgalvani          #+#    #+#             */
/*   Updated: 2017/08/29 17:31:12 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	owner_group_attr(t_info *dir_info, t_dir *curr, char *name)
{
	struct passwd	*pwuid;
	struct group	*grgid;
	acl_t			acl;

	pwuid = getpwuid(curr->stat.st_uid);
	dir_info->owner = ft_strdup(pwuid->pw_name);
	grgid = getgrgid(curr->stat.st_gid);
	dir_info->group = ft_strdup(grgid->gr_name);
	dir_info->attr = ' ';
	if ((acl = acl_get_link_np(name, ACL_TYPE_EXTENDED)))
		dir_info->attr = '+';
	if ((listxattr(name, NULL, 0, XATTR_NOFOLLOW)) > 0)
		dir_info->attr = '@';
	acl_free((void*)acl);
}

void	link_date(t_dir *curr, t_info *dir_info, t_u16 flag, char *name)
{
	char	buf[1024];
	ssize_t	size;

	if (flag & ACCESS)
		get_atime(curr, dir_info, flag);
	else
		get_mtime(curr, dir_info, flag);
	if ((size = readlink(name, buf, sizeof(buf) - 1)) != -1)
		buf[size] = '\0';
	dir_info->lpath = ft_strnew(3 + ft_strlen(buf));
	dir_info->lpath = ft_strcpy(dir_info->lpath, "-> ");
	dir_info->lpath = ft_strcat(dir_info->lpath, buf);
	dir_info->type = 'l';
	dir_info->link = curr->stat.st_nlink;
}

t_info	*save_link_info(t_info *dir_info, t_u16 flag, t_dir *curr, char *name)
{
	t_info	*new_info;
	t_info	*begin_info;

	new_info = (t_info*)malloc(sizeof(t_info));
	link_date(curr, new_info, flag, name);
	owner_group_attr(new_info, curr, name);
	new_info->perm = get_perm(curr);
	new_info->size = curr->stat.st_size;
	new_info->blocks = curr->stat.st_blocks;
	new_info->name = ft_strdup(name);
	new_info->color = PURPLE;
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

void	print_link(char *name, t_u16 flag)
{
	t_info	*dir_info;
	t_dir	curr;

	dir_info = NULL;
	if ((lstat(name, &curr.stat)) != -1)
	{
		dir_info = save_link_info(dir_info, flag, &curr, name);
		ft_printf("%c%s%c %lld %s %s %lld %.24s %s%s%s %s\n",
				dir_info->type, dir_info->perm, dir_info->attr,
				dir_info->link, dir_info->owner, dir_info->group,
				dir_info->size, dir_info->date, dir_info->color,
				dir_info->name, STOP, dir_info->lpath);
		free_dir_info(dir_info);
	}
}

void	print_rec_link(t_rec *d_list, t_u16 flag, char *buf)
{
	t_rec	*prev;
	t_info	*dir_info;
	t_dir	curr;
	t_max	max;

	dir_info = NULL;
	max = (t_max){0, 0, 0, 0, 0};
	prev = d_list;
	while (d_list)
	{
		if (flag & LARGE && readlink(d_list->new_loc, buf, 1) == 1)
		{
			if ((lstat(d_list->new_loc, &curr.stat)) != -1)
				dir_info = save_link_info(dir_info, flag, &curr,
						d_list->new_loc);
		}
		d_list = d_list->next;
	}
	get_max(&max, dir_info);
	if (!(flag & NO_SORT))
		sort_info(dir_info, flag);
	if (dir_info)
		print_link_list(&max, dir_info);
	free_dir_info(dir_info);
	d_list = prev;
}
