/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:21:42 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/08 15:44:29 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_data	*init_data(t_data *data)
{
	int		i;
	t_flags	*flags;

	if ((data = (t_data*)malloc(sizeof(t_data))) == NULL)
		return (NULL);
	if ((flags = (t_flags*)malloc(sizeof(t_flags))) == NULL)
		return (NULL);
	data->i = 0;
	i = 0;
	while (i < 5)
	{
		flags->options[i] = 0;
		i++;
	}
	flags->modifier[0] = 0;
	flags->modifier[1] = 0;
	data->flags = flags;
	data->len = 0;
	ft_bzero(data->buff, BUFF_SIZE);
	data->b_len = 0;
	data->arg_len = 0;
	return (data);
}

t_data	*reset_data(t_data *data)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		data->flags->options[i] = 0;
		i++;
	}
	data->flags->modifier[0] = 0;
	data->flags->modifier[1] = 0;
	data->arg_len = 0;
	return (data);
}

char	*ft_buff_cat(char *str, t_data *data)
{
	if (!(str = ft_realloccat(str, data->buff, data->len, data->b_len)))
		return (NULL);
	ft_bzero(data->buff, BUFF_SIZE);
	data->len += data->b_len;
	data->b_len = 0;
	return (str);
}

char	*ft_process(const char *f, va_list ap, t_data *data)
{
	int		i;
	char	*arg;

	i = 0;
	arg = NULL;
	while (f[data->i])
	{
		if (i == BUFF_SIZE)
			ft_buff_cat(str, data) ? i = 0 : return (NULL);
		if (f[data->i] == '%')
		{
			ft_buff_cat(str, data) ? i = 0 : return (NULL);
			arg = ft_get_arg(f, ap, data);
			if (!(str = ft_realloccat(str, arg, data->len, data->arg_len)))
				return (NULL);
			data->len += data->arg_len;
			data = reset_data(data);
		}
		else
		{
			data->buff[i++] = f[(data->i)++];
			data->b_len += 1;
		}
	}
	return (str = ft_realloccat(str, data->buff, data->len, data->b_len))
}

int		ft_printf(const char *fornat, ...)
{
	va_list ap;
	char 	*str;
	t_data	*data;

	if (format == NULL)
		return (0);
	data = init_data(data);
	va_start(ap, format);
	str = ft_process(t_data *data);
	va_end(ap);
	if (str == NULL || data->len == 0)
		return (0);
	write(1, str, data->len);
	free(str);
	str = NULL;
	free(data->flags);
	free(data);
	data = NULL;
	return (data->len);
}
