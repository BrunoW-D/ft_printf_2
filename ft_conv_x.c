/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:58:36 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/22 20:13:08 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static unsigned long long	ft_check_mod(va_list ap, t_spec *spec)
{
	unsigned long long	x;

	if (spec->mod[0] == spec->mod[1] && spec->mod[1] == 'l')
		x = va_arg(ap, unsigned long long);
	else if (spec->mod[0] == 'l')
		x = va_arg(ap, unsigned long);
	else if (spec->mod[0] == 'j')
		x = va_arg(ap, uintmax_t);
	else if (spec->mod[0] == spec->mod[1] && spec->mod[1] == 'h')
		x = (unsigned char)va_arg(ap, int);
	else if (spec->mod[0] == 'h')
		x = (unsigned short)va_arg(ap, unsigned int);
	else if (spec->mod[0] == 'z')
		x = va_arg(ap, size_t);
	else
		x = va_arg(ap, unsigned int);
	return (x);
}

static char					*ft_check_prec(unsigned long long x, t_spec *spec)
{
	char	*ret;
	int		len;

	if (x == 0 && spec->prec == 0)
	{
		if ((ret = ft_strdup("")) == NULL)
			return (NULL);
	}
	else if ((ret = ft_base(x, 16)) == NULL)
		return (NULL);
	len = ft_strlen(ret);
	if (spec->prec > 0)
	{
		if (spec->prec > len)
		{
			if (!(ret = ft_realloc_free(ft_nchar('0', spec->prec - len), ret)))
				return (NULL);
		}
		else if (!x)
		{
			if (spec->flags[0] == 1)
			{
				if ((ret = ft_strsub(ret, 0, spec->prec - 1)) == NULL)
					return (NULL);
			}
			else if ((ret = ft_strsub(ret, 0, spec->prec)) == NULL)
				return (NULL);
		}
	}
	return (ret);
}

char						*ft_conv_x(va_list ap, t_spec *spec, t_data *data)
{
	unsigned long long	x;
	char				*ret;
	int					len;

	x = ft_check_mod(ap, spec);
	if ((ret = ft_check_prec(x, spec)) == NULL)
		return (NULL);
	len = ft_strlen(ret);
	if (spec->flags[0] == 1 && x)
	{
		if (spec->prec == -1 && spec->flags[1] == 2)
		{
			if ((ret = ft_width(ret, len + 2, spec, data)) == NULL)
				return (NULL);
			if ((ret = ft_realloc_free(ft_strdup("0x"), ret)) == NULL)
				return (NULL);
		}
		else
		{
			if ((ret = ft_realloc_free(ft_strdup("0x"), ret)) == NULL)
				return (NULL);
			if ((ret = ft_width(ret, data->len + 2, spec, data)) == NULL)
				return (NULL);
		}
	}
	else
		ret = ft_width(ret, ft_strlen(ret), spec, data);
	return (ret);
}
