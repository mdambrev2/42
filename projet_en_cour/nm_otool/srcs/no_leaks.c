/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_leaks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 13:46:38 by mdambrev          #+#    #+#             */
/*   Updated: 2018/12/04 10:27:21 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

int			free_sector(t_circ *sector)
{
	t_circ	*tmp;

	if (sector == NULL)
		return (1);
	tmp = sector->racine->next;
	while (tmp != tmp->racine && tmp)
	{
		ft_memdel((void*)&tmp->value);
		ft_memdel((void*)&tmp->function_name);
		ft_memdel((void*)&tmp->sector_name);
		tmp = tmp->next;
	}
	free_circ(sector->racine);
	return (1);
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
