/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:57:23 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/17 17:05:58 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_conv_p(va_list ap, t_spec *spec, t_data *data)
{
	void	*p;
	char	*ret;

	spec->flags[0] = 0;
	p = va_arg(ap, void*);
	if ((ret = ft_base((long long)p, 16)) == NULL)
		return (NULL);
	if ((ret = ft_realloc_free(ft_strdup("0x"), ret)) == NULL)
		return (NULL);
	return (ft_width(ret, ft_strlen(ret), spec, data));
}
