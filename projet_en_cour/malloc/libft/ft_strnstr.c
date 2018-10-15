/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 15:50:41 by mdambrev          #+#    #+#             */
/*   Updated: 2014/12/01 18:25:31 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned	int x;
	unsigned	int y;
	unsigned	int tmp;

	x = 0;
	y = 0;
	if (ft_strlen((char *)s2) == 0)
		return ((char *)s1);
	while (s1[x] != '\0' && x < n)
	{
		tmp = x;
		if (s1[x] == s2[y])
		{
			while (s1[tmp] && s2[y] && (s1[tmp] == s2[y]) && tmp++ < n)
			{
				y++;
			}
			if (y == ft_strlen((char *)s2))
				return ((char *)s1 + x);
		}
		else
			y = 0;
		x++;
	}
	return (NULL);
}
