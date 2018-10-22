/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:58:05 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/22 20:08:13 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static char	*ft_check_mod(va_list ap, t_spec *spec, char *ret)
{
	unsigned long long int	n;

	if (spec->mod[0] == spec->mod[1] && spec->mod[1] == 'l')
		n = va_arg(ap, unsigned long long);
	else if (spec->mod[0] == 'l')
		n = va_arg(ap, unsigned long);
	else if (spec->mod[0] == 'j')
		n = va_arg(ap, uintmax_t);
	else if (spec->mod[0] == spec->mod[1] && spec->mod[1] == 'h')
		n = (unsigned char)va_arg(ap, int);
	else if (spec->mod[0] == 'h')
		n = (unsigned short)va_arg(ap, unsigned int);
	else if (spec->mod[0] == 'z')
		n = va_arg(ap, size_t);
	else
		n = va_arg(ap, unsigned int);
	if ((ret = ft_utoa(n)) == NULL)
		return (NULL);
	return (ret);
}

char		*ft_conv_u(va_list ap, t_spec *spec, t_data *data)
{
	char	*ret;
	int		len;

	if (ft_check_mod(ap, spec, ret) == NULL)
		return (NULL);
	if (spec->prec == 0)
	{
		free(ret);
		if ((ret = ft_strdup("")) == NULL)
			return (NULL);
	}
	len = ft_strlen(ret);
	if (spec->prec > len)
	{
		if (!(ret = ft_realloc_free(ft_nchar('0', spec->prec - len), ret)))
			return (NULL);
	}
	return (ft_width(ret, ft_strlen(ret), spec, data));
}
