/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:27:07 by mdambrev          #+#    #+#             */
/*   Updated: 2018/04/23 16:02:21 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static char				*base_alloc(uintmax_t quotient,
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

static char				*set_base_tab(uintmax_t base)
{
	char				*ret;
	uintmax_t			x;
	int					tmp;

	x = 0;
	tmp = '0';
	ret = (char *)ft_memalloc(sizeof(char) * base + 1);
	while (x < base && tmp >= '0' && tmp <= '9')
	{
		ret[x] = tmp;
		tmp++;
		x++;
	}
	tmp = 'a';
	while (x < base && tmp >= 'a' && tmp <= 'z')
	{
		ret[x] = tmp;
		tmp++;
		x++;
	}
	ret[x] = '\0';
	return (ret);
}

char					*ft_convert_base_max(uintmax_t quotient, int base)
{
	char				*ret;
	uintmax_t			reste;
	uintmax_t			mult;
	uintmax_t			pos;
	char				*basetab;

	mult = 0;
	ret = base_alloc(quotient, &mult, base);
	basetab = set_base_tab(base);
	if (mult == 0)
	{
		ft_memdel((void*)&basetab);
		return (ret);
	}
	mult--;
	pos = 0;
	while (quotient > 0)
	{
		reste = quotient % base;
		quotient = quotient / base;
		ret[mult - pos] = basetab[reste];
		pos++;
	}
	ft_memdel((void*)&basetab);
	return (ret);
}
