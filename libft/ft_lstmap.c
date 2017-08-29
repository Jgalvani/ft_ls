/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:16:22 by jgalvani          #+#    #+#             */
/*   Updated: 2016/11/24 16:23:12 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*p;
	t_list	*result;

	p = f(lst);
	if (!lst || !f)
		return (0);
	if (!(result = ft_lstnew(p->content, p->content_size)))
		return (0);
	new_lst = result;
	lst = lst->next;
	while (lst)
	{
		p = p->next;
		p = f(lst);
		if (!(new_lst->next = ft_lstnew(p->content, p->content_size)))
			return (0);
		lst = lst->next;
		new_lst = new_lst->next;
	}
	return (result);
}
