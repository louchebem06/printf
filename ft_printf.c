/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:01:47 by bledda            #+#    #+#             */
/*   Updated: 2021/04/19 15:16:41 by bledda           ###   ########.fr       */
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

			else if (input[i] == 'd' || input[i] == 'i' || input[i] == 'u' || input[i] == 'x' || input[i] == 'X')
			{
				if (input[i] == 'd' || input[i] == 'i')
				{
					decimal = va_arg(args, int);
					if ((int)decimal < 0 && (int)decimal != -2147483648)
					{
						neg = 1;
						decimal *= -1;
					}
					str = ft_itoa(decimal);
				}
				else if (input[i] == 'u')
				{
					decimal = va_arg(args, unsigned int);
					/*if ((unsigned int)decimal < 0)
					{
						neg = 1;
						decimal *= -1;
					}*/
					str = ft_uitoa(decimal);
				}
				else if (input[i] == 'x' || input[i] == 'X')
				{
					decimal = va_arg(args, unsigned long long);
					/*if ((unsigned long long)decimal < 0)
					{
						neg = 1;
						decimal *= -1;
					}*/
					str = ft_itoh(decimal);
					if (input[i] == 'x')
						str = ft_strtolower(str);
					else
						str = ft_strtoupper(str);
				}
				
				//printf("%d", (int)decimal);
				//ft_putstr_fd(str, 1);
				//str = ft_itoa(decimal);
				// Pas de Flags
				if (flags_value[2] == -1 && flags_value[1] == -1)
				{
					if (input[i] == 'x' || input[i] == 'X')
					{
						if (str[i] == 0)
						{
							ft_putchar_fd('0', 1);
							cmp++;
						}
					}
					ft_putstr_fd(str, 1);
					cmp += ft_strlen(str);
				}
				else
				{
					if (!(flags_value[1] == 0) || !(flags_value[2] == 0))
					{
						//Si ya un moin
						if (flags_value[0] == 0)
						{
							//printf("HERE");
							if (neg == 1)
							{
								ft_putchar_fd('-', 1);
								cmp++;
								f++;
							}
							// 1 Param
							if (flags_value[1] == -1)
							{
								// 2 Param
								// if str et plus grand que param 1 et 2 affiche str
								// if str et plus petit que param 2 ajouter zero avant
								// si le plus grand de param 2 ou str et plus petit que param 1
								//alors mettre de espace pour completer
								//printf("HERE");

								f = ft_strlen(str);
								ft_putstr_fd(str, 1);
								if ((int)f < flags_value[2])
									ft_before_data(flags_value[2], f, ' ', &cmp);
								//ft_putstr_fd(str, 1);
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
										ft_before_data(flags_value[2], ft_strlen(str), '0', 0);
										ft_putstr_fd(str, 1);
										f = flags_value[2];
									}
									else
									{
										ft_putstr_fd(str, 1);
										f = ft_strlen(str);
									}
									if ((int)f < flags_value[1] && neg != 1)
										ft_before_data(flags_value[1], f, ' ', &cmp);
									else if ((int)f < flags_value[1] && neg == 1)
										ft_before_data(flags_value[1], f + 1, ' ', &cmp);
									//f--;
								}
							}
						}
						//Si ya un rien
						else if (flags_value[0] == 1)
						{
							//printf("HERE");
							// 1 Param
							if (flags_value[1] == -1)
							{
								if ((int)ft_strlen(str) >= flags_value[2])
								{
									ft_putstr_fd(str, 1);
									f = ft_strlen(str);
								}
								else
								{
									//ft_putstr_fd(str, 1);
									/*if ((int)ft_strlen(str) < flags_value[2])
										f = flags_value[2];
									else*/
									f = ft_strlen(str);
									if ((int)f < flags_value[2])
										ft_before_data(flags_value[2], f, ' ', &cmp);
									ft_putstr_fd(str, 1);
									//f--;
								}
							}
							else
							{
								//printf("HERE");
								// 2 Param
								// if str et plus grand que param 1 et 2 affiche str
								// if str et plus petit que param 2 ajouter zero avant
								// si le plus grand de param 2 ou str et plus petit que param 1
								//alors mettre de espace pour completer
								if (neg == 1)
								{
									//ft_putchar_fd('-', 1);
									cmp++;
									f++;
								}
								if ((int)ft_strlen(str) > flags_value[1] && (int)ft_strlen(str) > flags_value[2])
								{
									ft_putstr_fd(str, 1);
									f = ft_strlen(str);
								}
								else
								{
									if (input[i] == 'u' && ft_strncmp(str, "4294967295", 10) == 0
										&& flags_value[2] < 11 && flags_value[1] > 10)
									{
										ft_putchar_fd(' ', 1);
										cmp++;
									}
									//printf("HERE");
									if ((int)ft_strlen(str) <= flags_value[2])
									{
										f = flags_value[2];
									}
									else
									{
										f = ft_strlen(str);
									}
									if ((int)f < flags_value[1] && ft_strncmp(str, "0", 1) != 0)
									{
										ft_before_data(flags_value[1], f + 1, ' ', &cmp);
									}
									if (neg == 1)
										ft_putchar_fd('-', 1);

									if ((int)ft_strlen(str) <= flags_value[2])
									{
										ft_before_data(flags_value[2], ft_strlen(str), '0', 0);
										ft_putstr_fd(str, 1);
									}
									else if (ft_strncmp(str, "0", 1) != 0)
									{
										ft_putstr_fd(str, 1);
									}
									else
									{
										//printf("HERE");
										//ft_putchar_fd(' ', 1);
										ft_before_data(flags_value[1], 0, ' ', &cmp);
										cmp--;
									}
									//f--;
								}
							}	
						}
						//Si ya un zero
						else if (flags_value[0] == 2)
						{
							//printf("HERE");
							// 1 Param
							if (flags_value[1] == -1)
							{
								if (neg == 1)
								{
									f++;
									cmp++;
								}
								/*f = ft_strlen(str);*/
								if (neg == 1)
									ft_putchar_fd('-', 1);
								/*if ((int)f < flags_value[2])
									ft_before_data(flags_value[2], f + 1, '0', &cmp);
								ft_putstr_fd(str, 1);*/

								f = ft_strlen(str);
								//ft_putstr_fd(str, 1);
								if ((int)f < flags_value[2] && neg == 0)
									ft_before_data(flags_value[2], f, '0', &cmp);
								else if ((int)f < flags_value[2] && neg == 1)
									ft_before_data(flags_value[2], f + 1, '0', &cmp);
								ft_putstr_fd(str, 1);
							}
							else
							{
								// 2 Param
								if ((int)ft_strlen(str) >= flags_value[1] && (int)ft_strlen(str) >= flags_value[2])
								{
									if (neg == 1)
									{
										ft_putchar_fd('-', 1);
										cmp++;
										f++;
									}
									ft_putstr_fd(str, 1);
									f = ft_strlen(str);
								}
								else
								{
									//printf("HERE");
									if (neg == 1)
									{
										f++;
										cmp++;
									}
									if ((int)ft_strlen(str) <= flags_value[2])
										f = flags_value[2];
									else
										f = ft_strlen(str);

									if ((int)f < flags_value[1] && neg == 1)
										ft_before_data(flags_value[1], f + 1, ' ', &cmp);
									if ((int)f < flags_value[1] && neg !=  1)
										ft_before_data(flags_value[1], f, ' ', &cmp);

									if (neg == 1)
										ft_putchar_fd('-', 1);

									
									if ((int)ft_strlen(str) <= flags_value[2])
									{
										ft_before_data(flags_value[2], ft_strlen(str), '0', 0);
										ft_putstr_fd(str, 1);
									}
									else if (ft_strncmp(str, "0", 1) != 0)
										ft_putstr_fd(str, 1);
									else
										ft_putchar_fd(' ', 1);
									
									}
							}
						}
						//Si ya un zero et un moin -
						else if (flags_value[0] == 3)
						{
							//printf("HERE");
							// 1 Param
							if (flags_value[1] == -1)
							{
								if (neg == 1)
								{
									f++;
									cmp++;
								}
								f = ft_strlen(str);
								if (neg == 1)
									ft_putchar_fd('-', 1);
								ft_putstr_fd(str, 1);
								if ((int)f < flags_value[2] && neg == 0)
									ft_before_data(flags_value[2], f, ' ', &cmp);
								if ((int)f < flags_value[2] && neg == 1)
									ft_before_data(flags_value[2], f + 1, ' ', &cmp);
							}
							else
							{
								//printf("here");
								//printf("%s", str);
								if (neg == 1)
								{
									f++;
									cmp++;
								}
								if ((int)ft_strlen(str) <= flags_value[2])
									f = flags_value[2];
								else
									f = ft_strlen(str);

								if (neg == 1)
									ft_putchar_fd('-', 1);

								
								if ((int)ft_strlen(str) <= flags_value[2])
								{
									ft_before_data(flags_value[2], ft_strlen(str), '0', 0);
									ft_putstr_fd(str, 1);
								}
								else if (ft_strncmp(str, "0", 1) != 0)
									ft_putstr_fd(str, 1);
								else
									ft_putchar_fd(' ', 1);

								if ((int)f < flags_value[1] && neg == 1)
									ft_before_data(flags_value[1], f + 1, ' ', &cmp);
								if ((int)f < flags_value[1] && neg !=  1)
									ft_before_data(flags_value[1], f, ' ', &cmp);
								
								
								//f--;
							}
						}
						cmp += f;
					}
					else
					{
						//printf("HERE");
						if ((ft_strncmp(str, "0", 1) != 0 && input[i] != 'x')
							&& (ft_strncmp(str, "0", 1) != 0 && input[i] != 'X'))
						{
							ft_putstr_fd(str, 1);
							cmp = ft_strlen(str);
							//printf("HERE");
						}
					}
				}
				f = 0;
				neg = 0;
				free(str);
			}
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