/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:41:29 by bledda            #+#    #+#             */
/*   Updated: 2021/04/20 16:24:55 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strreplace(char *mstr, char charset, char *rep)
{
	char	*str;
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	if (ft_strchr(mstr, (int)charset) == 0)
		return (mstr);
	if (rep[0] == 0)
		str = ft_calloc(sizeof(char), ft_strlen(mstr) + 2);
	else
		str = ft_calloc(sizeof(char), ft_strlen(mstr) + ft_strlen(rep) + 2);
	while (mstr[i] != charset)
	{
		str[i] = mstr[i];
		i++;
	}
	tmp = ft_strjoin(str, rep);
	j = ft_strlen(tmp);
	i++;
	while (mstr[i] != 0)
	{
		tmp[j] = mstr[i];
		i++;
		j++;
	}
	free(str);
	free(mstr);
	free(rep);
	return (tmp);
}
