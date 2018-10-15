/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambtev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 22:38:39 by mdambrev          #+#    #+#             */
/*   Updated: 2018/05/09 16:26:24 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int							ft_get_nb_page_large(long long int size,
															int page_size)
{
	int						x;
	int						y;

	x = 1;
	y = 0;
	while (y < size)
	{
		y = page_size * x;
		x++;
	}
	return (--x);
}

void						ft_set_block_size(size_t size)
{
	static	int				page_size;
	static	long long int	x = 0;

	if (x == 0 && ++x)
	{
		page_size = getpagesize();
		g_zone.t_zone_size = page_size * COEFF_TINY;
		g_zone.t_block_size = ((g_zone.t_zone_size -
			(BLOCK_NUMBER * DATA_STRUCT) - DATA_RACINE) / BLOCK_NUMBER) - 16;
		g_zone.s_zone_size = page_size * COEFF_SMALL;
		g_zone.s_block_size = ((g_zone.s_zone_size
			- (BLOCK_NUMBER * DATA_STRUCT) - DATA_RACINE) / BLOCK_NUMBER) - 16;
		g_zone.ns_zone = 1;
		g_zone.nt_zone = 1;
	}
	if (size <= g_zone.t_block_size)
		g_zone.type = 1;
	else if (size <= g_zone.s_block_size)
		g_zone.type = 2;
	else if (size >= (g_zone.s_block_size + 1))
	{
		g_zone.l_zone_size = ft_get_nb_page_large(size +
			DATA_RACINE + (16 - (DATA_RACINE % 16)), page_size) * page_size;
		g_zone.type = 3;
	}
}

void						*norm_set_map(void)
{
	t_addrzone				*ret;

	ret = mmap(0, g_zone.s_zone_size, PROT_READ
			| PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	ft_bzero(ret, g_zone.s_zone_size);
	ret->end = (long long int)ret + (long long int)g_zone.s_zone_size;
	ret->data = (long long int)ret + DATA_RACINE;
	return (ret);
}

t_addrzone					*ft_set_map(int x)
{
	t_addrzone		*ret;

	ret = NULL;
	if (x == 1)
	{
		ret = mmap(0, g_zone.t_zone_size, PROT_READ
				| PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		ft_bzero(ret, g_zone.t_zone_size);
		ret->end = (long long int)ret + (long long int)g_zone.t_zone_size;
		ret->data = (long long int)ret + DATA_RACINE;
	}
	else if (x == 2)
		ret = norm_set_map();
	else if (x == 3)
	{
		ret = mmap(0, g_zone.l_zone_size, PROT_READ
				| PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		ft_bzero(ret, g_zone.l_zone_size);
		ret->end = (long long int)ret + (long long int)g_zone.l_zone_size;
	}
	ret->start = (long long int)ret;
	return (ret);
}

void						ft_init_map(void)
{
	if (g_zone.t_zone == NULL && g_zone.type == 1)
	{
		g_zone.t_zone = ft_set_map(1);
	}
	if (g_zone.s_zone == NULL && g_zone.type == 2)
	{
		g_zone.s_zone = ft_set_map(2);
	}
}
