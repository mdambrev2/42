/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base_suite.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:55:06 by mdambrev          #+#    #+#             */
/*   Updated: 2018/10/08 11:05:18 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char				*base_alloc(uintmax_t quotient,
								uintmax_t *mult, int base)
{
	uintmax_t			x;
	char				*ret;

	x = 0;
	while (quotient > 0)
	{
		quotient = quotient / base;
		x++;
	}
	*mult = x;
	if (*mult == 0)
	{
		ret = (char*)ft_memalloc(sizeof(char) * 2);
		ret[0] = '0';
		ret[1] = '\0';
		return (ret);
	}
	ret = (char *)ft_memalloc(sizeof(char) * x);
	ret[x] = '\0';
	return (ret);
}
