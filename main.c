/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:02:55 by bledda            #+#    #+#             */
/*   Updated: 2021/04/07 22:57:55 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	/*char str[] = "je suis une string";
	unsigned int plus = 500;
	int neg = -42;*/
	unsigned int coucou = 'j';
	unsigned int coucou2 = 'J';

	printf("%x %X", coucou, coucou2);
	printf("\n");
	ft_printf("%x %X", coucou, coucou2);
	printf("\n");
	return (0);
}