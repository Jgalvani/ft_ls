/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permissions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 21:47:53 by jgalvani          #+#    #+#             */
/*   Updated: 2017/08/29 18:49:02 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char	*suid_sgid_stickybit(char *perm, t_dir *curr)
{
	if (curr->stat.st_mode & S_ISUID)
	{
		if (perm[2] == 'x')
			perm[2] = 's';
		else
			perm[2] = 'S';
	}
	if (curr->stat.st_mode & S_ISGID)
	{
		if (perm[5] == 'x')
			perm[5] = 's';
		else
			perm[5] = 'S';
	}
	if (curr->stat.st_mode & S_ISVTX)
	{
		if (perm[8] == 'x')
			perm[8] = 't';
		else
			perm[8] = 'T';
	}
	return (perm);
}

char	*get_perm(t_dir *curr)
{
	char	*perm;
	char	*tab;
	t_perm	p;
	t_u16	i;

	i = 0;
	perm = ft_strnew(9);
	tab = "rwx";
	p = (t_perm){{S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH,
		S_IWOTH, S_IXOTH, 0}};
	while (p.tab[i])
	{
		if (curr->stat.st_mode & p.tab[i])
			perm[i] = tab[i % 3];
		else
			perm[i] = '-';
		i++;
	}
	perm[9] = '\0';
	perm = suid_sgid_stickybit(perm, curr);
	return (perm);
}

void	get_link(t_info *dir_info, t_dir *curr, char *loc)
{
	char	*new_loc;
	char	buf[1024];
	ssize_t	size;

	new_loc = get_new_loc(loc, curr->dirent->d_name);
	if ((size = readlink(new_loc, buf, sizeof(buf) - 1)) != -1)
		buf[size] = '\0';
	dir_info->lpath = ft_strnew(3 + ft_strlen(buf));
	dir_info->lpath = ft_strcpy(dir_info->lpath, "-> ");
	dir_info->lpath = ft_strcat(dir_info->lpath, buf);
	free(new_loc);
	dir_info->type = 'l';
}

void	get_type(t_dir *curr, t_info *dir_info, char *loc)
{
	if (curr->dirent->d_type == DT_DIR)
		dir_info->type = 'd';
	else if (curr->dirent->d_type == DT_LNK)
		get_link(dir_info, curr, loc);
	else if (curr->dirent->d_type == DT_CHR)
		dir_info->type = 'c';
	else if (curr->dirent->d_type == DT_BLK)
		dir_info->type = 'b';
	else if (curr->dirent->d_type == DT_SOCK)
		dir_info->type = 's';
	else if (curr->dirent->d_type == DT_FIFO)
		dir_info->type = 'p';
	else if (curr->dirent->d_type == DT_UNKNOWN)
		dir_info->type = '?';
	else
		dir_info->type = '-';
}

bool	choose_rec_stat(char *loc, t_dir *curr)
{
	bool	boolean;

	if (curr->dirent->d_type != DT_LNK)
		boolean = get_stat(loc, &curr->stat, curr->dirent->d_name);
	else
		boolean = get_lstat(loc, &curr->stat, curr->dirent->d_name);
	return (boolean);
}
