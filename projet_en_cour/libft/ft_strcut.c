/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:56:10 by mdambrev          #+#    #+#             */
/*   Updated: 2018/10/24 17:24:36 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcut(const char *s1, const char *s2)
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
			return (ft_strndup(str1, tmp, ft_strlen(str1)));
		y = 0;
		x++;
	}
	return (NULL);
}
