/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_lx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:56:44 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/08 18:56:47 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_conv_lx(va_list ap, t_flags *flags, t_data *data)
{
	char	*ret;

	if ((ret = ft_print_x(ap, flags, data)) == NULL)
		return (NULL);
	ret = ft_strupper(ret);
	if (flags->options[0] && ret && ret[1])
		ret[1] = 'X';
	return (ret);
}
