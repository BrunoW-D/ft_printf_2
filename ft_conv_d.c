/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:54:52 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/19 20:05:53 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

long long	ft_check_mod_d(va_list ap, t_spec *spec)
{
	long long	n;

	if (spec->mod[0] == spec->mod[1] && spec->mod[1] == 'l')
		n = va_arg(ap, long long);
	else if (spec->mod[0] == 'l')
		n = va_arg(ap, long);
	else if (spec->mod[0] == 'j')
		n = va_arg(ap, intmax_t);
	else if (spec->mod[0] == 'z')
		n = va_arg(ap, ssize_t);
	else if (spec->mod[0] == spec->mod[1] && spec->mod[1] == 'h')
		n = (signed char)va_arg(ap, int);
	else if (spec->mod[0] == 'h')
		n = (short)va_arg(ap, int);
	else
		n = va_arg(ap, int);
	return (n);
}

char		*ft_check_prec(long long n, t_spec *spec, char *ret, t_data *data)
{
	if (n == 0 && spec->prec == 0)
	{
		if ((ret = ft_strdup("")) == NULL)
			return (NULL);
	}
	else if ((ret = new_itoa(n)) == NULL)
		return (NULL);
	data->arg_len = ft_strlen(ret);
	if (n < 0)
		(data->arg_len)--;
	if (spec->prec > 0)
	{
		if (spec->prec > data->arg_len)
		{
			ret = ft_realloc_free(ft_nchar('0', spec->prec - data->arg_len), ret);
			if (ret == NULL)
				return (NULL);
		}
		else if (!n)
		{
			if ((ret = ft_strsub(ret, 0, spec->prec - 1)) == NULL)
				return (NULL);
		}
	}
	data->arg_len = ft_strlen(ret);
	return (ret);
}

char		*ft_check_flags(long long n, t_spec *spec, char *ret, t_data *data)
{
	if (spec->flags[2] == 1 && n >= 0)
	{
		if (spec->flags[1] == 2)
		{
			if ((ret = ft_width(ret, data->arg_len + 1, spec, data)) == NULL)
				return (NULL);
		}
		if ((ret = ft_realloc_free(ft_strdup("+"), ret)) == NULL)
			return (NULL);
		if (spec->flags[1] != 2)
		{
			if ((ret = ft_width(ret, data->arg_len + 1, spec, data)) == NULL)
				return (NULL);
		}
	}
	else if (spec->flags[2] == 2 && n >= 0)
	{
		if ((ret = ft_realloc_free(ft_strdup(" "), ret)) == NULL)
			return (NULL);
		if ((ret = ft_width(ret, data->arg_len + 1, spec, data)) == NULL)
			return (NULL);
	}
	else if ((ret = ft_width(ret, data->arg_len, spec, data)) == NULL)
		return (NULL);
	return (ret);
}

char		*ft_conv_d(va_list ap, t_spec *spec, t_data *data)
{
	long long	n;
	char		*ret;
	int			i;
	int			done;

	done = 0;
	n = ft_check_mod_d(ap, spec);
	if (!(ret = ft_check_prec(n, spec, ret, data)))
		return (NULL);
	if (n < 0)
	{
		if (spec->width > ft_strlen(ret) && spec->flags[1] == 2)
		{
			if (!(ret = ft_check_flags(n, spec, ret, data)))
				return (NULL);
			done = 1;
		}
		if (ret && ret[0] == '0')
		{
			i = 0;
			while (ret[i] == '0')
				i++;
			ret[i] = '0';
			ret[0] = '-';
		}
	}
	if (done == 0)
	{
		if (!(ret = ft_check_flags(n, spec, ret, data)))
			return (NULL);
	}
	return (ret);
}
