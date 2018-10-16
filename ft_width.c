/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:34:24 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/16 19:43:52 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_width(char *str, int len, t_spec *spec)
{
	int	left;
/* realloccat au lieu de realloc_free */	
	left = spec->width - len;
	if (left <= 0)
		return (str);
	if (spec->flags[1] == 2)
	{
		if (spec->prec == 0)
		{
			if (!(str = ft_realloc_free(ft_nchar('0', left), str)))
				return (NULL);
		}
		else
			spec->flags[1] = 0;
	}
	if (spec->flags[1] == 1)
	{
		if (!(str = ft_realloc_free(str, ft_nchar(' ', left))))
			return (NULL);
	}
	if (spec->flags[1] == 0)
		str = ft_realloc_free(ft_nchar(' ', left), str);
	return (str);
}
