/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isconvert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:40:49 by bledda            #+#    #+#             */
/*   Updated: 2021/06/05 15:28:11 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_isconvert(char charset)
{
	if (charset != 's'
		&& charset != 'c'
		&& charset != 'd'
		&& charset != 'i'
		&& charset != 'u'
		&& charset != '%'
		&& charset != 'x'
		&& charset != 'X'
		&& charset != 'p'
		&& charset != 0)
		return (1);
	return (0);
}
