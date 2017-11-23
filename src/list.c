/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 18:30:53 by jgalvani          #+#    #+#             */
/*   Updated: 2017/09/04 17:11:44 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_rec	*save_argument(char *location, t_rec *d_list, t_u16 flag)
{
	t_rec	*new_dir;
	t_rec	*begin_dir;

	new_dir = (t_rec*)malloc(sizeof(t_rec) * 1);
	new_dir->new_loc = ft_strdup(location);
	new_dir->time = get_rec_time(new_dir, flag);
	new_dir->next = NULL;
	if (!d_list)
		return (new_dir);
	else
	{
		begin_dir = d_list;
		while (d_list->next)
			d_list = d_list->next;
		d_list->next = new_dir;
	}
	return (begin_dir);
}

t_rec	*save_dir(t_dir *curr, t_rec *d_list, t_u16 flag, char *loc)
{
	t_rec	*new_dir;
	t_rec	*begin_dir;

	new_dir = (t_rec*)malloc(sizeof(t_rec) * 1);
	new_dir->new_loc = get_new_loc(loc, curr->dirent->d_name);
	new_dir->color = assign_color(curr->dirent->d_type);
	new_dir->time = get_rec_time(new_dir, flag);
	free(new_dir->new_loc);
	new_dir->new_loc = ft_strdup(curr->dirent->d_name);
	new_dir->next = NULL;
	if (!d_list)
		return (new_dir);
	else
	{
		begin_dir = d_list;
		while (d_list->next)
			d_list = d_list->next;
		d_list->next = new_dir;
	}
	return (begin_dir);
}

t_rec	*save_rec(char *loc, char *d_name, t_rec *d_list, t_u16 flag)
{
	t_rec	*new_dir;
	t_rec	*begin_dir;

	new_dir = (t_rec*)malloc(sizeof(t_rec) * 1);
	new_dir->new_loc = get_new_loc(loc, d_name);
	new_dir->time = get_rec_time(new_dir, flag);
	new_dir->next = NULL;
	if (!d_list)
		return (new_dir);
	else
	{
		begin_dir = d_list;
		while (d_list->next)
			d_list = d_list->next;
		d_list->next = new_dir;
	}
	return (begin_dir);
}

t_info	*get_owner_group_attr(t_info *new_info, t_dir *curr, char *location)
{
	struct passwd	*pwuid;
	struct group	*grgid;
	acl_t			acl;
	char			*new_loc;

	pwuid = getpwuid(curr->stat.st_uid);
	new_info->owner = ft_strdup(pwuid->pw_name);
	grgid = getgrgid(curr->stat.st_gid);
	new_info->group = ft_strdup(grgid->gr_name);
	new_info->attr = ' ';
	new_loc = get_new_loc(location, curr->dirent->d_name);
	if ((acl = acl_get_link_np(new_loc, ACL_TYPE_EXTENDED)))
		new_info->attr = '+';
	if ((listxattr(new_loc, NULL, 0, XATTR_NOFOLLOW)) > 0)
		new_info->attr = '@';
	acl_free((void*)acl);
	free(new_loc);
	return (new_info);
}

t_info	*info(t_info *d_info, t_dir *curr, char *loc, t_u16 flag)
{
	t_info			*new_info;
	t_info			*begin_info;

	new_info = (t_info*)malloc(sizeof(t_info) * 1);
	tld(curr, new_info, flag, loc);
	new_info = get_owner_group_attr(new_info, curr, loc);
	new_info->perm = get_perm(curr);
	new_info->blocks = curr->stat.st_blocks;
	new_info->name = ft_strdup(curr->dirent->d_name);
	new_info->color = assign_color(curr->dirent->d_type);
	new_info->next = NULL;
	if (!d_info)
		return (new_info);
	else
	{
		begin_info = d_info;
		while (d_info->next)
			d_info = d_info->next;
		d_info->next = new_info;
	}
	return (begin_info);
}
