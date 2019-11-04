/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:59:23 by mdambrev          #+#    #+#             */
/*   Updated: 2014/11/18 03:32:27 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	x;

	x = 0;
	while (x < n)
	{
		((unsigned char*)dest)[x] = ((unsigned char*)src)[x];
		if (((unsigned char *)dest)[x] == ((unsigned char)c))
			return (dest + x + 1);
		x++;
	}
	return (NULL);
}
