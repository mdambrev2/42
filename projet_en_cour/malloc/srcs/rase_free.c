/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rase_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 09:55:31 by mdambrev          #+#    #+#             */
/*   Updated: 2018/05/09 16:22:24 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			ft_delete_tiny_ptr(void *ptr)
{
	t_addrzone	*tmp;

	tmp = ((t_addrzone *)ptr);
	if (g_zone.nt_zone > 1)
	{
		ft_delete_elem(g_zone.t_zone, tmp);
		ft_bzero(ptr, g_zone.t_zone_size);
		munmap(ptr, g_zone.t_zone_size);
		g_zone.nt_zone--;
	}
	else
	{
		tmp->next = NULL;
		tmp->prev = NULL;
		ft_bzero((void*)tmp->data, g_zone.t_zone_size
			- ((long long int)tmp->data - (long long int)tmp));
		tmp->racine = tmp;
	}
}

void			ft_delete_small_ptr(void *ptr)
{
	t_addrzone	*tmp;

	tmp = ((t_addrzone *)ptr);
	if (g_zone.ns_zone > 1)
	{
		ft_delete_elem(g_zone.s_zone, tmp);
		ft_bzero(ptr, g_zone.s_zone_size);
		munmap(ptr, g_zone.s_zone_size);
		g_zone.ns_zone--;
	}
	else
	{
		tmp->next = NULL;
		tmp->prev = NULL;
		ft_bzero((void*)tmp->data, g_zone.s_zone_size
			- (tmp->data - (long long int)tmp));
		tmp->racine = tmp;
	}
}

void			ft_delete_large_ptr(void *ptr)
{
	t_addrzone	*tmp;

	tmp = (t_addrzone *)ptr;
	ft_delete_elem(g_zone.l_zone, tmp);
	ft_bzero(ptr, ((t_addrzone*)ptr)->end - (long long int)ptr);
	munmap(ptr, ((t_addrzone*)ptr)->end - (long long int)ptr);
	if (g_zone.nl_zone == 1)
		g_zone.l_zone = NULL;
	g_zone.nl_zone--;
}
