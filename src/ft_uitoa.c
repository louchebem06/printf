/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:30:16 by bledda            #+#    #+#             */
/*   Updated: 2021/06/05 15:39:18 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int	nb_char(unsigned int n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char			*itoa;
	unsigned int	i;

	i = nb_char(n);
	itoa = ft_calloc(sizeof(char), i + 1);
	if (itoa == 0)
		return (0);
	while (i > 0)
	{
		i--;
		itoa[i] = n % 10 + 48;
		n /= 10;
	}
	return (itoa);
}
