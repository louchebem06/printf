/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:01:47 by bledda            #+#    #+#             */
/*   Updated: 2021/04/08 00:22:25 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//cspdiuxX%
//flags -0.*
int ft_printf(const char *input, ...)
{
	char *str;
	char charset;
	int  decimal;
	unsigned int un_decimal;

	int i = 0;
	va_list		args;

	va_start(args, input);
	
	while (input[i] != 0)
	{
		if (input[i] == '%')
		{
			i++;
			if (input[i] == 's')
			{
				str = va_arg(args, char *);
				ft_putstr_fd(str, 1);
			}
			else if (input[i] == 'c')
			{
				charset = va_arg(args, int);
				ft_putchar_fd(charset, 1);
			}
			else if (input[i] == 'd' || input[i] == 'i')
			{
				decimal = va_arg(args, int);
				ft_putstr_fd(ft_itoa(decimal), 1);
			}
			else if (input[i] == 'u')
			{
				un_decimal = va_arg(args, unsigned int);
				ft_putstr_fd(ft_itoa(un_decimal), 1);
			}
			else if (input[i] == '%')
				ft_putchar_fd('%', 1);
			else if (input[i] == 'x')
			{
				un_decimal = va_arg(args, unsigned int);
				ft_putstr_fd(ft_strtolower(ft_itoh(un_decimal)), 1);
			}
			else if (input[i] == 'X')
			{
				un_decimal = va_arg(args, unsigned int);
				ft_putstr_fd(ft_strtoupper(ft_itoh(un_decimal)), 1);
			}
			else if (input[i] == 'p')
			{
				un_decimal = va_arg(args, unsigned int);
				ft_putstr_fd("0x7ffe", 1);
				ft_putstr_fd(ft_strtolower(ft_itoh(un_decimal)), 1);
			}
		}
		else
			ft_putchar_fd(input[i], 1);
		i++;
	}

	va_end(args);
	return (0);
}