/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:34:24 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/22 17:14:04 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static char	*ft_prepend(char *str, int len, char c, int left)
{
	char	*filler;

	if ((filler = ft_nchar(c, left)) == NULL)
		return (NULL);
	if ((str = ft_realloccat(filler, str, left, len)) == NULL)
		return (NULL);
	return (str);
}

static char	*ft_append(char *str, int len, char c, int left)
{
	char	*filler;

	if ((filler = ft_nchar(c, left)) == NULL)
		return (NULL);
	if ((str = ft_realloccat(str, filler, len, left)) == NULL)
		return (NULL);
	return (str);
}

char		*ft_width(char *str, int len, t_spec *spec, t_data *data)
{
	int	left;

	left = spec->width - len;
	data->arg_len = len;
	if (left <= 0)
		return (str);
	if (spec->flags[1] == 2)
	{
		if (spec->prec >= 0 && (spec->conv == 'x' || spec->conv == 'd'
					|| spec->conv == 'o' || spec->conv == 'u'
					|| spec->conv == 'X' || spec->conv == 'O'
					|| spec->conv == 'p' || spec->conv == 'D'
					|| spec->conv == 'u'))
			spec->flags[1] = 0;
		else
			str = ft_prepend(str, len, '0', left);
	}
	if (spec->flags[1] == 1)
		str = ft_append(str, len, ' ', left);
	if (spec->flags[1] == 0)
		str = ft_prepend(str, len, ' ', left);
	data->arg_len = len + left;
	return (str);
}
