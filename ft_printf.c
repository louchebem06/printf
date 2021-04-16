/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:01:47 by bledda            #+#    #+#             */
/*   Updated: 2021/04/17 00:26:33 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *input, ...)
{
	char *str;
	unsigned long long decimal;
	char *flags;
	size_t f;
	int i;
	unsigned int cmp;
	va_list		args;
	int flags_value[3];
	char *tmp;
	int neg;

	i = 0;
	cmp = 0;
	f = 0;
	neg = 0;
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
			ft_flagsjoin(flags_value, args, flags);
			//printf("\nResultat final  : %d %d %d\n", flags_value[0], flags_value[1], flags_value[2]);
			//break;
			if (input[i] == 'c' || input[i] == '%')
			{
				decimal = va_arg(args, int);
				if (flags_value[2] == -1)
				{
					if (input[i] != '%')
						ft_putchar_fd(decimal, 1);
					else
						ft_putchar_fd('%', 1);
				}
				else
				{
					if (flags_value[0] == 0)
					{
						if (input[i] != '%')
							ft_putchar_fd(decimal, 1);
						else
							ft_putchar_fd('%', 1);
						ft_before_data(flags_value[2], 1, ' ', &cmp);
					}
					else
					{	
						ft_before_data(flags_value[2], 1, ' ', &cmp);
						if (input[i] != '%')
							ft_putchar_fd(decimal, 1);
						else
							ft_putchar_fd('%', 1);
					}
				}
				cmp++;
			}

			else if (input[i] == 's')
			{
				str = va_arg(args, char *);
				if (str == 0)
						str = ft_strdup("(null)");
				if (flags_value[2] == -1 && flags_value[1] == -1)
				{
					ft_putstr_fd(str, 1);
					cmp += ft_strlen(str);
				}
				else if (flags_value[1] == -1)
				{
					if (flags_value[0] == 0)
					{
						ft_putstr_fd(str, 1);
						ft_before_data(flags_value[2], ft_strlen(str), ' ', &cmp);
					}
					else
					{
						ft_before_data(flags_value[2], ft_strlen(str), ' ', &cmp);
						ft_putstr_fd(str, 1);
					}
					cmp += ft_strlen(str);
				}
				else
				{
					if (ft_strlen(str) <= (size_t)flags_value[2])
						f = ft_strlen(str);
					else
						f = flags_value[2];
					if (flags_value[0] == 0)
					{
						ft_putnstr(str, f);
						ft_before_data(flags_value[1], f , ' ', &cmp);
					}
					else
					{
						ft_before_data(flags_value[1], f, ' ', &cmp);
						ft_putnstr(str, f);
					}
					cmp += f;
					f = 0;
				}
				if (ft_strncmp(str, "(null)", 6) == 0)
					free(str);
			}

			else if (input[i] == 'p')
			{
				decimal = va_arg(args, unsigned long long);
				str = ft_strtolower(ft_itoh(decimal));
				if (decimal == 0)
					tmp = ft_strjoin("0x0", "");
				else
					tmp = ft_strjoin("0x", str);
				free(str);
				str = ft_strdup(tmp);
				free(tmp);
				if (flags_value[2] == -1 && flags_value[1] == -1)
				{
					ft_putstr_fd(str, 1);
					cmp += ft_strlen(str);
				}
				else if (flags_value[1] == -1)
				{
					if (flags_value[0] == 0)
					{
						ft_putstr_fd(str, 1);
						ft_before_data(flags_value[2], ft_strlen(str), ' ', &cmp);
					}
					else
					{
						ft_before_data(flags_value[2], ft_strlen(str), ' ', &cmp);
						ft_putstr_fd(str, 1);
					}
					cmp += ft_strlen(str);
				}
				else
				{
					if (ft_strlen(str) <= (size_t)flags_value[2])
						f = ft_strlen(str);
					else
						f = flags_value[2];
					if (flags_value[0] == 0)
					{
						ft_putnstr(str, f);
						ft_before_data(flags_value[1], f, ' ', &cmp);
					}
					else
					{
						ft_before_data(flags_value[1], f, ' ', &cmp);
						ft_putnstr(str, f);
					}
					cmp += f;
					f = 0;
				}
				free(str);
			}

			else if (input[i] == 'd')
			{
				decimal = va_arg(args, int);
				if ((int)decimal < 0)
				{
					neg = 1;
					decimal *= -1;
				}
				str = ft_itoa(decimal);
				// Pas de Flags
				if (flags_value[2] == -1 && flags_value[1] == -1)
				{
					ft_putstr_fd(str, 1);
					cmp += ft_strlen(str);
				}
				else
				{
					if (neg == 1)
					{
						ft_putchar_fd('-', 1);
						cmp++;
						f++;
					}
					if (!(flags_value[1] == 0) || !(flags_value[2] == 0))
					{
						//Si ya un moin
						if (flags_value[0] == 0)
						{
							// 1 Param
							if (flags_value[1] == -1)
							{

							}
							else
							{
								// 2 Param
								// if str et plus grand que param 1 et 2 affiche str
								// if str et plus petit que param 2 ajouter zero avant
								// si le plus grand de param 2 ou str et plus petit que param 1
								//alors mettre de espace pour completer
								if ((int)ft_strlen(str) >= flags_value[1] && (int)ft_strlen(str) >= flags_value[2])
								{
									ft_putstr_fd(str, 1);
									f = ft_strlen(str);
								}
								else
								{
									if ((int)ft_strlen(str) < flags_value[2])
									{
										ft_before_data(flags_value[2], ft_strlen(str), '0', &cmp);
										ft_putstr_fd(str, 1);
										f = flags_value[2];
									}
									else
									{
										ft_putstr_fd(str, 1);
										f = ft_strlen(str);
									}
									if ((int)f < flags_value[1])
										ft_before_data(flags_value[1], f, ' ', &cmp);
									f--;
								}
							}
						}
						//Si ya un rien
						else if (flags_value[0] == 1)
						{
							// 1 Param
							if (flags_value[1] == -1)
							{

							}
							else
							{
								// 2 Param
								// if str et plus grand que param 1 et 2 affiche str
								// if str et plus petit que param 2 ajouter zero avant
								// si le plus grand de param 2 ou str et plus petit que param 1
								//alors mettre de espace pour completer
								if ((int)ft_strlen(str) >= flags_value[1] && (int)ft_strlen(str) >= flags_value[2])
								{
									ft_putstr_fd(str, 1);
									f = ft_strlen(str);
								}
								else
								{
									if ((int)ft_strlen(str) < flags_value[2])
									{
										ft_putstr_fd(str, 1);
										ft_before_data(flags_value[2], ft_strlen(str), '0', &cmp);
										f = flags_value[2];
									}
									else
									{
										ft_putstr_fd(str, 1);
										f = ft_strlen(str);
									}
									if ((int)f < flags_value[1])
										ft_before_data(flags_value[1], f + 1, ' ', &cmp);
									f--;
								}
							}	
						}
						//Si ya un zero
						else if (flags_value[0] == 2)
						{
							// 1 Param
							if (flags_value[1] == -1)
							{

							}
							else
							{
								// 2 Param
							}
						}
						cmp += f;
					}
				}
				f = 0;
				neg = 0;
				free(str);
			}

			/*else if (input[i] == 'd' || input[i] == 'i' || input[i] == 'u' || input[i] == 'x' || input[i] == 'X')
			{
				if (input[i] == 'd' || input[i] == 'i')
				{
					decimal = va_arg(args, int);
					if ((int)decimal < 0)
					{
						neg = 1;
						decimal *= -1;
					}
				}
				else if (input[i] == 'u')
				{
					decimal = va_arg(args, unsigned int);
					if ((unsigned int)decimal < 0)
					{
						neg = 1;
						decimal *= -1;
					}
				}
				else
					decimal = va_arg(args, unsigned long long);
				
				if (input[i] == 'd' || input[i] == 'i' || input[i] == 'u')
					str = ft_itoa(decimal);
				else
				{
					if (input[i] == 'x')
						str = ft_strtolower(ft_itoh(decimal));
					else
						str = ft_strtoupper(ft_itoh(decimal));

				}
				if (flags_value[2] == -1 && flags_value[1] == -1)
				{
					ft_putstr_fd(str, 1);
					cmp += ft_strlen(str);
				}
				else if (flags_value[1] == 0 && flags_value[2] == 0)
				{
					// Je sais pas encore si j'ai besoins de cette conditions.
				}
				else
				{
					if (ft_strlen(str) <= (size_t)flags_value[2])
						f = ft_strlen(str);
					else
						f = flags_value[2];
					//cmp += f;
					if (neg == 1)
					{
						ft_putchar_fd('-', 1);
						cmp++;
					}
					if (flags_value[0] == 0)
					{
						if (ft_strlen(str) <= (size_t)flags_value[1])
							f = ft_strlen(str);
						else
							f = flags_value[1];
						ft_before_data(flags_value[2], f, '0', &cmp);
						ft_putnstr(str, f);
						cmp += f;
						if (flags_value[2] != flags_value[1] && flags_value[1] != 0)
						{
							if (flags_value[1] != -1)
							{
								if (ft_strlen(str) <= (size_t)flags_value[1] && (int)ft_strlen(str) <= flags_value[2])
									f = flags_value[2];
								else
									f = ft_strlen(str);
								ft_before_data(flags_value[1], f, ' ', &cmp);
							}
							else
								ft_before_data(flags_value[2], f, ' ', &cmp);
							//cmp += f;
						}
					}
					else if (flags_value[0] == 2)
					{
						if (neg == 1)
						{
							f++;
							//cmp--;
						}
						if (ft_strlen(str) <= (size_t)flags_value[1])
							f = ft_strlen(str);
						else
							f = flags_value[1];
						if (flags_value[1] == -1)
						{
							ft_putnstr(str, f);
							ft_before_data(flags_value[2], f, ' ', &cmp);
						}
						else
						{
							ft_before_data(flags_value[2], f, '0', &cmp);
							ft_putnstr(str, f);
							if (flags_value[2] < flags_value[1])
								ft_before_data(flags_value[1], f, ' ', &cmp);
						}
						cmp += f;
					}
					else if (flags_value[0] == 1)
					{
						ft_before_data(flags_value[1], flags_value[2], ' ', &cmp);
						ft_before_data(flags_value[2], f, '0', &cmp);
						ft_putnstr(str, flags_value[2]);
						cmp += f;
					}
					//cmp += f;
				}
				f = 0;
				neg = 0;
				free(str);
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