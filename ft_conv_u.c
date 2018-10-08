/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:58:05 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/08 18:58:11 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_conv_u(va_list ap, t_flags *flags, t_data *data)
{
	unsigned long long int	n;
	char					*ret;
	int						len;

	if (flags->modifier[0] == flags->modifier[1] && flags->modifier[1] == 'l')
		n = va_arg(ap, unsigned long long);
	else if (flags->modifier[0] == 'l')
		n = va_arg(ap, unsigned long);
	else if (flags->modifier[0] == 'j')
		n = va_arg(ap, uintmax_t);
	else if (flags->modifier[0] == flags->modifier[1] && flags->modifier[1] == 'h')
		n = (unsigned char)va_arg(ap, int);
	else if (flags->modifier[0] == 'h')
		n = (unsigned short)va_arg(ap, unsigned int);
	else if (flags->modifier[0] == 'z')
		n = va_arg(ap, size_t);
	else
		n = va_arg(ap, unsigned int);
	if ((ret = ft_utoa(n)) == NULL)
		return (NULL);
	len = ft_strlen(ret);
	if (flags->options[4] > len)
	{
		if ((ret = ft_realloc_free(ft_nchar('0', flags->options[4] - len), ret)) == NULL)
			return (NULL);
	}
	return (ft_width(ret, ft_strlen(ret), flags));
}
