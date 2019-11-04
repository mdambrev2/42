/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:36:36 by mdambrev          #+#    #+#             */
/*   Updated: 2014/12/04 03:33:43 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = (unsigned char*)malloc(sizeof(*str) * n);
	ft_memcpy(str, s2, n);
	ft_memcpy(s1, str, n);
	free(str);
	return (s1);
}
