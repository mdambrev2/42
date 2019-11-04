/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_char_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 22:54:04 by mdambrev          #+#    #+#             */
/*   Updated: 2015/08/15 17:45:38 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			nb_char_str(char *str, char c)
{
	int		x;
	int		y;

	y = 0;
	x = ft_strlen(str);
	while (x > 0)
	{
		if (*str == c)
			y++;
		x--;
		str++;
	}
	return (y);
}
