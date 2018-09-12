/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:23:48 by mdambrev          #+#    #+#             */
/*   Updated: 2014/11/13 17:41:17 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *s, int c, size_t n)
{
	unsigned int	x;

	x = 0;
	while (x < n)
	{
		((unsigned char *)s)[x] = (unsigned char)c;
		x++;
	}
	return (s);
}
