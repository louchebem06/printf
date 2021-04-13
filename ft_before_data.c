/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_before_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:20:56 by bledda            #+#    #+#             */
/*   Updated: 2021/04/14 01:07:35 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_before_data(int start, int size_str, char charset, unsigned int *cmp)
{
	char	*tmp;

	if (start >= 0)
	{
		tmp = ft_calloc(sizeof(char), start + 1);
		start -= size_str;
		if (start > 0)
		{
			tmp = ft_memset(tmp, charset, start);
			ft_putstr_fd(tmp, 1);
			*cmp += start;
		}
		free(tmp);
		tmp = 0;
	}
}
