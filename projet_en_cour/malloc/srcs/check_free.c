/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:55:29 by mdambrev          #+#    #+#             */
/*   Updated: 2018/05/09 16:28:58 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			*ptr_ret(t_chained *tmp2, t_addrzone *tmp1)
{
	if (tmp2->free != 1)
		tmp1->nb_malloc--;
	tmp2->free = 1;
	if (tmp1->nb_malloc == 0)
		return ((void*)tmp1);
	else
		return (NULL);
}

void			*ft_check_tiny(void *ptr)
{
	t_addrzone	*tmp1;
	t_chained	*tmp2;

	tmp1 = g_zone.t_zone;
	while (tmp1 && ptr)
	{
		if ((long long int)ptr > tmp1->start && (long long int)ptr < tmp1->end)
		{
			tmp2 = tmp1->next;
			while (tmp2 && tmp2 != (void*)tmp1)
			{
				if ((long long int)ptr == tmp2->data)
					return (ptr_ret(tmp2, tmp1));
				tmp2 = tmp2->next;
			}
		}
		tmp1 = tmp1->zone_next;
		if (tmp1 == g_zone.t_zone)
			break ;
	}
	return (NULL);
}

void			*ft_check_small(void *ptr)
{
	t_addrzone	*tmp1;
	t_chained	*tmp2;

	tmp1 = g_zone.s_zone;
	while (tmp1 && ptr)
	{
		if ((long long int)ptr > tmp1->start && (long long int)ptr < tmp1->end)
		{
			tmp2 = tmp1->next;
			while (tmp2 && tmp2 != (void*)tmp1)
			{
				if ((long long int)ptr == tmp2->data)
					return (ptr_ret(tmp2, tmp1));
				tmp2 = tmp2->next;
				if ((long long int)tmp2 > tmp1->end)
					break ;
			}
		}
		tmp1 = tmp1->zone_next;
		if (tmp1 == g_zone.s_zone)
			break ;
	}
	return (NULL);
}

void			*ft_check_large(void *ptr)
{
	t_addrzone	*tmp1;
	int			y;

	y = 0;
	tmp1 = g_zone.l_zone;
	while (tmp1)
	{
		if ((long long int)ptr == tmp1->data)
			return ((void*)tmp1);
		tmp1 = tmp1->zone_next;
		if (tmp1 == g_zone.l_zone)
			break ;
	}
	return (NULL);
}
