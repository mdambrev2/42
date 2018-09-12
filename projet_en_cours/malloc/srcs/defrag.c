/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defrag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:17:52 by mdambrev          #+#    #+#             */
/*   Updated: 2018/05/09 16:20:36 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static int			ft_check_tiny_range(size_t size)
{
	t_addrzone		*tmp1;
	t_chained		*tmp2;
	int				x;
	long long int	diff;

	tmp1 = g_zone.t_zone;
	if (g_zone.t_zone->prev == NULL)
		return (0);
	x = 1;
	while (tmp1 && tmp1->prev)
	{
		tmp2 = tmp1->prev;
		g_zone.nt_zone = x;
		diff = tmp2->end + DATA_STRUCT + size + 16;
		if (diff < tmp1->end && diff > tmp1->start)
			return (1);
		tmp1 = tmp1->zone_next;
		if (tmp1 == g_zone.t_zone)
			break ;
		x++;
	}
	ft_set_new_zone();
	return (0);
}

static int			ft_check_small_range(size_t size)
{
	t_addrzone		*tmp1;
	t_chained		*tmp2;
	int				x;
	long long int	diff;

	tmp1 = g_zone.s_zone;
	if (g_zone.s_zone->prev == NULL)
		return (0);
	x = 1;
	while (tmp1 && tmp1->prev)
	{
		tmp2 = tmp1->prev;
		g_zone.ns_zone = x;
		diff = tmp2->end + DATA_STRUCT + size + 16;
		if (diff < tmp1->end && diff > tmp1->start)
		{
			return (1);
		}
		tmp1 = tmp1->zone_next;
		if (tmp1 == g_zone.s_zone)
			break ;
		x++;
	}
	ft_set_new_zone();
	return (0);
}

int					ft_check_full(size_t size)
{
	int				ret;

	if (g_zone.type == 1)
		ret = ft_check_tiny_range(size);
	if (g_zone.type == 2)
		ret = ft_check_small_range(size);
	if (g_zone.type == 3)
		ft_set_new_zone();
	return (0);
}

void				*ft_check_data(size_t size)
{
	void			*ret;

	ret = NULL;
	if ((ret = ft_check_allocate_memorie(size)) != NULL)
		return (ret);
	ft_check_full(size);
	return (ret);
}
