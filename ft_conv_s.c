/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:57:49 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/16 16:32:12 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_conv_s(va_list ap, t_spec *spec, t_data *data)
{
	char	*str;

	if (spec->mod[0] == 'l')
		return (ft_print_ls(ap, spec));
	else
		str = va_arg(ap, char*);
	if (str == NULL)
	{
		if ((str = ft_strdup("(null)")) == NULL)
			return (NULL);
	}
	if (spec->prec > 0)
	{
		if ((str = ft_strsub(str, 0, spec->prec)) == NULL)
			return (NULL);
	}
	str = ft_width(ft_strdup(str), ft_strlen(str), spec);
	return (str);
}
