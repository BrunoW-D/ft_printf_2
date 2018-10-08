/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_lu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:56:28 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/08 18:56:29 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_conv_lu(va_list ap, t_flags *flags, t_data *data)
{
	flags->modifier[0] = 'l';
	return (ft_print_u(ap, flags, data));
}
