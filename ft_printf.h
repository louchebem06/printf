/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:00:05 by bledda            #+#    #+#             */
/*   Updated: 2021/04/21 11:11:55 by bledda           ###   ########.fr       */
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
char	*ft_itoh(unsigned long long nb);
void	ft_strrev(char *str);
char	*ft_strtoupper(char *str);
char	*ft_strtolower(char *str);
void	ft_before_data(int start, int size, char charset, unsigned int *cmp);
int		ft_isconvert(char charset);
char	*ft_strreplace(char *mainstr, char charset, char *replace);
int		ft_strchrintab(char *str, char a, char b);
void	ft_putnstr(char *str, int n);
void	ft_flagsjoin(int *flags_value, va_list args, char *flags);
char	*ft_uitoa(unsigned int n);
void	ft_flags(char *flags, char *input, int *a);
void	ft_check_c(char input, va_list args, int *flags, unsigned int *cmp);
void	ft_check_percent(char input, int *flags_value, unsigned int *cmp);
void	ft_check_s(char input, va_list args, int *flags, unsigned int *cmp);
void	ft_check_p(char input, va_list args, int *flags, unsigned int *cmp);

#endif