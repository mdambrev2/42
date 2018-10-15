/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 19:23:36 by mdambrev          #+#    #+#             */
/*   Updated: 2018/03/26 18:55:01 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*cpy;
	int		x;

	x = 0;
	if (s == NULL || f == NULL
	|| (cpy = (char*)ft_memalloc(sizeof(cpy) * (int)ft_strlen(s) + 1)) == NULL)
		return (NULL);
	while (*s && ++x)
		*cpy++ = (*f)(*s++);
	*cpy = '\0';
	return (cpy - x);
}
