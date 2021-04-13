/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:41:29 by bledda            #+#    #+#             */
/*   Updated: 2021/04/14 01:12:36 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strreplace(char *mainstr, char charset, char *replace)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	if (ft_strchr(mainstr, (int)charset) == 0)
		return (mainstr);
	str = ft_calloc(sizeof(char), ft_strlen(mainstr) + ft_strlen(replace) + 2);
	while (mainstr[i] != charset)
	{
		str[i] = mainstr[i];
		i++;
	}
	str = ft_strjoin(str, replace);
	j = ft_strlen(str);
	i++;
	while (mainstr[i] != 0)
	{
		str[j] = mainstr[i];
		i++;
		j++;
	}
	free(mainstr);
	free(replace);
	return (str);
}
