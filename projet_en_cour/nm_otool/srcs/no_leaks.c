/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_leaks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 13:46:38 by mdambrev          #+#    #+#             */
/*   Updated: 2018/09/28 21:27:01 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

void		free_sector(t_circ *sector)
{
	t_circ	*tmp;

	tmp = sector->racine->next;
	while (tmp != tmp->racine)
	{
		ft_memdel((void*)&tmp->sector_name);
		tmp = tmp->next;
	}
	free_circ(sector->racine);
}

void		free_tab(char **tab)
{
	int x;

	x = 0;
	while (tab[x])
	{
		ft_memdel((void *)&tab[x]);
		x++;
	}
	ft_memdel((void *)&tab);
}
