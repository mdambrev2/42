/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:38:34 by mdambrev          #+#    #+#             */
/*   Updated: 2018/05/09 16:28:34 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void					*set_align(long long int tmp, long long int ret
																, size_t size)
{
	ret = (long long int)ret + (long long int)DATA_STRUCT;
	ret = (long long int)ret + (16 - ((long long int)ret % 16));
	((t_chained *)tmp)->data = ret;
	((t_chained *)tmp)->end = (long long int)ret + size;
	((t_chained *)tmp)->start = tmp;
	return ((void*)ret);
}

void					*ft_set_tiny_data(size_t size)
{
	long long int		ret;
	long long int		tmp;
	int					x;
	t_addrzone			*tmp2;

	x = 1;
	tmp2 = g_zone.t_zone;
	while (x++ < g_zone.nt_zone)
		tmp2 = tmp2->racine->zone_next;
	if (tmp2->racine == NULL)
		tmp2->racine = ft_create_malloc_list(tmp2);
	if (tmp2 != NULL && tmp2->racine->next == NULL)
	{
		tmp = (long long int)tmp2 + (long long int)(DATA_RACINE);
		ret = (long long int)ft_add_malloc_list(tmp2->racine, (void*)tmp);
		((t_chained *)tmp)->size = size;
	}
	else
	{
		tmp = (long long int)tmp2->racine->prev->data
			+ (long long int)tmp2->racine->prev->size;
		ret = (long long int)ft_add_malloc_list(tmp2->racine, (void*)tmp);
		((t_chained *)tmp)->size = size;
	}
	return (set_align(tmp, ret, size));
}

void					*ft_set_small_data(size_t size)
{
	long long int		ret;
	long long int		tmp;
	int					x;
	t_addrzone			*tmp2;

	x = 1;
	tmp2 = g_zone.s_zone;
	while (x++ < g_zone.ns_zone)
		tmp2 = tmp2->racine->zone_next;
	if (tmp2->racine == NULL)
		tmp2->racine = ft_create_malloc_list(tmp2);
	if (tmp2 != NULL && tmp2->racine->next == NULL)
	{
		tmp = (long long int)tmp2 + (long long int)(DATA_RACINE);
		ret = (long long int)ft_add_malloc_list(tmp2->racine, (void*)tmp);
		((t_chained *)tmp)->size = size;
	}
	else
	{
		tmp = (long long int)tmp2->racine->prev->data
			+ (long long int)tmp2->racine->prev->size;
		ret = (long long int)ft_add_malloc_list(tmp2->racine, (void*)tmp);
		((t_chained *)tmp)->size = size;
	}
	return (set_align(tmp, ret, size));
}

void					*ft_set_large_data(size_t size)
{
	long long int		ret;
	int					x;
	t_addrzone			*tmp2;

	x = 1;
	tmp2 = g_zone.l_zone;
	while (x++ < g_zone.nl_zone)
		tmp2 = tmp2->racine->zone_next;
	ret = (long long int)tmp2 + (long long int)(DATA_RACINE);
	ret = ret + (16 - ((long long int)ret % 16));
	((t_addrzone *)tmp2)->data = ret;
	((t_addrzone *)tmp2)->start = (long long int)tmp2;
	((t_addrzone *)tmp2)->size = (long long int)size;
	return ((void*)ret);
}

void					*ft_set_data(size_t size)
{
	if (g_zone.type == 1)
		return (ft_set_tiny_data(size));
	if (g_zone.type == 2)
		return (ft_set_small_data(size));
	if (g_zone.type == 3)
		return (ft_set_large_data(size));
	return (NULL);
}
