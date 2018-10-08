/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:54:23 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/08 18:54:25 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_conv_c(va_list ap, t_flags *flags, t_data *data)
{
	char	*ret;
	char	c;

	if ((ret = ft_strnew(1)) == NULL)
		return (NULL);
	if (flags->modifier[0] == 'l')
		return (ft_print_lc(ap, flags));
	c = va_arg(ap, int);
	ret[0] = c;
	// data->arg_len = ???
	return (ft_width(ret, 1, flags));
}
