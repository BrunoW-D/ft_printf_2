/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:02:38 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/28 17:09:22 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_realloc_free(char *str1, char *str2)
{
	char	*tmp;
	char	*ret;

	if (!str1 && !str2)
		return (NULL);
	if (!str1 && str2)
		return (str2);
	if (!str2)
		return (str1);
	tmp = ft_strdup(str1);
	free(str1);
	str1 = NULL;
	if ((ret = ft_strnew(ft_strlen(tmp) + ft_strlen(str2))) == NULL)
		return (NULL);
	ret = ft_strcpy(ret, tmp);
	ret = ft_strcat(ret, str2);
	free(tmp);
	tmp = NULL;
	free(str2);
	str2 = NULL;
	return (ret);
}
