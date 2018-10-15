/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringtonbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:31:29 by mdambrev          #+#    #+#             */
/*   Updated: 2018/03/26 18:58:18 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int			ft_stringtonbr(char *str)
{
	int		ret;
	int		cpt;
	int		neg;
	int		x;

	x = 0;
	ret = 0;
	neg = 0;
	if (str[x] == '-')
	{
		str++;
		neg = 1;
	}
	cpt = ft_strlen(str) - 1;
	while (str[x] && ft_isdigit(str[x]))
	{
		ret = ret * 10 + (str[x] - 48);
		cpt--;
		x++;
	}
	if (neg == 1)
		ret = ret * (-1);
	return (ret);
}
