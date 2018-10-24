/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloccat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 18:17:23 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/24 19:40:16 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	*ft_memdup(void *src, size_t len)
{
	int			i;
	void		*cpy;
	char		*c;
	const char	*s;

	if ((cpy = (void*)malloc(sizeof(void) * len)) == NULL)
		return (NULL);
	c = (char*)cpy;
	s = (const char*)src;
	i = 0;
	while (i < len)
	{
		c[i] = s[i];
		i++;
	}
	return (cpy);
}

void	*ft_memcat(void *dest, void *src, size_t len1, size_t len2)
{
	int			i;
	int			j;
	char		*d;
	const char	*s;

	i = len1;
	j = 0;
	d = (char*)dest;
	s = (const char*)src;
	while (j < len2)
	{
		d[i] = s[j];
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
	tmp = ft_memdup(p1, len1);
	free(p1);
	p1 = NULL;
	if ((p1 = ft_memalloc(len1 + len2)) == NULL)
		return (NULL);
	p1 = ft_memcpy(p1, tmp, len1);
	p1 = ft_memcat(p1, p2, len1, len2);
	free(tmp);
	return (p1);
}
