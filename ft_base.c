/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:25:22 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/08 17:25:47 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static char	*ft_init_negative(int len, long long *nb)
{
	char	*nbr;

	if ((nbr = ft_strnew(len)) == NULL)
		return (NULL);
	nbr[0] = '-';
	*nb *= -1;
	return (nbr);
}

char		*ft_ubase(unsigned long long u, int base)
{
	char				*nbr;
	unsigned long long	nb;
	int					len;

	nb = u;
	len = 1;
	while (nb /= base)
		len++;
	nb = u;
	if ((nbr = ft_strnew(len)) == NULL)
		return (NULL);
	while (nb > 0)
	{
		nbr[--len] = nb % base < 10 ? nb % base + 48 : nb % base + 87;
		nb /= base;
	}
	return (nbr);
}

char		*ft_ibase(long long n, int base)
{
	char		*nbr;
	long long	nb;
	int 		len;

	nb = n;
	len = 1;
	while (nb /= base)
		len++;
	nb = n;
	if (nb < 0 && ((nbr = ft_init_negative(++len, &nb)) == NULL))
		return (NULL);
	if (nb > 0 && ((nbr = ft_strnew(len)) == NULL))
		return (NULL);
	while (nb > 0)
	{
		nbr[--len] = nb % base < 10 ? nb % base + 48 : nb % base + 87;
		nb /= base;
	}
	return (nbr);
}

char		*ft_base(long long n, int base)
{
	if (base < 1 || base > 35)
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	if (base == 10)
		return (ft_ibase(n, base));
	else
		return (ft_ubase((unsigned long long)n, base));
}
