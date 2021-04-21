/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_xX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:55:58 by bledda            #+#    #+#             */
/*   Updated: 2021/04/21 21:00:39 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_xX(char input, va_list args, int *flags, unsigned int *cmp2)
{
	unsigned int	cmp;
	int neg;
	char *str;
	size_t f;
	unsigned long long decimal;

	cmp = 0;
	neg = 0;
	f = 0;
	str = 0;
	if (input != 'x' && input != 'X')
		return ;
	decimal = va_arg(args, unsigned int);
	if (decimal == 0)
		str = ft_strdup("0");
	else
		str = ft_itoh(decimal);
	if (input == 'x')
		str = ft_strtolower(str);
	else
		str = ft_strtoupper(str);
	
	/*
		PAS DE FLAGS
	*/
	if (flags[2] == -1 && flags[1] == -1)
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
		if (!(flags[1] == 0) || !(flags[2] == 0))
		{
			/*
				YA UN MOIN
			*/
			if (flags[0] == 0)
			{
				if (neg == 1)
				{
					ft_putchar_fd('-', 1);
					cmp++;
					f++;
				}
				if (flags[1] == -1)
				{
					f = 1;
					ft_putstr_fd("0", 1);
					if ((int)f < flags[2])
						ft_before_data(flags[2], f, ' ', &cmp);
				}
				else
				{
					if ((int)ft_strlen(str) >= flags[1] && (int)ft_strlen(str) >= flags[2])
					{
						ft_putstr_fd(str, 1);
						f = ft_strlen(str);
					}
					else
					{
						if ((int)ft_strlen(str) < flags[2])
						{
							ft_before_data(flags[2], ft_strlen(str), '0', 0);
							ft_putstr_fd(str, 1);
							f = flags[2];
						}
						else
						{
							ft_putstr_fd(str, 1);
							f = ft_strlen(str);
						}
						if ((int)f < flags[1] && neg != 1)
							ft_before_data(flags[1], f, ' ', &cmp);
						else if ((int)f < flags[1] && neg == 1)
							ft_before_data(flags[1], f + 1, ' ', &cmp);
					}
				}
			}

			/*
				PAS DE SYMBOLE
			*/
			else if (flags[0] == 1)
			{
				if (flags[1] == -1)
				{
					if ((int)ft_strlen(str) >= flags[2])
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
						f = 1;
						if ((int)f < flags[2])
							ft_before_data(flags[2], f, ' ', &cmp);
						ft_putstr_fd("0", 1);
					}
				}
				else
				{
					if (neg == 1)
					{
						cmp++;
						f++;
					}
					if ((int)ft_strlen(str) > flags[1] && (int)ft_strlen(str) > flags[2])
					{
						if (neg == 1)
							ft_putchar_fd('-', 1);
						ft_putstr_fd(str, 1);
						f = ft_strlen(str);
					}
					else
					{
						if ((int)ft_strlen(str) <= flags[2])
						{
							f = flags[2];
						}
						else
						{
							f = ft_strlen(str);
						}


						if ((int)f < flags[1] && ft_strncmp(str, "0", 1) != 0 && ft_strncmp(str, "1", 1) == 0)
						{
							ft_before_data(flags[1], f + 1, ' ', &cmp);
						}
						else if ((int)f < flags[1] && ft_strncmp(str, "0", 1) != 0)
						{
							ft_before_data(flags[1], f, ' ', &cmp);
						}


						if (neg == 1)
							ft_putchar_fd('-', 1);

						if ((int)ft_strlen(str) <= flags[2])
						{
							ft_before_data(flags[2], ft_strlen(str), '0', 0);
							ft_putstr_fd(str, 1);
						}
						else if (ft_strncmp(str, "0", 1) != 0)
						{
							ft_putstr_fd(str, 1);
						}
						else
						{
							ft_before_data(flags[1], 0, ' ', &cmp);
							cmp--;
						}
					}
				}	
			}

			/*
				SI YA UN ZERO
			*/
			else if (flags[0] == 2)
			{
				if (flags[1] == -1)
				{
					if (neg == 1)
					{
						f++;
						cmp++;
					}
					if (neg == 1)
						ft_putchar_fd('-', 1);
					f = ft_strlen(str);
					if ((int)f < flags[2] && neg == 0)
						ft_before_data(flags[2], f, '0', &cmp);
					else if ((int)f < flags[2] && neg == 1)
						ft_before_data(flags[2], f + 1, '0', &cmp);
					ft_putstr_fd(str, 1);
				}
				else
				{
					if ((int)ft_strlen(str) >= flags[1] && (int)ft_strlen(str) >= flags[2])
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
						if ((int)ft_strlen(str) <= flags[2])
							f = flags[2];
						else
							f = ft_strlen(str);

						if ((int)f < flags[1] && neg == 1)
							ft_before_data(flags[1], f + 1, ' ', &cmp);
						if ((int)f < flags[1] && neg !=  1)
							ft_before_data(flags[1], f, ' ', &cmp);

						if (neg == 1)
							ft_putchar_fd('-', 1);

						
						if ((int)ft_strlen(str) <= flags[2])
						{
							ft_before_data(flags[2], ft_strlen(str), '0', 0);
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
			else if (flags[0] == 3)
			{
				if (flags[1] == -1)
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
					if ((int)f < flags[2] && neg == 0)
						ft_before_data(flags[2], f, ' ', &cmp);
					if ((int)f < flags[2] && neg == 1)
						ft_before_data(flags[2], f + 1, ' ', &cmp);
				}
				else
				{
					if (neg == 1)
					{
						f++;
						cmp++;
					}
					if ((int)ft_strlen(str) <= flags[2])
						f = flags[2];
					else
						f = ft_strlen(str);

					if (neg == 1)
						ft_putchar_fd('-', 1);

					
					if ((int)ft_strlen(str) <= flags[2])
					{
						ft_before_data(flags[2], ft_strlen(str), '0', 0);
						ft_putstr_fd(str, 1);
					}
					else if (ft_strncmp(str, "0", 1) != 0)
						ft_putstr_fd(str, 1);
					else
						ft_putchar_fd(' ', 1);

					if ((int)f < flags[1] && neg == 1)
						ft_before_data(flags[1], f + 1, ' ', &cmp);
					if ((int)f < flags[1] && neg !=  1)
						ft_before_data(flags[1], f, ' ', &cmp);
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
		}
	}
	free(str);
	*cmp2 += cmp;
}
