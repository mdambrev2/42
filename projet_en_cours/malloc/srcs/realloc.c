/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:43:50 by mdambrev          #+#    #+#             */
/*   Updated: 2018/05/09 16:29:20 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			*ft_check_block_tiny(size_t size, void *ptr)
{
	t_chained	*tmp1;
	void		*tmp2;

	tmp1 = (t_chained *)ptr;
	if (size <= g_zone.t_block_size && tmp1->data + (long long int)size
			< tmp1->racine->end)
	{
		tmp1->size = size;
		return ((void*)((t_chained*)ptr)->data);
	}
	else
	{
		tmp2 = malloc(size);
		ft_memcpy(tmp2, (void*)tmp1->data, tmp1->size);
		free((void*)tmp1->data);
	}
	return (tmp2);
}

void			*ft_check_block_small(size_t size, void *ptr)
{
	t_chained	*tmp1;
	void		*tmp2;
	int			x;

	x = 0;
	tmp1 = ptr;
	if (size <= g_zone.s_block_size && tmp1->data +
			(long long int)size < tmp1->racine->end)
	{
		tmp1->size = size;
		tmp1->end = (long long int)tmp1->data + size;
		return ((void*)tmp1->data);
	}
	else
	{
		tmp2 = malloc(size);
		ft_memcpy(tmp2, (void*)tmp1->data, tmp1->size);
		free((void*)tmp1->data);
	}
	return (tmp2);
}

void			*ft_check_block_large(size_t size, void *ptr)
{
	t_addrzone	*tmp1;
	void		*tmp2;

	tmp1 = ptr;
	if ((long long int)size <= (tmp1->end - tmp1->data))
	{
		tmp1->size = size;
		return ((void*)((t_addrzone *)ptr)->data);
	}
	else
	{
		tmp2 = malloc(size);
		ft_memcpy(tmp2, (void*)tmp1->data, tmp1->size);
		free((void*)tmp1->data);
		return (tmp2);
	}
}

void			*ft_check_block(size_t size, void *ptr)
{
	void		*ret;

	ret = NULL;
	if (g_zone.type == 1)
		ret = ft_check_block_tiny(size, ptr);
	else if (g_zone.type == 2)
		ret = ft_check_block_small(size, ptr);
	else if (g_zone.type == 3)
		ret = ft_check_block_large(size, ptr);
	return (ret);
}
