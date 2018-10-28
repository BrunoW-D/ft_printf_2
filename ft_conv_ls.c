/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:56:11 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/28 18:46:01 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_wstr_to_str(wchar_t *ws)
{
	char	*str;
	char	*wc;

	if ((str = ft_strnew(0)) == NULL)
		return (NULL);
	while (*ws)
	{
		if ((wc = ft_wchar_to_char(*ws)) == NULL)
		{
			free(str);
			return (NULL);
		}
		if ((str = ft_realloc_free(str, wc)) == NULL)
			return (NULL);
		ws++;
	}
	return (str);
}

char	*ft_wstr_to_str_prec(wchar_t *ws, int prec)
{
	char	*str;
	char	*wc;

	if ((str = ft_strnew(0)) == NULL)
		return (NULL);
	while (*ws && prec)
	{
		if ((wc = ft_wchar_to_char(*ws)) == NULL)
		{
			free(str);
			return (NULL);
		}
		if ((str = ft_realloc_free(str, wc)) == NULL)
			return (NULL);
		ws++;
		prec--;
	}
	return (str);
}

int		ft_wchar_len(wchar_t wc)
{
	if (wc < 0)
		return (0);
	if (wc <= 0x7f)
		return (1);
	else if (wc <= 0x7ff)
		return (2);
	else if (wc <= 0xffff)
		return (3);
	else if (wc <= 0x10ffff)
		return (4);
	return (0);
}

int		ft_wstr_prec(wchar_t *ws, int prec)
{
	int ws_prec;
	int	wc_len;

	ws_prec = 0;
	wc_len = 0;
	while (*ws)
	{
		if ((wc_len = ft_wchar_len(*ws)) == 0)
			return (-1);
		if (ws_prec + wc_len > prec)
			return (ws_prec);
		ws_prec += wc_len;
	}
	return (ws_prec);
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
		if ((spec->prec = ft_wstr_prec(ws, spec->prec)) == -1)
			return (NULL);
		if ((ret = ft_wstr_to_str_prec(ws, spec->prec)) == NULL)
			return (NULL);
	}
	else
	{
		if ((ret = ft_wstr_to_str(ws)) == NULL)
			return (NULL);
	}
	return (ft_width(ret, ft_strlen(ret), spec, data));
}
