/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 16:44:55 by mdambrev          #+#    #+#             */
/*   Updated: 2014/12/03 22:20:07 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	x;

	x = 0;
	while (x < n && s)
	{
		if (((unsigned char*)s)[x] == (unsigned char)c)
			return (((unsigned char *)s) + x);
		x++;
	}
	return (NULL);
}
