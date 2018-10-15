/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 11:36:07 by mdambrev          #+#    #+#             */
/*   Updated: 2018/03/26 18:48:01 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strupper(char *str)
{
	char		*ret;
	int			x;

	x = 0;
	ret = (char*)ft_memalloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[x])
	{
		ret[x] = ft_toupper(str[x]);
		x++;
	}
	str[x] = '\0';
	return (ret);
}
