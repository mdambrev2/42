/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_otool_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 18:42:25 by mdambrev          #+#    #+#             */
/*   Updated: 2018/10/19 18:29:33 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

char								*add_octet_otool_32(char *str,
													int strlen, int n_ret)
{
	int								n_octet;
	char							*ret;
	int								cpt;
	int								i;

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

int									if_sector_empty_banners(int x)
{
	static int						ret = 0;

	if (x == 1)
		ret = 1;
	if (x == 2)
		ret = 2;
	if (x == -1)
		ret = 0;
	return (ret);
}

uint32_t							swap_uint32(uint32_t val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return (val << 16) | (val >> 16);
}

uint64_t							if_ppc_swap(uint64_t value)
{
	if (static_banner_ppc(0) == 32)
		return (swap_uint32(value));
	else if (static_banner_ppc(0) == 64)
		return (swap_uint64(value));
	else
		return (value);
}

int									static_banner_ppc(int modifier)
{
	static int		x = 0;

	if (modifier == 32)
		x = 32;
	if (modifier == 64)
		x = 64;
	if (modifier == -1)
		x = 0;
	return (x);
}
