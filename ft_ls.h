/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 17:21:07 by jgalvani          #+#    #+#             */
/*   Updated: 2017/08/29 22:54:16 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <dirent.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <pwd.h>
# include <grp.h>

# define SIX_MONTHS 16560000

enum
{
	LARGE = 0b00000001,
	RECURSIVE = 0b00000010,
	ALL = 0b00000100,
	REVERSE = 0b00001000,
	TIME = 0b00010000,
	ACCESS = 0b00100000,
	STATUS = 0b01000000,
	NO_SORT = 0b10000000,
	FULL_TIME = 1 << 8,
	FIRST = 1 << 9
};

typedef union		u_flag
{
	struct
	{
		t_u16		large: 1;
		t_u16		recursive: 1;
		t_u16		all: 1;
		t_u16		reverse: 1;
		t_u16		time: 1;
		t_u16		access: 1;
		t_u16		no_sort: 1;
		t_u16		full_time: 1;
	}				bit;
	t_u16			all: 8;
}					t_flag;

typedef struct		s_perm
{
	int				tab[10];
}					t_perm;

typedef struct		s_rec
{
	char			*new_loc;
	t_u8			color;
	time_t			time;
	struct s_rec	*next;
}					t_rec;

typedef struct		s_dir
{
	DIR				*dir;
	struct dirent	*dirent;
	struct stat		stat;
}					t_dir;

typedef struct		s_info
{
	char			attr;
	blkcnt_t		blocks;
	char			type;
	char			*perm;
	t_u64			link;
	char			*owner;
	char			*group;
	off_t			size;
	char			*date;
	char			*name;
	t_u8			color;
	char			*lpath;
	time_t			time;
	struct s_info	*next;
}					t_info;

typedef struct		s_max
{
	int				link;
	int				owner;
	int				group;
	int				size;
	size_t			blocks;
}					t_max;

void				get_dir_loc(int ac, char **av, t_u16 flag, int i);
void				get_rec_dir_loc(t_rec *d_list, t_u16 flag);
void				print_dir(char *location, t_u16 flag);
void				get_ctime(t_dir *curr, t_info *dir_info, t_u16 flag);

t_u16				set_flag(char *str);
t_u8				assign_color(unsigned char type);
char				*get_new_loc(char *location, char *d_name);

void				flag_error(char *str);
void				dir_error(char *location);

void				print_stat_list(t_max *max, t_info *dir_info);
void				print_link_list(t_max *max, t_info *dir_info);
void				print_loc_list(t_rec *d_list);

bool				get_stat(char *loc, struct stat *st, char *d_name);
bool				get_lstat(char *loc, struct stat *st, char *d_name);
t_rec				*print_stat(t_dir *curr, t_u16 flag, char *loc);
void				free_dir_info(t_info *dir_info);

char				*get_perm(t_dir *curr);
void				tld(t_dir *curr, t_info *d_info, t_u16 flag, char *loc);
void				get_max(t_max *max, t_info *info);
void				get_mtime(t_dir *curr, t_info *dir_info, t_u16 flag);
void				get_atime(t_dir *curr, t_info *dir_info, t_u16 flag);

t_rec				*save_argument(char *location, t_rec *d_list);
t_info				*info(t_info *d_info, t_dir *curr, char *loc, t_u16 fl);
t_rec				*save_rec(char *location, char *d_name, t_rec *d_list);
t_rec				*save_dir(t_dir *curr, t_rec *d_list);

void				swap_info(t_info *next, t_info *dir_info);
void				swap_rec(t_rec *next, t_rec *d_list);
void				sort_rec(t_rec *d_list, t_u16 flag);
void				sort_info(t_info *dir_info, t_u16 flag);

void				sort_info_ascii(t_info *dir_info);
void				sort_rec_ascii(t_rec *d_list);
void				sort_info_rev_ascii(t_info *dir_info);
void				sort_rec_rev_ascii(t_rec *d_list);

void				sort_info_time(t_info *dir_info);
void				sort_rec_time(t_rec *d_list);
void				sort_rec_rev_time(t_rec *d_list);
void				sort_info_rev_time(t_info *dir_info);

void				print_link(char *name, t_u16 flag);
void				print_rec_link(t_rec *d_list, t_u16 flag, char *buf);
void				owner_group_attr(t_info *dir_info, t_dir *curr, char *name);
bool				choose_rec_stat(char*loc, t_dir *curr);

void				print_reg(char *name, t_u16 flag);
void				print_rec_reg(t_rec *d_list, t_u16 flag);
void				print_reg_list(t_max *max, t_info *dir_info);
void				get_type(t_dir *curr, t_info *dir_info, char *loc);

#endif
