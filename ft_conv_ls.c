/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:56:11 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/22 19:03:36 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

wchar_t	*ft_wssub(wchar_t const *ws, unsigned int start, size_t len)
{
	wchar_t	*dst;
	size_t	i;

	if (ws)
	{
		i = 0;
		if ((dst = (wchar_t*)malloc(sizeof(wchar_t) * (len + 1))) == NULL)
			return (NULL);
		while (i < len)
		{
			dst[i] = ws[start + i];
			i++;
		}
		dst[i] = '\0';
		return (dst);
	}
	else
		return (NULL);
}

char	*ft_conv_ls(va_list ap, t_spec *spec, t_data *data)
{
	wchar_t *ws;
	char	*ret;

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
		if ((ws = ft_wssub(ws, 0, spec->prec)) == NULL)
			return (NULL);
	}
	while (*ws)
	{
		if ((ret = ft_realloc_free(ret, ft_wchar_to_char(*ws))) == NULL)
			return (NULL);
		ws++;
	}
	return (ft_width(ret, ft_strlen(ret), spec, data));
}
