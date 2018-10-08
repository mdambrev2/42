/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:27:07 by mdambrev          #+#    #+#             */
/*   Updated: 2018/10/08 11:02:40 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

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

char					*add_octet(char *str, int strlen, int n_ret)
{
	int					n_octet;
	char				*ret;
	int					cpt;
	int					i;

	cpt = 0;
	n_octet = n_ret - strlen;
	ret = ft_strnew(n_ret + 1);
	i = 0;
	while (cpt < n_octet)
	{
		ret[cpt] = '0';
		cpt++;
	}
	while (str[i])
	{
		ret[cpt] = str[i];
		cpt++;
		i++;
	}
	free(str);
	return (ret);
}

char					*cut_hexa(char *str, int n)
{
	int					strlen;
	char				*ret;
	int					cpt;
	int					i;

	strlen = ft_strlen(str);
	if (strlen == n)
		return (str);
	else if (strlen < n)
		return ((ret = add_octet(str, strlen, 2)));
	cpt = strlen - n;
	ret = ft_strnew(n + 1);
	i = 0;
	while (str[cpt])
	{
		ret[i] = str[cpt];
		i++;
		cpt++;
	}
	free(str);
	return (ret);
}

char					*ft_convertn_base_max(uintmax_t quotient, int base,
																	int n)
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
		return (cut_hexa(ret, n));
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
	return (cut_hexa(ret, n));
}
