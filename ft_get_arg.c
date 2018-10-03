/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 18:48:29 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/03 19:19:09 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		is_type_flag(const char c)
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
		if (f[data->i] < '0' || f[data->i] > '9')
		{
			(data->i)--;
			return (-1);
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
	if (data->flags->modifier[0] == 'h' && f[data->i] == 'h')
		data->flags->modifier[1] = 'h';
	else if (data->flags->modifier[0] == 'l' && f[data->i] == 'l')
		data->flags->modifier[1] = 'l';
	else if (f[data->i] > data->flags->modifier[0])
	{
		data->flags->modifier[0] = f[data->i];
		data->flags->modifier[1] = 0;
	}
	else if (data->flags->modifier[0] == 0)
		data->flags->modifier[0] = f[data->i];
}

void	ft_get_flags(const char *f, t_data *data, int i)
{
	while (f[data->i] && f[data->i] != '%' && !is_type_flag(f[data->i]))
	{
		if (f[data->i] == '#')
			data->flags->options[0] = 1;
		if (f[data->i] == '-')
			data->flags->options[1] = 1;
		if (f[data->i] == '+')
			data->flags->options[2] = 1;
		if (f[data->i] == ' ' && !data->flags->options[2])
			data->flags->options[2] = 2;
		if (f[data->i] == '0' && !data->flags->options[1])
			data->flags->options[1] = 2;
		if (f[data->i] >= '1' && f[data->i] <= '9')
			data->flags->options[3] = get_num(f, data);
		if (f[data->i] == '.')
			data->flags->options[4] = get_num(f, data);
		if (f[data->i] == 'h' || f[data->i] == 'l'
				|| f[data->i] == 'j' || f[data->i] == 'z')
			get_modifier(f, data);
		(data->i)++;
	}
}

char	*ft_get_arg(const char *f, va_list ap, t_data *data)
{
	int	i;

	i = data->i;
	(data->i)++;
	ft_get_flags(f, data, i);
	if (f[data->i] == '%')
	{
		(data->i)++;
		return (ft_width(ft_strdup("%"), 1, data->flags));
	}
	else if (is_type_flag(format[data->i]))
		return (ft_print_controller(f[(data->i)++], ap, data));
	else
		return (NULL);
	(data->i)++;
	return (NULL);
}
