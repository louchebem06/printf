/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrintab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:01:17 by bledda            #+#    #+#             */
/*   Updated: 2021/04/15 21:08:21 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strchrintab(char *str, char a, char b)
{
	int	value;
	int	i;
	int	ok;
	int	symbole;

	ok = -1;
	value = 0;
	i = 0;
	symbole = 1;
	if (a != 'a')
	{
		while (str[i] != a)
			i++;
		i++;
	}
	while (str[i] != b && str[i] != 0)
	{
		ok = 1;
		if (str[i] == '-')
			symbole = -1;
		if (ft_isdigit(str[i]))
			value = (value * 10) + (str[i] - 48);
		i++;
	}
	if (ok == -1)
		return (-1);
	return (value * symbole);
}
