/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:01:58 by bledda            #+#    #+#             */
/*   Updated: 2021/04/07 22:58:24 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_itoh(unsigned int nb)
{
	char	itoh[100];
	int i;
	unsigned int save_nb;
	char *r;

	i = 0;
	while (nb != 0)
	{
		save_nb = nb % 16;
		if (save_nb < 10)
		{
			itoh[i] = save_nb + 48;
			i++;
		}
		else
		{
			itoh[i] = save_nb + 55;
			i++;
		}
		nb /= 16;
	}
	itoh[i] = 0;
	i = ft_strlen(itoh);
	r = ft_calloc(sizeof(char), i + 1);
	if (r == 0)
		return (0);
	ft_strlcpy(r, itoh, i + 1);
	ft_strrev(r);
	return (r);
}
