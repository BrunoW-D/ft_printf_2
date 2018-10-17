/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 15:49:23 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/17 17:02:30 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static char	*(*g_p[14]) (va_list ap, t_spec *spec, t_data *data);
static char	*g_types = "sSpdDioOuUxXcC";

void	init_p(void)
{
	g_p[0] = ft_conv_s;
	g_p[1] = ft_conv_ls;
	g_p[2] = ft_conv_p;
	g_p[3] = ft_conv_d;
	g_p[4] = ft_conv_ld;
	g_p[5] = ft_conv_d;
	g_p[6] = ft_conv_o;
	g_p[7] = ft_conv_lo;
	g_p[8] = ft_conv_u;
	g_p[9] = ft_conv_lu;
	g_p[10] = ft_conv_x;
	g_p[11] = ft_conv_lx;
	g_p[12] = ft_conv_c;
	g_p[13] = ft_conv_lc;
}

char	*ft_controller(char c, va_list ap, t_data *data)
{
	int		i;
	char	*arg;
	int		len;

	init_p();
	i = 0;
	while (i <= 13)
	{
		if (c == g_types[i])
		{
			if ((arg = g_p[i](ap, data->spec, data)) == NULL)
				return (NULL);
		}
		i++;
	}
	return (arg);
}
