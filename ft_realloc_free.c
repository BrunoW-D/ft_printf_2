/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:02:38 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/08 17:02:49 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_realloc_free(char *str1, char *str2)
{
	char	*tmp;

	if (!str1 && !str2)
		return (NULL);
	if (!str1 && str2)
		return (str2);
	if (!str2)
		return (str1);
	tmp = ft_strdup(str1);
	if ((str1 = ft_strnew(ft_strlen(str1) + ft_strlen(str2))) == NULL)
		return (NULL);
	str1 = ft_strcpy(str1, tmp);
	str1 = ft_strcat(str1, str2);
	free(tmp);
	free(str2);
	tmp = NULL;
	str2 = NULL;
	return (str1);
}
