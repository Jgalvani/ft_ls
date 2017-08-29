/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:33:36 by jgalvani          #+#    #+#             */
/*   Updated: 2016/11/24 16:22:21 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	list = ft_memalloc(sizeof(t_list));
	if (list)
	{
		if (content == 0)
		{
			list->content = 0;
			list->content_size = 0;
		}
		else
		{
			list->content = ft_memalloc(content_size);
			list->content = ft_memcpy(list->content, content, content_size);
			list->content_size = content_size;
		}
		list->next = 0;
		return (list);
	}
	free(list);
	return (0);
}
