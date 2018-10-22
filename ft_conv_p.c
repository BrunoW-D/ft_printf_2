/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:57:23 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/22 20:06:48 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static char	*ft_check_prec(void *p, t_spec *spec, char *ret)
{
	int	len;

	if (spec->prec > 0)
	{
		len = ft_strlen(ret);
		if (spec->prec > len)
		{
			if (!(ret = ft_realloc_free(ft_nchar('0', spec->prec - len), ret)))
				return (NULL);
		}
		else if (!p)
		{
			if ((ret = ft_strsub(ret, 0, spec->prec - 1)) == NULL)
				return (NULL);
		}
	}
	return (ret);
}

static char	*ft_check_flags(void *p, t_spec *spec, char *ret, t_data *data)
{
	if (spec->flags[1] == 2)
	{
		ret = ft_width(ret, ft_strlen(ret) + 2, spec, data);
		if ((ret = ft_realloc_free(ft_strdup("0x"), ret)) == NULL)
			return (NULL);
		data->arg_len = ft_strlen(ret);
	}
	else
	{
		if ((ret = ft_realloc_free(ft_strdup("0x"), ret)) == NULL)
			return (NULL);
		ret = ft_width(ret, ft_strlen(ret), spec, data);
	}
	return (ret);
}

char		*ft_conv_p(va_list ap, t_spec *spec, t_data *data)
{
	void	*p;
	char	*ret;

	p = va_arg(ap, void*);
	if (!p && spec->prec == 0)
	{
		if ((ret = ft_strdup("")) == NULL)
			return (NULL);
	}
	else if ((ret = ft_base((long long)p, 16)) == NULL)
		return (NULL);
	if ((ret = ft_check_prec(p, spec, ret)) == NULL)
		return (NULL);
	if ((ret = ft_check_flags(p, spec, ret, data)) == NULL)
		return (NULL);
	return (ret);
}
