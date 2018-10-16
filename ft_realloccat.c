/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloccat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 18:17:23 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/16 16:59:10 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	*ft_memdup(void *src, size_t len)
{
	int		i;
	void	*cpy;

	if ((cpy = (void*)malloc(sizeof(void) * len)) == NULL)
		return (NULL);
	i = 0;
	while (i < len2)
	{
		cpy[i] = src[i];
		i++;
	}
	return (cpy);
}

void	*ft_memcat(void *dest, void *src, size_t len1, size_t len2)
{
	int	i;

	i = len1;
	j = 0;
	while (i < len2)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	return (dest);
}

void	*ft_realloccat(void *p1, void *p2, size_t len1, size_t len2)
{
	void	*tmp;

	if (!p1 && !p2)
		return (NULL);
	if (!p1 && p2)
		return (p1 = ft_memdup(p2, len2));
	if (!p2)
		return (p1);
	tmp = ft_memdup(p1);
	if ((p1 = ft_memalloc(len1 + len2)) == NULL)
		return (NULL);
	p1 = ft_memcpy(p1, tmp, len1);
	p1 = ft_memcat(p1, p2, len1, len2);
	free(tmp);
	return (p1);
}
