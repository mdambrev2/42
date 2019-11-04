/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:28:25 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/12 16:45:02 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_memclrcpy(void *dest, const void *src, size_t n,
									size_t size_max)
{
	if (size_max < n)
		ft_putendl("Error memclrcpy : size_max < n");
	ft_bzero(dest, size_max);
	ft_memcpy(dest, src, n);
}

void				*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned	int	x;

	x = 0;
	while (x < n)
	{
		((unsigned char *)dest)[x] = ((unsigned char*)src)[x];
		x++;
	}
	return (dest);
}
