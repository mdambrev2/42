/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 22:10:18 by mdambrev          #+#    #+#             */
/*   Updated: 2017/02/20 10:23:06 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			replace_char(char **str, char ent, char sort)
{
	int			x;
	char		*str1;
	int			y;

	y = 0;
	str1 = *str;
	x = nb_word_str(str1, ent);
	while (x > 0)
	{
		if (str1[y] == ent)
		{
			while (str1[y] == ent)
				str1[y++] = sort;
			x--;
		}
		y++;
	}
}

void			replace_n_char(char **str, char ent, char sort, int n)
{
	char		*str1;
	int			y;

	str1 = *str;
	y = 0;
	if (nb_char_str(str1, ent) < n)
		n = nb_char_str(str1, ent);
	while (n > 0)
	{
		if (str1[y] == ent)
		{
			str1[y] = sort;
			n--;
		}
		y++;
	}
}
