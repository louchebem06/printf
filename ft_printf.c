/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:01:47 by bledda            #+#    #+#             */
/*   Updated: 2021/04/07 22:58:17 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//cspdiuxX%
int ft_printf(const char *input, ...)
{
	char *str; // s, STRING
	char charset; // c, char
	int  decimal; // d, i, Decimal
	unsigned int un_decimal; // u, Unsigned Decimail
	unsigned int hexa; // x, Hexadecimal abcd
	unsigned int HEXA; // X, Hexadecimal ABCD
	//p, Pointer

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
				hexa = va_arg(args, unsigned int);
				ft_putstr_fd(ft_strtolower(ft_itoh(hexa)), 1);
			}
			else if (input[i] == 'X')
			{
				HEXA = va_arg(args, unsigned int);
				ft_putstr_fd(ft_strtoupper(ft_itoh(HEXA)), 1);
			}
		}
		else
			ft_putchar_fd(input[i], 1);
		i++;
	}

	va_end(args);
	return (0);
}