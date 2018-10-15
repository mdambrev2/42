/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:24:15 by mdambrev          #+#    #+#             */
/*   Updated: 2018/05/09 16:26:12 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "malloc.h"

void			*malloc(size_t size)
{
	void		*ret;

	pthread_mutex_lock(&g_malloc_lock);
	if (size == 0)
		return (NULL);
	ft_set_block_size(size);
	ft_init_map();
	if ((ret = ft_check_data(size)) != NULL)
	{
		return (ret);
	}
	ret = ft_set_data(size);
	if ((long long int)ret % 16 != 0)
		ft_putstr("ERROR\n");
	pthread_mutex_unlock(&g_malloc_lock);
	return (ret);
}

void			free(void *ptr)
{
	void		*to_munmap;
	static int	x = 0;

	x++;
	pthread_mutex_lock(&g_malloc_lock);
	if (ptr == NULL)
		return ;
	if ((to_munmap = ft_check_tiny(ptr)) != NULL)
	{
		g_zone.type = 1;
		ft_delete_tiny_ptr(to_munmap);
	}
	else if ((to_munmap = ft_check_small(ptr)) != NULL)
	{
		g_zone.type = 2;
		ft_delete_small_ptr(to_munmap);
	}
	else if ((to_munmap = ft_check_large(ptr)) != NULL)
	{
		g_zone.type = 3;
		ft_delete_large_ptr(to_munmap);
	}
	pthread_mutex_unlock(&g_malloc_lock);
}

void			*realloc(void *ptr, size_t size)
{
	void		*ret;

	pthread_mutex_lock(&g_malloc_lock);
	if (ptr == NULL)
	{
		return (malloc(size));
	}
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if ((ptr = ft_check_realloc(ptr)) == NULL)
	{
		return (NULL);
	}
	ret = ft_check_block(size, ptr);
	pthread_mutex_unlock(&g_malloc_lock);
	if ((long long int)ret % 16 != 0)
		ft_putstr("ERROR\n");
	return (ret);
}

void			*reallocf(void *ptr, size_t size)
{
	ptr = realloc(ptr, size);
	if (ptr == NULL)
		free(ptr);
	return (ptr);
}

void			*calloc(size_t count, size_t size)
{
	char		*ptr;
	size_t		allocation_size;

	ptr = NULL;
	allocation_size = count * size;
	ptr = malloc(allocation_size);
	if (ptr != NULL)
		ft_bzero(ptr, allocation_size);
	return (ptr);
}
