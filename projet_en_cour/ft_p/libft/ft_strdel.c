/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 03:51:59 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/21 20:12:30 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	ft_strdel(char **as)
{
	if (as)
	{
		free(*as);
		*as = NULL;
	}
}


void	free_tab(char **tab)
{
	int x;

	x = 0;
	while(tab[x])
	{
		ft_strdel(&tab[x]);
		x++;
	}
	free(tab);
}
