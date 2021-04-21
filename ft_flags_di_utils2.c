/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_di_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:37:17 by bledda            #+#    #+#             */
/*   Updated: 2021/04/21 19:45:00 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_di_minus(unsigned int *cmp, int *flags, int neg, char *str)
{
	size_t			f;

	f = 0;
	if (flags[0] != 0)
		return ;
	ft_isneg_di(neg, cmp);
	if (flags[1] == -1)
	{
		ft_print_and_f_size(&f, str);
		ft_space_neg(f, flags[2], neg, cmp);
	}
	else
	{
		if ((int)ft_strlen(str) >= flags[1] && (int)ft_strlen(str) >= flags[2])
			ft_print_and_f_size(&f, str);
		else
		{
			if ((int)ft_strlen(str) < flags[2])
			{
				ft_before_data(flags[2], ft_strlen(str), '0', 0);
				ft_putstr_fd(str, 1);
				f = flags[2];
			}
			else
				ft_print_and_f_size(&f, str);
			ft_space_neg(f, flags[1], neg, cmp);
		}
	}
	*cmp += f;
}

void	ft_flags_di_clear(unsigned int *cmp, int *flags, int neg, char *str)
{
	size_t			f;

	f = 0;
	if (flags[0] != 1)
		return ;
	if (flags[1] == -1)
	{
		f = ft_strlen(str);
		ft_space_neg(f, flags[2], neg, cmp);
		ft_isneg_di(neg, cmp);
		ft_putstr_fd(str, 1);
	}
	else
	{
		if ((int)ft_strlen(str) > flags[1]
			&& (int)ft_strlen(str) > flags[2])
			ft_just_print(neg, cmp, str);
		else
		{
			if ((int)ft_strlen(str) <= flags[2])
				f = flags[2];
			else
				f = ft_strlen(str);
			if ((int)f < flags[1] && ft_strncmp(str, "0", 1) != 0
				&& ft_strncmp(str, "1", 1) == 0)
				ft_before_data(flags[1], f + 1, ' ', cmp);
			else if ((int)f < flags[1] && ft_strncmp(str, "0", 1) != 0)
				ft_before_data(flags[1], f, ' ', cmp);
			ft_isneg_di(neg, cmp);
			if ((int)ft_strlen(str) <= flags[2])
			{
				ft_before_data(flags[2], ft_strlen(str), '0', 0);
				ft_putstr_fd(str, 1);
			}
			else if (ft_strncmp(str, "0", 1) != 0)
				ft_putstr_fd(str, 1);
			else
			{
				ft_before_data(flags[1], 0, ' ', cmp);
				cmp--;
			}
		}
	}
	*cmp += f;
}

void	ft_flags_di_zero(unsigned int *cmp, int *flags, int neg, char *str)
{
	size_t			f;

	f = 0;
	if (flags[0] != 2)
		return ;
	if (flags[1] == -1)
	{
		ft_isneg_di(neg, cmp);
		f = ft_strlen(str);
		ft_zero_neg(f, flags[2], neg, cmp);
		ft_putstr_fd(str, 1);
	}
	else
	{
		if ((int)ft_strlen(str) >= flags[1]
			&& (int)ft_strlen(str) >= flags[2])
		{
			ft_isneg_di(neg, cmp);
			ft_print_and_f_size(&f, str);
		}
		else
		{
			if ((int)ft_strlen(str) <= flags[2])
				f = flags[2];
			else
				f = ft_strlen(str);
			if ((int)f < flags[1] && neg == 1)
				ft_before_data(flags[1], f + 1, ' ', cmp);
			if ((int)f < flags[1] && neg != 1)
				ft_before_data(flags[1], f, ' ', cmp);
			ft_isneg_di(neg, cmp);
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
	*cmp += f;
}

void	ft_flags_di_zero_minu(unsigned int *cmp, int *flags, int neg, char *str)
{
	size_t			f;

	f = 0;
	if (flags[0] != 3)
		return ;
	if (flags[1] == -1)
	{
		ft_isneg_di(neg, cmp);
		ft_print_and_f_size(&f, str);
		ft_space_neg(f, flags[2], neg, cmp);
	}
	else
	{
		ft_isneg_di(neg, cmp);
		if ((int)ft_strlen(str) <= flags[2])
			f = flags[2];
		else
			f = ft_strlen(str);
		if ((int)ft_strlen(str) <= flags[2])
		{
			ft_before_data(flags[2], ft_strlen(str), '0', 0);
			ft_putstr_fd(str, 1);
		}
		else if (ft_strncmp(str, "0", 1) != 0)
			ft_putstr_fd(str, 1);
		else
			ft_putchar_fd(' ', 1);
		ft_space_neg(f, flags[1], neg, cmp);
	}
	*cmp += f;
}

void	ft_flags_di(int *flags, unsigned int *cmp2, int neg, char *str)
{
	unsigned int	cmp;

	cmp = 0;
	if (!(flags[1] == 0) || !(flags[2] == 0))
	{
		ft_flags_di_minus(&cmp, flags, neg, str);
		ft_flags_di_clear(&cmp, flags, neg, str);
		ft_flags_di_zero(&cmp, flags, neg, str);
		ft_flags_di_zero_minu(&cmp, flags, neg, str);
	}
	else if (ft_strncmp(str, "0", 1) != 0)
	{
		ft_isneg_di(neg, &cmp);
		ft_putstr_fd(str, 1);
		cmp += ft_strlen(str);
	}
	*cmp2 += cmp;
}
