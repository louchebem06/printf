/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 21:08:31 by bledda            #+#    #+#             */
/*   Updated: 2021/04/13 12:34:14 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char *pointer;

	pointer = 0;
	printf("%0*d\n", 11, 150);
	ft_printf("%0*d\n", 11, 150);
	printf("%*d\n", 11, 150);
	ft_printf("%*d\n", 11, 150);
	printf("%*i\n", 10, 12);
	ft_printf("%*i\n", 10, 12);
	printf("%*u\n", 10, 15);
	ft_printf("%*u\n", 10, 15);
	printf("%*x\n", 10, 'A');
	ft_printf("%*x\n", 10, 'A');
	printf("%*X\n", 10, 'b');
	ft_printf("%*X\n", 10, 'b');
	printf("%s\n", "😘");
	ft_printf("%s\n", "😘");
	printf("%*s\n", 10, "😘");
	ft_printf("%*s\n", 10, "😘");
	printf("%*p\n", 30, &pointer);
	ft_printf("%*p\n", 30, &pointer);
	printf("%*p\n", 10, &pointer);
	ft_printf("%*p\n", 10, &pointer);
	printf("%*p\n", 25, pointer);
	ft_printf("%*p\n", 25, pointer);
	printf("%p\n", pointer);
	ft_printf("%p\n", pointer);
	printf("%*c\n", 10, 'S');
	ft_printf("%*c\n", 10, 'S');
	printf("%*%\n", 10);
	ft_printf("%*%\n", 10);
	printf("%*s\n", 20, "Ouais ouais oauis");
	ft_printf("%*s\n", 20, "Ouais ouais oauis");
	printf("%*s\n", 10, "Ouais ouais oauis");
	ft_printf("%*s\n", 10, "Ouais ouais oauis");
	printf("%s\n", "Ouais ouais oauis");
	ft_printf("%s\n", "Ouais ouais oauis");
	return (0);
}
