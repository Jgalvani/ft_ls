/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:19:16 by jgalvani          #+#    #+#             */
/*   Updated: 2017/01/11 13:12:47 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		get_end(char **str, t_chain *data)
{
	char		*copy;
	int			i;

	i = 0;
	while (data->buf[i] != '\n')
		i++;
	data->next_line = 1;
	copy = ft_strnew(ft_strlen(*str) + i);
	copy = ft_strcpy(copy, *str);
	free(*str);
	*str = copy;
	copy += ft_strlen(copy);
	copy = ft_strncpy(copy, (data->buf), i);
}

static char		*get_start(char *str, t_chain *data)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < BUFF_SIZE && data->buf[i] != '\n')
		i++;
	i++;
	while (i <= BUFF_SIZE && data->buf[i])
	{
		data->buf[j] = data->buf[i];
		i++;
		j++;
	}
	str = ft_strnew(j);
	data->buf[j] = '\0';
	j = 0;
	while (j < BUFF_SIZE && data->buf[j] != '\n' && data->buf[j])
	{
		str[j] = data->buf[j];
		j++;
	}
	return (str);
}

static int		get_line(t_chain *data, char **str)
{
	if (data->read < BUFF_SIZE)
		data->buf[0] = '\0';
	while (data->read)
	{
		if (!data->next_line)
		{
			if ((data->read = read(data->fd, &(data->buf), BUFF_SIZE)) == -1)
				return (0);
			if (ft_strnstr((data->buf), "\n", BUFF_SIZE))
			{
				get_end(&*str, data);
				return (1);
			}
			if (data->read)
			{
				*str = ft_strjoin(*str, data->buf);
			}
		}
		ft_bzero((data->buf), BUFF_SIZE + 1);
		data->next_line = 0;
	}
	return (1);
}

static t_chain	*get_data(t_chain *data, t_chain **begin, int fd)
{
	t_chain	*previous;

	previous = 0;
	data = *begin;
	while (data)
	{
		if (data->fd == fd)
			return (data);
		previous = data;
		data = data->next;
	}
	if (!data)
	{
		if (!(data = (t_chain*)malloc(sizeof(t_chain))))
			return (0);
		data->fd = fd;
		data->next = 0;
		data->next_line = 0;
		ft_bzero((data->buf), BUFF_SIZE + 1);
	}
	if (previous)
		previous->next = data;
	if (!*begin)
		*begin = data;
	return (data);
}

int				get_next_line(const int fd, char **line)
{
	t_chain			*data;
	static t_chain	*begin;

	data = 0;
	if (!line || fd < 0)
		return (-1);
	if (!(data = get_data(data, &begin, fd)))
		return (-1);
	data->read = BUFF_SIZE + 1;
	*line = ft_strnew(0);
	if (ft_strnstr((data->buf), "\n", BUFF_SIZE))
	{
		*line = get_start(*line, data);
		if (data->buf[ft_strlen(*line)] == '\n')
			return (1);
	}
	if (!(get_line(data, &*line)))
		return (-1);
	if (data->read == 0 && !*line[0])
		return (0);
	return (1);
}
