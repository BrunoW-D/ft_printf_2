/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:57:08 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/08 18:57:09 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

unsigned long long	ft_check_mod(va_list ap, t_flags *flags)
{
	unsigned long long	o;

	if (flags->modifier[0] == flags->modifier[1] && flags->modifier[1] == 'l')
		o = va_arg(ap, unsigned long long);
	else if (flags->modifier[0] == 'l')
		o = va_arg(ap, unsigned long);
	else if (flags->modifier[0] == 'j')
		o = va_arg(ap, uintmax_t);
	else if (flags->modifier[0] == flags->modifier[1] && flags->modifier[1] == 'h')
		o = (unsigned char)va_arg(ap, int);
	else if (flags->modifier[0] == 'h')
		o = (unsigned short)va_arg(ap, unsigned int);
	else if (flags->modifier[0] == 'z')
		o = va_arg(ap, size_t);
	else
		o = va_arg(ap, unsigned int);
	return (o);
}

char    			*ft_conv_o(va_list ap, t_flags *flags, t_data *data)
{
	unsigned long long	o;
	char            	*ret;

	o = ft_check_mod(ap, flags);
	if (o == 0 && flags->options[4] == -1)
	{
		if ((ret = ft_strdup("")) == NULL)
			return (NULL);
	}
	else if ((ret = ft_base(o, 8)) == NULL)
		return (NULL);
	data->arg_len = ft_strlen(ret);
	if (flags->options[4] > len)
	{
		ret = ft_realloc_free(ft_nchar('0', flags->options[4] - data->arg_len), ret);
		if (ret == NULL)
			return (NULL);
	}
	if (flags->options[0] && ret[0] != '0')
		if ((ret = ft_realloc_free(ft_strdup("0"), ret)) == NULL)
			return (NULL);
	return (ft_width(ret, ft_strlen(ret), flags));
}
