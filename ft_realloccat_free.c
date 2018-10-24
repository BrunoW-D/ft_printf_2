/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloccat_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 19:51:28 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/24 20:05:58 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	*ft_realloccat_free(void *p1, void *p2, size_t l1, size_t l2)
{
	void	*tmp;

	if (!p1 && !p2)
		return (NULL);
	if (!p1 && p2)
		return (p1 = ft_memdup(p2, l2));
	if (!p2)
		return (p1);
	tmp = ft_memdup(p1, l1);
	free(p1);
	p1 = NULL;
	if ((p1 = ft_memalloc(l1 + l2)) == NULL)
		return (NULL);
	p1 = ft_memcpy(p1, tmp, l1);
	p1 = ft_memcat(p1, p2, l1, l2);
	free(tmp);
	free(p2);
	p2 = NULL;
	return (p1);
}
