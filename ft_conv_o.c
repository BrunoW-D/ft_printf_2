/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:57:08 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/18 18:56:05 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

unsigned long long	ft_check_mod_o(va_list ap, t_spec *spec)
{
	unsigned long long	o;

	if (spec->mod[0] == spec->mod[1] && spec->mod[1] == 'l')
		o = va_arg(ap, unsigned long long);
	else if (spec->mod[0] == 'l')
		o = va_arg(ap, unsigned long);
	else if (spec->mod[0] == 'j')
		o = va_arg(ap, uintmax_t);
	else if (spec->mod[0] == spec->mod[1] && spec->mod[1] == 'h')
		o = (unsigned char)va_arg(ap, int);
	else if (spec->mod[0] == 'h')
		o = (unsigned short)va_arg(ap, unsigned int);
	else if (spec->mod[0] == 'z')
		o = va_arg(ap, size_t);
	else
		o = va_arg(ap, unsigned int);
	return (o);
}

char				*ft_conv_o(va_list ap, t_spec *spec, t_data *data)
{
	unsigned long long	o;
	char				*ret;

	o = ft_check_mod_o(ap, spec);
	if (o == 0 && spec->prec == 0)
	{
		if ((ret = ft_strdup("")) == NULL)
			return (NULL);
	}
	else if ((ret = ft_base(o, 8)) == NULL)
		return (NULL);
	data->arg_len = ft_strlen(ret);
	if (spec->prec > data->arg_len)
	{
		ret = ft_realloc_free(ft_nchar('0', spec->prec - data->arg_len), ret);
		if (ret == NULL)
			return (NULL);
	}
	if (spec->flags[0] && ret[0] != '0')
		if ((ret = ft_realloc_free(ft_strdup("0"), ret)) == NULL)
			return (NULL);
	return (ft_width(ret, ft_strlen(ret), spec, data));
}
