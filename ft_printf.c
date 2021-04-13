/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:01:47 by bledda            #+#    #+#             */
/*   Updated: 2021/04/14 01:18:47 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//cspdiuxX%
//flags -0.*
/*
	* Remplace une data
	. peut avoir une data avant ou apres
		DATA AVANT 10. Place 10 espace
		DATA APRES .5 Affiche que les 5 premier char ou jusqu'a '\0'
		if -10. Les espace seront placer apres le texte
	0 Ne fonctionne que pour type diuxX
*/
int ft_printf(const char *input, ...)
{
	char *str;
	//unsigned long long decimal;
	char *flags;
	size_t f;
	int i;
	int start;
	int end;
	unsigned int cmp;
	va_list		args;

	i = 0;
	cmp = 0;
	f = 0;
	start = -1;
	end = -1;
	flags = ft_calloc(sizeof(char), ft_strlen(input));
	va_start(args, input);
	while (input[i] != 0)
	{
		if (input[i] == '%')
		{
			i++;
			ft_memset(flags, 0, ft_strlen(flags));
			while (ft_isconvert(input[i]))
				flags[f++] = input[i++];
			f = 0;

			if (input[i] == 's')
			{
				/*SI YA DES FLAGS*/
				if (ft_strlen(flags) > 0)
				{
					if (ft_strchr(flags, '*') != 0)
					{
						start = va_arg(args, int);
						flags = ft_strreplace(flags, '*', ft_itoa(start));
					}
					if (ft_strchr(flags, '*') != 0)
					{
						end = va_arg(args, int);
						flags = ft_strreplace(flags, '*', ft_itoa(end));
					}
					str = va_arg(args, char *);

					/*. peut avoir une data avant ou apres
					DATA AVANT 10. Place 10 espace
					DATA APRES .5 Affiche que les 5 premier char ou jusqu'a '\0'
					if -10. Les espace seront placer apres le texte*/

					/*SI YA PAS DE . donc selement une etoile qui a etait Remplacer precedament*/
					if (ft_strchr(flags, '.') == 0)
					{
						if (ft_strchr(flags, '-') != 0)
						{
							start = ft_strchrintab(flags, '-', 's');
							ft_putstr_fd(str, 1);
							ft_before_data(start, ft_strlen(str), ' ', &cmp);
							cmp += ft_strlen(str);
						}
						else
						{
							start = ft_atoi(flags);
							ft_before_data(start, ft_strlen(str), ' ', &cmp);
							cmp += ft_strlen(str);
							ft_putstr_fd(str, 1);
						}
					}
					else
					{
						end = ft_strchrintab(flags, '.', 'b');
						if (ft_strchr(flags, '-') != 0)
						{
							/*SI YA UN - AU DEBUT*/
							start = ft_strchrintab(flags, '-', '.');
							if (start != -1)
							{
								ft_putnstr(str, end);
								if (end != -1)
									ft_before_data(start, end, ' ', &cmp);
								else
									ft_before_data(start, ft_strlen(str), ' ', &cmp);
								if (ft_strlen(str) > (size_t)end)
									cmp += end;
								else
									cmp += ft_strlen(str);
							}
						}
						else
						{
							/*SI YA PAS DE -*/
							start = ft_strchrintab(flags, 'a', '.');
							if (start != -1)
							{
								if (end != -1)
									ft_before_data(start, end, ' ', &cmp);
								else if (end == -1 && start != -1)
									ft_before_data(start, 0, ' ', &cmp);
								else
									ft_before_data(start, ft_strlen(str), ' ', &cmp);
							}
							if (end != -1)
							{
								if (ft_strlen(str) > (size_t)end)
									cmp += end;
								else
									cmp += ft_strlen(str);
							}
							ft_putnstr(str, end);
						}
					}
					start = -1;
					end = -1;
				}
				else
				{
					str = va_arg(args, char *);
					cmp += ft_strlen(str);
					ft_putstr_fd(str, 1);
				}
			}
/*
			else if (input[i] == 'c' || input[i] == '%')
			{
				if (!ft_strncmp(flags, "*", 1))
				{
					start = va_arg(args, int);
					if (input[i] != '%')
						decimal = va_arg(args, int);
					str = ft_calloc(sizeof(char), 2);
					str = ft_memset(str, decimal, 1);
					ft_before_data(start, str, ' ', &cmp);
				}
				else
					decimal = va_arg(args, int);
				if (input[i] != '%')
					ft_putchar_fd(decimal, 1);
				else
					ft_putchar_fd('%', 1);
				cmp++;
			}

			else if (input[i] == 'd' || input[i] == 'i')
			{
				if (!ft_strncmp(flags, "0*", 2) || !ft_strncmp(flags, "*", 1))
				{
					start = va_arg(args, int);
					decimal = va_arg(args, int);
					if (!ft_strncmp(flags, "0*", 2))
						ft_before_data(start, ft_itoa(decimal), '0', &cmp);
					else
						ft_before_data(start, ft_itoa(decimal), ' ', &cmp);
				}
				else
					decimal = va_arg(args, int);
				ft_putstr_fd(ft_itoa(decimal), 1);
				cmp += ft_strlen(ft_itoa(decimal));
			}

			else if (input[i] == 'u')
			{
				if (!ft_strncmp(flags, "0*", 2) || !ft_strncmp(flags, "*", 1))
				{
					start = va_arg(args, int);
					decimal = va_arg(args, unsigned int);
					if (!ft_strncmp(flags, "0*", 2))
						ft_before_data(start, ft_itoa(decimal), '0', &cmp);
					else
						ft_before_data(start, ft_itoa(decimal), ' ', &cmp);
				}
				else
					decimal = va_arg(args, unsigned int);
				ft_putstr_fd(ft_itoa(decimal), 1);
				cmp += ft_strlen(ft_itoa(decimal));
			}

			else if (input[i] == 'x' || input[i] == 'X')
			{
				if (!ft_strncmp(flags, "0*", 2) || !ft_strncmp(flags, "*", 1))
				{
					start = va_arg(args, int);
					decimal = va_arg(args, unsigned int);
					if (!ft_strncmp(flags, "0*", 2))
						ft_before_data(start, ft_itoa(decimal), '0', &cmp);
					else
						ft_before_data(start, ft_itoa(decimal), ' ', &cmp);
				}
				else
					decimal = va_arg(args, unsigned int);
				if (input[i] == 'x')
					ft_putstr_fd(ft_strtolower(ft_itoh(decimal)), 1);
				else
					ft_putstr_fd(ft_strtoupper(ft_itoh(decimal)), 1);
				cmp += ft_strlen(ft_itoh(decimal));
			}

			else if (input[i] == 'p')
			{
				if (!ft_strncmp(flags, "*", 1))
				{
					start = va_arg(args, int);
					decimal = va_arg(args, unsigned long long);
					start -= 2;
					if (decimal != 0)
						start -= 2;
					ft_before_data(start, ft_itoa(decimal), ' ', &cmp);
				}
				else
					decimal = va_arg(args, unsigned long long);
				ft_putstr_fd("0x", 1);
				cmp += 2;
				if (decimal == 0)
				{
					ft_putchar_fd('0', 1);
					cmp++;
				}
				else
				{
					ft_putstr_fd(ft_strtolower(ft_itoh(decimal)), 1);
					cmp += ft_strlen(ft_itoh(decimal));
				}
			}*/

		}
		else
		{
			ft_putchar_fd(input[i], 1);
			cmp++;
		}
		i++;
	}
	free(flags);
	va_end(args);
	return (cmp);
}