/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:43:00 by bledda            #+#    #+#             */
/*   Updated: 2021/06/05 05:50:15 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int	ft_iswhitespace(char c)
{
	if (c == ' '
		|| c == '\t'
		|| c == '\n'
		||c == '\v'
		|| c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}
