/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:27:30 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/08 17:27:49 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char		*ft_utoa(unsigned long long n)
{
	char				*str;
	unsigned long long	nb;
	int					len;

	if (n == 0)
		return (ft_strdup("0"));
	nb = n;
	len = 1;
	while (nb /= 10)
		len++;
	nb = n;
	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	while (len-- > 0 && nb)
	{
		str[len] = nb % 10 + 48;
		nb /= 10;
	}
	return (str);
}
