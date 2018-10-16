/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:42:19 by bwang-do          #+#    #+#             */
/*   Updated: 2017/12/29 16:10:16 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *first;
	t_list *new;
	t_list *tmp;

	if (!lst || !(*f))
		return (NULL);
	tmp = (*f)(lst);
	if ((new = ft_lstnew(tmp->content, tmp->content_size)) == NULL)
		return (NULL);
	first = new;
	lst = lst->next;
	while (lst)
	{
		tmp = (*f)(lst);
		if (!(new->next = (ft_lstnew(tmp->content, tmp->content_size))))
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (first);
}
