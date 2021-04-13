/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrintab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:01:17 by bledda            #+#    #+#             */
/*   Updated: 2021/04/13 18:27:53 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_strchrintab(char *str, char a, char b)
{
	int value;
	int i;

	value = 0;
	i = 0;
	if (a != 'a')
	{
		while (str[i] != a)
			i++;
		i++;
	}
	while (str[i] != b && str[i] != 0)
	{
		value = (value * 10) + (str[i] - 48);
		i++;
	}
	return (value);
}
