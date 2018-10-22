/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_lc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:55:15 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/22 19:20:30 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_conv_lc(va_list ap, t_spec *spec, t_data *data)
{
	char	*ret;
	wchar_t	wc;

	wc = va_arg(ap, wchar_t);
	if (!wc)
		return (ft_width(ft_strdup(""), 1, spec, data));
	else if ((ret = ft_wchar_to_char(wc)) == NULL)
		return (NULL);
	return (ft_width(ret, ft_strlen(ret), spec, data));
}
