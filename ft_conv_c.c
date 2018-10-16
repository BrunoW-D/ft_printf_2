/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:54:23 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/16 16:18:36 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_conv_c(va_list ap, t_spec *spec, t_data *data)
{
	char	*ret;
	char	c;

	if ((ret = ft_strnew(1)) == NULL)
		return (NULL);
	if (spec->mod[0] == 'l')
		return (ft_print_lc(ap, flags));
	c = va_arg(ap, int);
	ret[0] = c;
	return (ft_width(ret, 1, flags));
}
