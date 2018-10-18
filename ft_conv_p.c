/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:57:23 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/18 19:44:46 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_conv_p(va_list ap, t_spec *spec, t_data *data)
{
	void	*p;
	char	*ret;
	int		len;

	spec->flags[0] = 0;
	p = va_arg(ap, void*);
	if (!p)
	{
		if ((ret = ft_strdup("")) == NULL)
			return (NULL);
	}
	else if ((ret = ft_base((long long)p, 16)) == NULL)
		return (NULL);
	if (spec->prec > spec->width)
	{
		len = ft_strlen(ret);
		if (spec->prec > len && !p)
		{
			if ((ret = ft_realloc_free(ret, ft_nchar('0', spec->prec - len))) == NULL)
				return (NULL);
		}	
		else
		{
			if ((ret = ft_strsub(ret, 0, spec->prec)) == NULL)
					return (NULL);
		}
	}
	ret = ft_width(ret, ft_strlen(ret), spec, data);
	if ((ret = ft_realloc_free(ft_strdup("0x"), ret)) == NULL)
		return (NULL);
	data->arg_len = ft_strlen(ret);
	return (ret);
}
