/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 02:26:32 by mdambrev          #+#    #+#             */
/*   Updated: 2014/12/04 03:04:43 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int	x;

	x = 0;
	if (n == 0)
		return (1);
	if (s1 && s2)
	{
		while (*s2 || *s1)
		{
			if (*s1++ != *s2++)
				return (0);
			if (++x == n)
				return (1);
		}
		return (1);
	}
	return (0);
}
