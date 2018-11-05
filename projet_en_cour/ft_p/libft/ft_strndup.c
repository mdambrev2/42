/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:47:21 by mdambrev          #+#    #+#             */
/*   Updated: 2018/10/25 20:52:41 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strndup(char *str, int start, int end)
{
	char		*ret;
	int			x;
	int			secu;

	secu = ft_strlen(str);
	if (secu < start)
		ft_putstr("error ft_strndup \n");
	if (secu < end)
		end = secu;
	x = 0;
	ret = ft_strnew(end - start + 2);
	while (start < end)
	{
		ret[x] = str[start];
		start++;
		x++;
	}
	ret[start] = '\0';
	return (ret);
}
