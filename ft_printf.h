/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:00:05 by bledda            #+#    #+#             */
/*   Updated: 2021/04/09 13:44:09 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *input, ...);
char	*ft_itoh(unsigned int nb);
void	ft_strrev(char *str);
char	*ft_strtoupper(char *str);
char	*ft_strtolower(char *str);

#endif