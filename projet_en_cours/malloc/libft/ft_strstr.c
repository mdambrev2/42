/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:13:24 by mdambrev          #+#    #+#             */
/*   Updated: 2014/11/13 17:20:56 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	int		x;
	int		y;
	char	*str1;
	char	*str2;
	int		tmp;

	x = 0;
	y = 0;
	str1 = (char*)s1;
	str2 = (char*)s2;
	if (!*str2)
		return (char *)s1;
	while (str1 && str1[x])
	{
		tmp = x;
		while ((str1[tmp] == str2[y]) && str1[tmp] != '\0' && str2[y++] != '\0')
		{
			tmp++;
		}
		if (str2[y] == '\0')
			return (&str1[x]);
		y = 0;
		x++;
	}
	return (NULL);
}
