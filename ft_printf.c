/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:21:42 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/17 16:14:25 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_data	*init_data(t_data *data)
{
	int		i;
	t_spec	*spec;

	if ((data = (t_data*)malloc(sizeof(t_data))) == NULL)
		return (NULL);
	if ((spec = (t_spec*)malloc(sizeof(t_spec))) == NULL)
		return (NULL);
	data->i = 0;
	i = 0;
	while (i < 5)
	{
		spec->flags[i] = 0;
		i++;
	}
	spec->width = 0;
	spec->prec = 0;
	spec->mod[0] = 0;
	spec->mod[1] = 0;
	data->spec = spec;
	data->len = 0;
	ft_bzero(data->buff, BUFF_SIZE);
	data->arg_len = 0;
	return (data);
}

t_data	*reset_data(t_data *data)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		data->spec->flags[i] = 0;
		i++;
	}
	data->spec->width = 0;
	data->spec->prec = 0;
	data->spec->mod[0] = 0;
	data->spec->mod[1] = 0;
	data->arg_len = 0;
	return (data);
}

char	*ft_buff_cat(char *str, t_data *data, int i)
{
	if (!(str = ft_realloccat(str, data->buff, data->len, i)))
		return (NULL);
	ft_bzero(data->buff, BUFF_SIZE);
	data->len += i;
	return (str);
}

char	*ft_process(const char *f, va_list ap, t_data *data)
{
	int		i;
	char	*arg;
	char	*str;

	i = 0;
	arg = NULL;
	while (f[data->i])
	{
		if (i == BUFF_SIZE)
		{
			if ((str = ft_buff_cat(str, data, i)) == NULL)
			   return (NULL);
			i = 0;
		}
		if (f[data->i] == '%')
		{
			if ((str = ft_buff_cat(str, data, i)) == NULL)
				return (NULL);
			i = 0;
			arg = ft_get_arg(f, ap, data);
			if (!(str = ft_realloccat(str, arg, data->len, data->arg_len)))
				return (NULL);
			data->len += data->arg_len;
			data = reset_data(data);
		}
		else
			data->buff[i++] = f[(data->i)++];
	}
	return (str = ft_buff_cat(str, data, i));
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	char 	*str;
	t_data	*data;
	int		len;

	len = 0;
	if (format == NULL)
		return (0);
	if ((data = init_data(data)) == NULL)
		return (0);
	va_start(ap, format);
	str = ft_process(format, ap, data);
	va_end(ap);
	if (str == NULL || data->len == 0)
		return (0);
	write(1, str, data->len);
	len = data->len;
	free(str);
	str = NULL;
	free(data->spec);
	free(data);
	data = NULL;
	return (len);
}
