/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 13:30:18 by jgalvani          #+#    #+#             */
/*   Updated: 2017/01/16 13:34:57 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

# define BUFF_SIZE 100

typedef struct		s_chain
{
	char			buf[BUFF_SIZE + 1];
	int				fd;
	int				read;
	int				next_line;
	struct s_chain	*next;
}					t_chain;

int					get_next_line(const int fd, char **line);

#endif
