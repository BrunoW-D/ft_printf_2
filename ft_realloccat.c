/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloccat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 18:17:23 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/26 20:03:58 by bwang-do         ###   ########.fr       */
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
	void	*ret;

	if (!p1 && !p2)
		return (NULL);
	if (!p1 && p2)
		return (ret = ft_memdup(p2, len2));
	if (!p2)
		return (p1);
	tmp = ft_memdup(p1, len1);
	free(p1);
	if ((ret = ft_memalloc(len1 + len2)) == NULL)
		return (NULL);
	ret = ft_memcpy(ret, tmp, len1);
	ret = ft_memcat(ret, p2, len1, len2);
	free(tmp);
	return (ret);
}
