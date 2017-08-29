/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:04:58 by jgalvani          #+#    #+#             */
/*   Updated: 2017/05/09 18:00:42 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		list->content_size = 0;
		free(list->content);
		tmp = list->next;
		free(list);
		list = tmp;
	}
}
