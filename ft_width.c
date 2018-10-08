/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:34:24 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/08 17:34:41 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_width(char *str, int len, t_flags *flags)
{
	int width;
	int	left;

	width = flags->options[3];
	left = width - len;
	if (left > 0)
	{
		if (flags->options[1] == 2)
		{
			if (flags->options[4] == 0)
			{
				if (!(str = ft_realloc_free(ft_nchar('0', left), str)))
					return (NULL);
			}
			else
				flags->options[1] = 0;
		}
		if (flags->options[1] == 1)
		{
			if (!(str = ft_realloc_free(str, ft_nchar(' ', left))))
				return (NULL);
		}
		if (flags->options[1] == 0)
		{
			if (!(str = ft_realloc_free(ft_nchar(' ', left), str)))
				return (NULL);
		}
	}
	return (str);
}
