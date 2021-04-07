/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:02:55 by bledda            #+#    #+#             */
/*   Updated: 2021/04/07 23:47:47 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	/*char str[] = "je suis une string";
	unsigned int plus = 500;
	int neg = -42;*/
	char *coucou;
	int *cc;

	coucou = ft_calloc(sizeof(char), 15);
	coucou = ft_strdup("coucou");
	printf("%p", &cc);
	printf("\n");
	ft_printf("%p", &cc);
	printf("\n");

	return (0);
}