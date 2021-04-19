/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:01:47 by bledda            #+#    #+#             */
/*   Updated: 2021/04/19 23:33:38 by bledda           ###   ########.fr       */
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
			ft_flags(flags, (char *)input, &i);
			ft_flagsjoin(flags_value, args, flags);

			/*
				GESTION DE C ET DU %
			*/
			if (input[i] == 'c' || input[i] == '%')
			{
				if (input[i] == 'c')
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

			/*
				GESTION DES STRING
			*/
			if (input[i] == 's')
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

			/*
				GESTION DES POINTER
			*/
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

			/*
				GESTION DE DIUXX
			*/
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
					str = ft_uitoa(decimal);
				}
				else if (input[i] == 'x' || input[i] == 'X')
				{
					decimal = va_arg(args, unsigned int);
					if (decimal == 0)
						str = ft_strdup("0");
					else
						str = ft_itoh(decimal);
					if (input[i] == 'x')
						str = ft_strtolower(str);
					else
						str = ft_strtoupper(str);
				}
				
				/*
					PAS DE FLAGS
				*/
				if (flags_value[2] == -1 && flags_value[1] == -1)
				{
					if (neg == 1)
					{
						ft_putchar_fd('-', 1);
						cmp++;
					}
					ft_putstr_fd(str, 1);
					cmp += ft_strlen(str);
				}
				else
				{
					if (!(flags_value[1] == 0) || !(flags_value[2] == 0))
					{
						/*
							YA UN MOIN
						*/
						if (flags_value[0] == 0)
						{
							if (neg == 1)
							{
								ft_putchar_fd('-', 1);
								cmp++;
								f++;
							}
							if (flags_value[1] == -1)
							{
								if ((input[i] == 'X' || input[i] == 'x') && str[0] == 0)
								{
									f = 1;
									ft_putstr_fd("0", 1);
									if ((int)f < flags_value[2])
										ft_before_data(flags_value[2], f, ' ', &cmp);
								}
								else
								{
									f = ft_strlen(str);
									ft_putstr_fd(str, 1);
									if ((int)f < flags_value[2])
									{
										if (neg == 0)
											ft_before_data(flags_value[2], f, ' ', &cmp);
										else if (neg == 1)
											ft_before_data(flags_value[2], f + 1, ' ', &cmp);
									}
								}
							}
							else
							{
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
								}
							}
						}

						/*
							PAS DE SYMBOLE
						*/
						else if (flags_value[0] == 1)
						{
							if (flags_value[1] == -1)
							{
								if ((int)ft_strlen(str) >= flags_value[2])
								{
									if (neg == 1)
									{
										ft_putchar_fd('-', 1);
										cmp++;
									}
									ft_putstr_fd(str, 1);
									f = ft_strlen(str);
								}
								else
								{
									if ((input[i] == 'X' || input[i] == 'x') && str[0] == 0)
									{
										f = 1;
										if ((int)f < flags_value[2])
											ft_before_data(flags_value[2], f, ' ', &cmp);
										ft_putstr_fd("0", 1);
									}
									else
									{
										f = ft_strlen(str);
										if ((int)f < flags_value[2])
										{
											if (neg == 1)
												ft_before_data(flags_value[2], f + 1, ' ', &cmp);
											else
												ft_before_data(flags_value[2], f, ' ', &cmp);
										}
										if (neg == 1)
										{
											ft_putchar_fd('-', 1);
											cmp++;
										}
										ft_putstr_fd(str, 1);
									}
								}
							}
							else
							{
								if (neg == 1)
								{
									cmp++;
									f++;
								}
								if ((int)ft_strlen(str) > flags_value[1] && (int)ft_strlen(str) > flags_value[2])
								{
									if (neg == 1)
										ft_putchar_fd('-', 1);
									ft_putstr_fd(str, 1);
									f = ft_strlen(str);
								}
								else
								{
									if ((int)ft_strlen(str) <= flags_value[2])
									{
										f = flags_value[2];
									}
									else
									{
										f = ft_strlen(str);
									}


									if ((int)f < flags_value[1] && ft_strncmp(str, "0", 1) != 0 && ft_strncmp(str, "1", 1) == 0)
									{
										ft_before_data(flags_value[1], f + 1, ' ', &cmp);
									}
									else if ((int)f < flags_value[1] && ft_strncmp(str, "0", 1) != 0)
									{
										ft_before_data(flags_value[1], f, ' ', &cmp);
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
										ft_before_data(flags_value[1], 0, ' ', &cmp);
										cmp--;
									}
								}
							}	
						}

						/*
							SI YA UN ZERO
						*/
						else if (flags_value[0] == 2)
						{
							if (flags_value[1] == -1)
							{
								if (neg == 1)
								{
									f++;
									cmp++;
								}
								if (neg == 1)
									ft_putchar_fd('-', 1);
								f = ft_strlen(str);
								if ((int)f < flags_value[2] && neg == 0)
									ft_before_data(flags_value[2], f, '0', &cmp);
								else if ((int)f < flags_value[2] && neg == 1)
									ft_before_data(flags_value[2], f + 1, '0', &cmp);
								ft_putstr_fd(str, 1);
							}
							else
							{
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

						/*
							ZERO + MOIN
						*/
						else if (flags_value[0] == 3)
						{
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
							}
						}
						cmp += f;
					}
					else
					{
						if (ft_strncmp(str, "0", 1) != 0)
						{
							if (neg == 1)
							{
								ft_putchar_fd('-', 1);
								cmp++;
							}
							ft_putstr_fd(str, 1);
							cmp += ft_strlen(str);
						}
						if (ft_strncmp(str, "0", 1) == 0 && flags[1] == '1')
						{
							ft_putchar_fd(' ', 1);
							cmp++;
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