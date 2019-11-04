/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 04:03:30 by mdambrev          #+#    #+#             */
/*   Updated: 2018/12/10 10:13:08 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*cpy;
	int		x;

	x = 0;
	if (!s1 || !s2)
		return (NULL);
	if ((cpy = (char*)ft_memalloc(sizeof(cpy) *
					(ft_strlen(s1) + ft_strlen(s2) + 1))) == NULL)
		return (NULL);
	while (*s2 || (*s2 == '\0' && *s1))
	{
		if (*s1 != '\0')
			*cpy++ = *s1++;
		else
			*cpy++ = *s2++;
		x++;
	}
	*cpy = '\0';
	return (cpy - x);
}
