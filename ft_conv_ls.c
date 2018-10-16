/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:56:11 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/16 16:26:52 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_conv_ls(va_list ap, t_spec *spec, t_data *data)
{
	wchar_t *ws;
	char	*ret;

	// ?? spec->flags[0] += 0;
	ws = va_arg(ap, wchar_t*);
	while (*ws)
	{
		if ((ret = ft_realloc_free(ret, ft_wchar_to_char(*ws))) == NULL)
			return (NULL);
		ws++;
	}
	/* Precision pour wchar ??? */
	return (ft_width(ret, ft_strlen(ret), spec));
}
