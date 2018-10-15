/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:40:55 by mdambrev          #+#    #+#             */
/*   Updated: 2014/11/13 17:34:51 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	x;

	x = ft_strlen((const char*)s);
	if ((char)c == '\0')
		return ((char*)&s[x]);
	while (s && x >= 0)
	{
		if (s[x] == (char)c)
			return ((char*)&s[x]);
		x--;
	}
	return (NULL);
}
