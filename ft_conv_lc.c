/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_lc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:55:15 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/08 18:55:17 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_conv_lc(va_list ap, t_flags *flags, t_data *data)
{
	char	*ret;
	wchar_t	wc;

	/*
	(flags->options[0]) += 0;
	*/
	wc = va_arg(ap, wchar_t);
	if ((ret = ft_wchar_to_char(wc)) == NULL)
		return (NULL);
	return (ft_width(ret, ft_strlen(ret), flags));
}
