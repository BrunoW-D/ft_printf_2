/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:56:11 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/19 19:56:13 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_conv_ls(va_list ap, t_spec *spec, t_data *data)
{
	wchar_t *ws;
	char	*ret;
	int		i;

	// ?? spec->flags[0] += 0;
	ws = va_arg(ap, wchar_t*);
	if (ws == NULL)
	{
		if ((ret = ft_strdup("(null)")) == NULL)
			return (NULL);
		data->arg_len = 6;
		return (ret);
	}
	if (spec->prec >= 0)
	{
		//ws = (wchar_t*)(ws >> (8 * (ft_strlen((char*)ws) - spec->prec)));
		//if ((ws = ft_strsub(ws, 0, spec->prec)) == NULL)
		//	return (NULL);
	}
	while (*ws)
	{
		if ((ret = ft_realloc_free(ret, ft_wchar_to_char(*ws))) == NULL)
			return (NULL);
		ws++;
	}
	if (spec->prec >= 0)
	{
		if ((ret = ft_strsub(ret, 0, spec->prec)) == NULL)
			return (NULL);
	}
	return (ft_width(ret, ft_strlen(ret), spec, data));
}
