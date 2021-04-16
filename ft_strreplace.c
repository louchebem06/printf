/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:41:29 by bledda            #+#    #+#             */
/*   Updated: 2021/04/15 22:11:30 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strreplace(char *mainstr, char charset, char *replace)
{
	char	*str;
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	if (ft_strchr(mainstr, (int)charset) == 0)
		return (mainstr);
	str = ft_calloc(sizeof(char), ft_strlen(mainstr) + ft_strlen(replace) + 2);
	while (mainstr[i] != charset)
	{
		str[i] = mainstr[i];
		i++;
	}
	tmp = ft_strjoin(str, replace);
	j = ft_strlen(tmp);
	i++;
	while (mainstr[i] != 0)
	{
		tmp[j] = mainstr[i];
		i++;
		j++;
	}
	free(str);
	free(mainstr);
	free(replace);
	return (tmp);
}
