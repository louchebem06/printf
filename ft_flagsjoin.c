/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagsjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:02:59 by bledda            #+#    #+#             */
/*   Updated: 2021/04/16 19:24:49 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flagsjoin(int *flags_value, va_list args, char *flags)
{
	char	*tmp;

	tmp = ft_strdup(flags);
	/************************/
	flags_value[1] = -1;
	if ((!ft_strchr(tmp, '.')) != 0)
		flags_value[2] = -1;
	if (ft_strnstr(tmp, "*.*", ft_strlen(tmp)) != 0)
	{
		flags_value[1] = va_arg(args, int);
		tmp = ft_strreplace(tmp, '*', ft_itoa(flags_value[1]));
		flags_value[2] = va_arg(args, int);
		tmp = ft_strreplace(tmp, '*', ft_itoa(flags_value[2]));
	}
	else if (ft_strnstr(tmp, "*.", ft_strlen(tmp)) != 0)
	{
		flags_value[1] = va_arg(args, int);
		tmp = ft_strreplace(tmp, '*', ft_itoa(flags_value[1]));
	}
	else if (ft_strnstr(tmp, ".*", ft_strlen(tmp)) != 0 || ft_strnstr(tmp, "*", ft_strlen(tmp)) != 0)
	{
		flags_value[2] = va_arg(args, int);
		tmp = ft_strreplace(tmp, '*', ft_itoa(flags_value[2]));
	}
	/*************************/
	if (tmp[0] == '-')
		flags_value[0] = 0;
	else
		flags_value[0] = 1;
	/*************************/
	if (ft_strchr(tmp, '.') != 0)
	{
		if (tmp[0] !=0)
		{
			if (ft_strchrintab(tmp, 'a', '.') == -1)
				flags_value[1] = 0;
			else
				flags_value[1] = ft_strchrintab(tmp, 'a', '.');
			if (ft_strchrintab(tmp, '.', 'b') == -1)
				flags_value[2] = 0;
			else if (ft_strchrintab(tmp, '.', 'b') != -1)
				flags_value[2] = ft_strchrintab(tmp, '.', 'b');
			if (flags_value[2] < 0)
				flags_value[2] = -1;
		}
	}
	else
	{
		if (tmp[0] !=0)
		{
			if (ft_strchrintab(tmp, 'a', 'b') != -1)
				flags_value[2] = ft_strchrintab(tmp, 'a', 'b');
			if (flags_value[2] < 0)
				flags_value[2] *= -1;
		}
	}
	/**********************************/
	if (flags_value[1] < 0 && flags_value[1] != -1)
			flags_value[1] *= -1;
	/********************************/
	if (tmp[0] == '0')
		flags_value[0] = 2;
	free(tmp);
}

/*
	MAN THIS FUNCTION

	This function incremante flags_value[3].
	If flags_value[0] = 0, your setting return string in start string,
	else your string here go end. if value is 2 is '0' and not - or empty
	flags_value[1] return number space for string, if equal -1 flags_value[2]
	in space functions.
	flags_value[2] return your number char for string else space if flags_value[1]
	is -1.
*/
