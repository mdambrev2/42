/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:37:15 by mdambrev          #+#    #+#             */
/*   Updated: 2014/11/13 17:35:54 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*str;

	str = (unsigned char*)s;
	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return ((char*)&str[i]);
		i++;
	}
	if ((unsigned char)c == '\0' && (str[i] == '\0'))
		return ((char*)str + i);
	return (NULL);
}
