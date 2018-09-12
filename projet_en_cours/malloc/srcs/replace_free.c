/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 21:12:53 by mdambrev          #+#    #+#             */
/*   Updated: 2018/05/09 16:23:13 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		*ft_check_tiny_allocate(size_t size)
{
	t_addrzone	*tmp1;
	t_chained	*tmp2;

	tmp1 = g_zone.t_zone;
	if (g_zone.t_zone->next == NULL)
		return (NULL);
	while (tmp1 && (tmp2 = tmp1->next) != NULL)
	{
		while (tmp2 && (void*)tmp2 != (void*)tmp1
				&& (long long int)tmp2 < tmp1->end)
		{
			if (tmp2->size >= size && tmp2->free == 1)
			{
				tmp2->free = 0;
				tmp2->size = size;
				tmp1->nb_malloc++;
				return ((void*)tmp2->data);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->zone_next;
		if (tmp1 == g_zone.t_zone)
			break ;
	}
	return (NULL);
}

static void		*ft_check_small_allocate(size_t size)
{
	t_addrzone	*tmp1;
	t_chained	*tmp2;

	tmp1 = g_zone.s_zone;
	if (g_zone.s_zone->next == NULL)
		return (NULL);
	while (tmp1 && (tmp2 = tmp1->next) != NULL)
	{
		while (tmp2 && (void*)tmp2 != (void*)tmp1
				&& (long long int)tmp2 < tmp1->end)
		{
			if (tmp2->size >= size && tmp2->free == 1)
			{
				tmp2->free = 0;
				tmp2->size = size;
				tmp1->nb_malloc++;
				return ((void*)tmp2->data);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->zone_next;
		if (tmp1 == g_zone.s_zone)
			break ;
	}
	return (NULL);
}

void			*ft_check_allocate_memorie(size_t size)
{
	void		*ret;

	ret = NULL;
	if (g_zone.type == 1)
		ret = ft_check_tiny_allocate(size);
	if (g_zone.type == 2)
		ret = ft_check_small_allocate(size);
	return (ret);
}
