/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_before_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:20:56 by bledda            #+#    #+#             */
/*   Updated: 2021/04/13 15:42:28 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_before_data(int start, char *str, char charset, unsigned int *cmp)
{
	char	*tmp;

	if (start >= 0)
	{
		tmp = ft_calloc(sizeof(char), start + 1);
		start -= ft_strlen(str);
		if (start > 0)
		{
			tmp = ft_memset(tmp, charset, start);
			ft_putstr_fd(tmp, 1);
		}
		free(tmp);
		tmp = 0;
	}
	*cmp += start;
}
