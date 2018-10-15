/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:55:29 by mdambrev          #+#    #+#             */
/*   Updated: 2018/05/09 16:20:20 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			*ft_check_tiny_realloc(void *ptr)
{
	t_addrzone	*tmp1;
	t_chained	*tmp2;

	tmp1 = g_zone.t_zone;
	while (tmp1)
	{
		if (ptr > (void*)tmp1->start && ptr < (void*)tmp1->end)
		{
			tmp2 = tmp1->next;
			while (tmp2 && tmp2 != (void*)tmp1)
			{
				if ((long long int)ptr == tmp2->data && tmp2->free != 1)
				{
					g_zone.type = 1;
					return (tmp2);
				}
				tmp2 = tmp2->next;
			}
		}
		tmp1 = tmp1->zone_next;
		if (tmp1 == g_zone.t_zone)
			break ;
	}
	return (NULL);
}

void			*ft_check_small_realloc(void *ptr)
{
	t_addrzone	*tmp1;
	t_chained	*tmp2;

	tmp1 = g_zone.s_zone;
	while (tmp1)
	{
		if (ptr > (void *)tmp1->start && ptr < (void *)tmp1->end)
		{
			tmp2 = tmp1->next;
			while (tmp2 && tmp2 != (void*)tmp1
					&& (long long int)tmp2 < tmp1->end)
			{
				if ((long long int)ptr == tmp2->data && tmp2->free != 1)
				{
					g_zone.type = 2;
					return (tmp2);
				}
				tmp2 = tmp2->next;
			}
		}
		tmp1 = tmp1->zone_next;
		if (tmp1 == g_zone.s_zone)
			break ;
	}
	return (NULL);
}

void			*ft_check_large_realloc(void *ptr)
{
	t_addrzone	*tmp1;
	int			y;

	y = 0;
	tmp1 = g_zone.l_zone;
	while (tmp1)
	{
		if ((long long int)ptr == tmp1->data)
		{
			g_zone.type = 3;
			return (tmp1);
		}
		tmp1 = tmp1->zone_next;
		if (tmp1 == g_zone.l_zone)
			break ;
	}
	return (NULL);
}

void			*ft_check_realloc(void *ptr)
{
	void		*ret;

	if ((ret = ft_check_tiny_realloc(ptr)) != NULL)
		return (ret);
	if ((ret = ft_check_small_realloc(ptr)) != NULL)
		return (ret);
	else if ((ret = ft_check_large_realloc(ptr)) != NULL)
		return (ret);
	return (NULL);
}
