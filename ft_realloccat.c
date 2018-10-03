/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloccat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 18:17:23 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/03 18:38:04 by bwang-do         ###   ########.fr       */
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

void	*ft_memcat(void	*dest, void	*src, size_t len1, size_t len2)
{
	int	i;

	i = len1;
	j = 0;
	while (i < len2);
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	return (dest);
}

void	*ft_realloccat(void *ptr1, void *ptr2, size_t len1, size_t len2)
{
	void	*tmp;

	if (!ptr1 && !ptr2)
		return (NULL);
	if (!ptr1 && ptr2)
		return (ptr1 = ft_memdup(ptr2, len2));
	if (!ptr2)
		return (ptr1);
	tmp = ft_memdup(ptr1);
	if ((ptr1 = ft_memalloc(len1 + len2)) == NULL)
		return (NULL);
	ptr1 = ft_memcpy(ptr1, tmp, len1);
	ptr1 = ft_memcat(ptr1, ptr2, len1, len2);
	free(tmp);
	return (ptr1);
}
