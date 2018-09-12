/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:39:34 by mdambrev          #+#    #+#             */
/*   Updated: 2018/05/09 16:27:11 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_addrzone				*ft_create_malloc_list(void *ptr)
{
	t_addrzone			*racine;

	racine = (t_addrzone*)ptr;
	if (racine)
	{
		racine->next = NULL;
		racine->prev = NULL;
		racine->racine = racine;
	}
	return (racine);
}

t_chained				*ft_add_malloc_list(t_addrzone *racine, void *ptr)
{
	t_chained			*new;
	t_chained			*prev;

	new = (t_chained *)ptr;
	if (racine->prev == NULL)
	{
		racine->next = new;
		racine->prev = new;
	}
	prev = racine->prev;
	prev->next = new;
	racine->prev = new;
	new->prev = racine->prev;
	new->next = (void*)racine;
	new->racine = (void*)racine;
	new->free = 0;
	racine->nb_malloc++;
	return (new);
}

t_addrzone				*ft_add_zone_list(t_addrzone *racine, void *ptr)
{
	t_addrzone			*new;
	t_addrzone			*prev;

	new = (t_addrzone *)ptr;
	if (racine->zone_prev == NULL)
	{
		racine->zone_next = new;
		racine->zone_prev = new;
		new->zone_prev = racine;
		new->zone_next = racine;
	}
	else
	{
		prev = racine->zone_prev;
		prev->zone_next = new;
		new->zone_prev = prev;
		new->zone_next = racine;
		racine->zone_prev = new;
	}
	new->racine = new;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void					ft_delete_elem(t_addrzone *racine, void *ptr)
{
	t_addrzone			*elem;

	elem = (t_addrzone *)ptr;
	if (ptr == racine && (elem->zone_next == NULL || elem->zone_next == racine))
	{
		if (g_zone.type == 1)
			g_zone.t_zone = NULL;
		if (g_zone.type == 2)
			g_zone.s_zone = NULL;
		return ;
	}
	if (ptr == racine && elem->zone_next != NULL && elem->zone_next != ptr)
	{
		if (g_zone.type == 1)
			g_zone.t_zone = elem->zone_next;
		else if (g_zone.type == 2)
			g_zone.s_zone = elem->zone_next;
		else if (g_zone.type == 3)
			g_zone.l_zone = elem->zone_next;
	}
	elem->zone_prev->zone_next = elem->zone_next;
	elem->zone_next->zone_prev = elem->zone_prev;
}
