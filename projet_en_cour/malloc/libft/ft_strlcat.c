/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 10:10:25 by mdambrev          #+#    #+#             */
/*   Updated: 2014/11/13 17:47:48 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	x;
	unsigned int	y;

	x = ft_strlen(dst);
	y = 0;
	if (x >= size)
		return (size + ft_strlen(src));
	while (x < size - 1 && src[y] != '\0')
	{
		dst[x] = src[y];
		x++;
		y++;
	}
	dst[x] = '\0';
	return (ft_strlen(src) + x - y);
}
