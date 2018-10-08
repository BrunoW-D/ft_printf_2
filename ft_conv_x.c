/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:58:36 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/08 18:58:38 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

unsigned long long	ft_check_mod(va_list ap, t_flags *flags)
{
	unsigned long long	x;

	if (flags->modifier[0] == flags->modifier[1] && flags->modifier[1] == 'l')
		x = va_arg(ap, unsigned long long);
	else if (flags->modifier[0] == 'l')
		x = va_arg(ap, unsigned long);
	else if (flags->modifier[0] == 'j')
		x = va_arg(ap, uintmax_t);
	else if (flags->modifier[0] == flags->modifier[1] && flags->modifier[1] == 'h')
		x = (unsigned char)va_arg(ap, int);
	else if (flags->modifier[0] == 'h')
		x = (unsigned short)va_arg(ap, unsigned int);
	else if (flags->modifier[0] == 'z')
		x = va_arg(ap, size_t);
	else
		x = va_arg(ap, unsigned int);
	return (x);
}

char	*ft_conv_x(va_list ap, t_flags *flags, t_data *data)
{
	unsigned long long	x;
	char				*ret;

	if (x == 0 && flags->options[4] == -1)
	{
		if ((ret = ft_strdup("")) == NULL)
			return (NULL);
	}
	else if ((ret = ft_base(x, 16)) == NULL)
		return (NULL);
	data->arg_len = ft_strlen(ret);
	if (flags->options[0] && ret[0] != '0' && ret[0] != '\0')
	{
		if (flags->options[1] == 2)
		{
			if ((ret = ft_width(ret, data->arg_len + 2, flags)) == NULL)
				return (NULL);
		}
		if ((ret = ft_realloc_free(ft_strdup("0x"), ret)) == NULL)
			return (NULL);
		if (flags->options[1] != 2)
			ret = ft_width(ret, data->arg_len + 2, flags);
	}
	else
		ret = ft_width(ret, data->arg_len, flags);
	return (ret);
}
