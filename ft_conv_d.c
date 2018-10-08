/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:54:52 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/08 18:54:54 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

long long	ft_check_mod(va_list ap, t_flags *flags)
{
	long long	n;

	if (flags->modifier[0] == flags->modifier[1] && flags->modifier[1] == 'l')
		n = va_arg(ap, long long);
	else if (flags->modifier[0] == 'l')
		n = va_arg(ap, long);
	else if (flags->modifier[0] == 'j')
		n = va_arg(ap, intmax_t);
	else if (flags->modifier[0] == 'z')
		n = va_arg(ap, ssize_t);
	else if (flags->modifier[0] == flags->modifier[1] && flags->modifier[1] == 'h')
		n = (signed char)va_arg(ap, int);
	else if (flags->modifier[0] == 'h')
		n = (short)va_arg(ap, int);
	else
		n = va_arg(ap, int);
	return (n);
}

char		*ft_check_precision(long long n, t_flags *flags, char *ret, t_data *data)
{
	if (n == 0 && flags->options[4] == -1)
	{
		if ((ret = ft_strdup("")) == NULL)
			return (NULL);
	}
	else if ((ret = new_itoa(n)) == NULL)
		return (NULL);
	data->arg_len = ft_strlen(ret);
	if (n < 0)
		(data->arg_len)--;
	if (flags->options[4] > data->arg_len)
	{
		ret = ft_realloc_free(ft_nchar('0', flags->options[4] - data->arg_len), ret);
		if (ret == NULL)
			return (NULL);
	}
	data->arg_len = ft_strlen(ret);
	return (ret);
}

char		*ft_check_flags(long long n, t_flags *flags, char *ret, t_data *data)
{
	if (flags->options[2] == 1 && n >= 0)
	{
		if (flags->options[1] == 2)
		{
			if ((ret = ft_width(ret, data->arg_len + 1, flags)) == NULL)
				return (NULL);
		}
		if ((ret = ft_realloc_free(ft_strdup("+"), ret)) == NULL)
			return (NULL);
		if (flags->options[1] != 2)
		{
			if ((ret = ft_width(ret, data->arg_len + 1, flags)) == NULL)
				return (NULL);
		}
	}
	else if (flags->options[2] == 2 && n >= 0)
	{
		if ((ret = ft_realloc_free(ft_strdup(" "), ret)) == NULL)
			return (NULL);
		if ((ret = ft_width(ret, data->arg_len + 1, flags)) == NULL)
			return (NULL);
	}
	else if ((ret = ft_width(ret, data->arg_len, flags)) == NULL)
		return (NULL);
	return (ret);
}

char		*ft_conv_d(va_list ap, t_flags *flags, t_data *data)
{
	long long	n;
	char		*ret;
	int			i;

	n = ft_check_mod(ap, flags);
	if (!(ret = ft_check_precision(n, flags, ret, data)))
		return (NULL);
	if (!(ret = ft_check_flags(n, flags, ret, data)))
		return (NULL);
	if (ret && ret[0] == '0' && n < 0)
	{
		i = 0;
		while (ret[i] == '0')
			i++;
		ret[i] = '0';
		ret[0] = '-';
	}
	return (ret);
}
