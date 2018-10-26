/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloccat_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 19:51:28 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/26 20:03:45 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	*ft_realloccat_free(void *p1, void *p2, size_t l1, size_t l2)
{
	void	*tmp;
	void	*ret;

	if (!p1 && !p2)
		return (NULL);
	if (!p1 && p2)
	{
		ret = ft_memdup(p2, l2);
		free(p2);
		p2 = NULL;
		return (ret);
	}
	if (!p2)
		return (p1);
	tmp = ft_memdup(p1, l1);
	free(p1);
	if ((ret = ft_memalloc(l1 + l2)) == NULL)
		return (NULL);
	ret = ft_memcpy(ret, tmp, l1);
	ret = ft_memcat(ret, p2, l1, l2);
	free(tmp);
	free(p2);
	p2 = NULL;
	return (ret);
}
