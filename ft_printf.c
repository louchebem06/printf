/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:01:47 by bledda            #+#    #+#             */
/*   Updated: 2021/04/12 19:00:59 by bledda           ###   ########.fr       */
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
	unsigned long long un_decimal;
	char flags[10];
	size_t f;
	int i;
	int start;
	char *tmp;
	va_list		args;

	i = 0;
	f = 0;
	tmp = 0;
	va_start(args, input);
	while (input[i] != 0)
	{
		if (input[i] == '%')
		{
			i++;
			ft_memset(flags, 0, ft_strlen(flags));
			while ((input[i] != 's'
				&& input[i] != 'c'
				&& input[i] != 'd'
				&& input[i] != 'i'
				&& input[i] != 'u'
				&& input[i] != '%'
				&& input[i] != 'x'
				&& input[i] != 'X'
				&& input[i] != 'p')
				&& input[i] != 0 && f != 10)
			{
				flags[f] = input[i];
				f++;
				i++;
			}
			f = 0;
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
				if (ft_strncmp(flags, "0*", 2) == 0)
				{
					start = va_arg(args, int);
					decimal = va_arg(args, int);
					if (start >= 0)
					{
						tmp = ft_calloc(sizeof(char), start + 1);
						tmp = ft_memset(tmp, '0', start - ft_strlen(ft_itoa(decimal)));
						if (ft_strlen(tmp) > ft_strlen(ft_itoa(decimal)))
							ft_putstr_fd(tmp, 1);
						free(tmp);
						tmp = 0;
					}
				}
				else
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
			else if (input[i] == 'x' || input[i] == 'X')
			{
				if (ft_strncmp(flags, "0*", 2) == 0)
				{
					start = va_arg(args, int);
					un_decimal = va_arg(args, unsigned int);
					if (start >= 0)
					{
						tmp = ft_calloc(sizeof(char), start + 1);
						tmp = ft_memset(tmp, '0', start - 1);
						if (ft_strlen(tmp) > ft_strlen(ft_itoa(un_decimal)))
							ft_putstr_fd(tmp, 1);
						free(tmp);
						tmp = 0;
					}
				}
				else
					un_decimal = va_arg(args, unsigned int);
				if (input[i] == 'x')
					ft_putstr_fd(ft_strtolower(ft_itoh(un_decimal)), 1);
				else
					ft_putstr_fd(ft_strtoupper(ft_itoh(un_decimal)), 1);
			}
			else if (input[i] == 'p')
			{
				un_decimal = va_arg(args, unsigned long long);
				ft_putstr_fd("0x", 1);
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