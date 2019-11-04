/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:27:07 by mdambrev          #+#    #+#             */
/*   Updated: 2018/04/26 15:34:02 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

uintmax_t				set_x(uintmax_t quotient,
								int base)
{
	uintmax_t			x;

	x = 0;
	while (quotient > 0)
	{
		quotient = quotient / base;
		x++;
	}
	return (x);
}

void					set_base_tab(uintmax_t base, char *basetab)
{
	char				*ret;
	uintmax_t			x;
	int					tmp;

	x = 0;
	tmp = '0';
	ret = basetab;
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
}

void					ft_put_base_max(uintmax_t quotient, int base)
{
	char				ret[100];
	uintmax_t			reste;
	uintmax_t			mult;
	uintmax_t			pos;
	char				basetab[base + 1];

	mult = set_x(quotient, base);
	set_base_tab(base, basetab);
	if (mult == 0)
	{
		ft_putstr("0");
		return ;
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
	ret[pos] = '\0';
	ft_putstr(ret);
}

void					ft_put_hexa(uintmax_t quotient)
{
	ft_putstr("0x");
	ft_put_base_max(quotient, 16);
}
