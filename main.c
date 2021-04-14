/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 21:08:31 by bledda            #+#    #+#             */
/*   Updated: 2021/04/14 14:02:37 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//gcc *.c libft/*.c && ./a.out
int	main(void)
{
	int i;
	i = printf(" %.*s$", -2, NULL);
	printf("\n%d\n", i);
	i =  ft_printf(" %.*s$", -2, NULL);
	printf("\n%d\n", i);
	i = printf(" %-3.s$", NULL);
	printf("\n%d\n", i);
	i =  ft_printf(" %-3.s$", NULL);
	printf("\n%d\n", i);
	i = printf(" %-9.1s$", NULL);
	printf("\n%d\n", i);
	i =  ft_printf(" %-9.1s$", NULL);
	printf("\n%d\n", i);
	return (0);
}
