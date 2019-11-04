/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/17 02:01:47 by mdambrev          #+#    #+#             */
/*   Updated: 2017/02/20 10:17:31 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_content			*init_list(void)
{
	t_content		*axx;
	int				x;

	x = 0;
	axx = (t_content *)ft_memalloc(sizeof(t_content) * (NB_LIST + 1));
	while (x < NB_LIST + 4)
	{
		(axx + x)->list = NULL;
		x++;
	}
	return (axx);
}

void				add_l(t_clist **list, void *src, int pos_x)
{
	t_clist			*racine;
	int				sens;
	t_clist			*tmp;

	racine = NULL;
	if (*list == NULL)
	{
		racine = init_racine();
		*list = racine;
		if (src == NULL)
			return ;
	}
	sens = ((pos_x > 0) && (pos_x != 0)) ? 0 : 1;
	if (pos_x)
		pos_x = -pos_x;
	tmp = *list;
	while (sens == 0 && pos_x-- > 0)
		tmp = tmp->bit;
	while (sens == 1 && pos_x-- > 0)
		tmp = (tmp + 1)->bit;
	add_content(list, src, &tmp);
}

void				free_list(t_content *axx, int z)
{
	int				y;
	int				x;

	y = NB_CONTENT + 3;
	x = 0;
	while (x < y)
	{
		if (VALUE_C(z, x))
			free(VALUE_C(z, x));
		x++;
	}
}

void				clear_list(t_content *axx, int x)
{
	LIST_R(x);
	while ((LIST_IC(x, 0)) != 0)
	{
		free_list(axx, x);
		LIST_I(x, 0);
	}
}

void				list_del(t_content *axx, int nb_list)
{
	int			x;

	x = 0;
	while (x < nb_list)
	{
		if (LIST_A(x))
			clear_list(axx, x);
		x++;
	}
	free(axx);
}
