/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 18:21:30 by mdambrev          #+#    #+#             */
/*   Updated: 2014/11/13 17:39:48 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		x;
	unsigned char		*s1p;
	unsigned char		*s2p;

	s1p = (unsigned char *)s1;
	s2p = (unsigned char *)s2;
	x = 0;
	while (x < n)
	{
		if (s1p[x] != s2p[x])
			return (s1p[x] - s2p[x]);
		x++;
	}
	return (0);
}
