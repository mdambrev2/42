/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 01:32:31 by mdambrev          #+#    #+#             */
/*   Updated: 2018/02/15 16:50:02 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*cpy;
	unsigned int	x;

	x = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	if ((cpy = (char*)ft_memalloc(sizeof(cpy) * ft_strlen(s) + 1)) == NULL)
		return (NULL);
	while (*s && ++x)
		*cpy++ = (*f)(x - 1, *s++);
	*cpy = '\0';
	return (cpy - x);
}
