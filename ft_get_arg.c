/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 18:48:29 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/19 17:07:17 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		is_format_type(const char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D'
			|| c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U'
			|| c == 'x' || c == 'X' || c == 'c' || c == 'C')
		return (1);
	else
		return (0);
}

int		get_num(const char *f, t_data *data)
{
	int n;

	n = 0;
	if (f[data->i] == '.')
	{
		(data->i)++;
		if (f[data->i] <= '0' || f[data->i] > '9')
		{
			(data->i)--;
			return (0);
		}
	}
	while (f[data->i] >= '0' && f[data->i] <= '9')
	{
		n *= 10;
		n += f[data->i] - 48;
		(data->i)++;
	}
	(data->i)--;
	return (n);
}

void	get_modifier(const char *f, t_data *data)
{
	if (data->spec->mod[0] == 'h' && f[data->i] == 'h')
		data->spec->mod[1] = 'h';
	else if (data->spec->mod[0] == 'l' && f[data->i] == 'l')
		data->spec->mod[1] = 'l';
	else if (f[data->i] > data->spec->mod[0])
	{
		data->spec->mod[0] = f[data->i];
		data->spec->mod[1] = 0;
	}
	else if (data->spec->mod[0] == 0)
		data->spec->mod[0] = f[data->i];
}

void	ft_get_spec(const char *f, t_data *data, int i)
{
	while (f[data->i] && f[data->i] != '%' && !is_format_type(f[data->i]))
	{
		if (f[data->i] == '#')
			data->spec->flags[0] = 1;
		else if (f[data->i] == '-')
			data->spec->flags[1] = 1;
		else if (f[data->i] == '+')
			data->spec->flags[2] = 1;
		else if (f[data->i] == ' ')
		{
			if (data->spec->flags[2] != 1)
				data->spec->flags[2] = 2;
		}
		else if (f[data->i] == '0')
		{
			if (data->spec->flags[1] != 1)
				data->spec->flags[1] = 2;
		}
		else if (f[data->i] >= '1' && f[data->i] <= '9')
			data->spec->width = get_num(f, data);
		else if (f[data->i] == '.')
			data->spec->prec = get_num(f, data);
		else if (f[data->i] == 'h' || f[data->i] == 'l'
				|| f[data->i] == 'j' || f[data->i] == 'z')
			get_modifier(f, data);
		else
			return ;
		(data->i)++;
	}
}

char	*ft_get_arg(const char *f, va_list ap, t_data *data)
{
	int		i;
	char	*str;

	str = NULL;
	(data->i)++;
	i = data->i;
	ft_get_spec(f, data, i);
	if (is_format_type(f[data->i]))
		return (ft_controller(f[(data->i)++], ap, data));
	else if (f[data->i] == '%')
	{
		if ((str = ft_width(ft_strdup("%"), 1, data->spec, data)) == NULL)
			return (NULL);
		(data->i)++;
		return (str);
	}
	else if (f[data->i])
	{
		if ((str = ft_strsub(f, data->i, 1)) == NULL)
			return (NULL);
		if ((str = ft_width(str, 1, data->spec, data)) == NULL)
			return (NULL);
		(data->i)++;
		data->arg_len = ft_strlen(str);
		return (str);
	}
	return (NULL);
}
