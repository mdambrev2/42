/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_list2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 09:42:50 by mdambrev          #+#    #+#             */
/*   Updated: 2015/10/14 16:25:53 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				del_elem(t_content *axx, int n_list, int pos_x, int sens)
{
	if (!LIST_A(n_list))
	{
		ft_putendl("\nERROR : (F_DEL_ELEM) list doesnt exist\n");
		return ;
	}
	LIST_R(n_list);
	while (pos_x--)
		LIST_I(n_list, sens);
	LIST_A(3) = LIST_V(n_list, 1);
	LIST_V(3, 0) = LIST_V(n_list, 0);
	LIST_A(3) = LIST_V(n_list, 0);
	LIST_V(3, 1) = LIST_V(n_list, 1);
	LIST_R(n_list);
}

static void			norm_move(t_content *axx, int pos_x, int pos_y)
{
	int sens;

	sens = ((pos_x > 0) && (pos_x != 0)) ? 0 : 1;
	if (pos_x < 0)
		pos_x = -pos_x;
	while (pos_x--)
		LIST_I(NB_LIST, sens);
	sens = ((pos_y > 0) && (pos_y != 0)) ? 0 : 1;
	if (pos_y < 0)
		pos_y = -pos_y;
	while (pos_y--)
		LIST_I(NB_LIST + 1, sens);
}

void				move_chain(t_content *axx, int pos_x, int pos_y)
{
	t_clist *src;

	norm_move(axx, pos_x, pos_y);
	src = TMP_A(0);
	TMP_A(2) = (src + 1)->bit;
	TMP_V(2, 0) = src->bit;
	TMP_A(2) = src->bit;
	TMP_V(2, 1) = (src + 1)->bit;
	src = TMP_A(0);
	src->bit = TMP_A(1);
	(src + 1)->bit = TMP_V(1, 1);
	(src + 2)->bit = TMP_V(1, 2);
	TMP_A(2) = TMP_V(1, 1);
	TMP_V(2, 0) = src;
	TMP_A(2) = ((t_clist*)TMP_V(1, 0) + 1)->bit;
	TMP_V(2, 1) = src;
}

t_clist				*init_racine(void)
{
	t_clist			*racine;

	racine = (t_clist*)ft_memalloc(sizeof(t_clist) * NB_CONTENT + 3);
	(racine + 2)->bit = racine;
	(racine + 3)->bit = 0;
	racine->bit = racine;
	(racine + 1)->bit = racine;
	return (racine);
}

void				add_content(t_clist **racine, void *content, t_clist **list)
{
	t_clist			*new;

	new = (t_clist*)ft_memalloc(sizeof(t_clist) * NB_CONTENT + 3);
	if ((*racine + 1)->bit == NULL)
	{
		(*racine + 1)->bit = new;
		new->bit = *racine;
	}
	else
	{
		((t_clist *)(*list)->bit + 1)->bit = new;
		new->bit = (*list)->bit;
	}
	(*list)->bit = new;
	(new + 3)->bit = content;
	(new + 2)->bit = *racine;
	(new + 1)->bit = *list;
}
