/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_zone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:49:38 by mdambrev          #+#    #+#             */
/*   Updated: 2018/05/09 16:21:41 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_addrzone		*ft_get_new_zone(void)
{
	t_addrzone	*ret;

	ret = NULL;
	if (g_zone.type == 1)
	{
		ret = ft_set_map(g_zone.type);
		ft_add_zone_list(g_zone.t_zone, ret);
		g_zone.nt_zone++;
	}
	if (g_zone.type == 2)
	{
		ret = ft_set_map(g_zone.type);
		ft_add_zone_list(g_zone.s_zone, ret);
		g_zone.ns_zone++;
	}
	if (g_zone.type == 3)
	{
		ret = ft_set_map(g_zone.type);
		if (g_zone.l_zone == NULL)
			g_zone.l_zone = ret;
		ft_add_zone_list(g_zone.l_zone, ret);
		g_zone.nl_zone++;
	}
	return (ret);
}

void			ft_set_new_zone(void)
{
	ft_get_new_zone();
}
