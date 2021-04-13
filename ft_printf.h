/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:00:05 by bledda            #+#    #+#             */
/*   Updated: 2021/04/13 20:27:44 by bledda           ###   ########.fr       */
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
void	ft_before_data(int start, int size_str, char charset, unsigned int *cmp);
int		ft_isconvert(char charset);
char	*ft_strreplace(char *mainstr, char charset, char *replace);
int		ft_strchrintab(char *str, char a, char b);
void 	ft_putnstr(char *str, int n);

#endif