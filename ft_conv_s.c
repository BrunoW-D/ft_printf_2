/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:57:49 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/08 18:57:51 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_conv_s(va_list ap, t_flags *flags, t_data *data)
{
	char	*str;

	if (flags->modifier[0] == 'l')
		return (ft_print_ls(ap, flags));
	else
		str = va_arg(ap, char*);
	if (str == NULL)
	{
		if ((str = ft_strdup("(null)")) == NULL)
			return (NULL);
	}
	if (flags->options[4] > 0)
	{
		if ((str = ft_strsub(str, 0, flags->options[4])) == NULL)
			return (NULL);
	}
	str = ft_width(ft_strdup(str), ft_strlen(str), flags);
	return (str);
}
