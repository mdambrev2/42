/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_list3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 16:25:19 by mdambrev          #+#    #+#             */
/*   Updated: 2018/03/26 19:54:53 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void				sort_list_bul(t_content *axx,
							int nlist, int (*cmp)(int, int))
{
	int	x;

	x = 0;
	TMP_A(0) = LIST_A(nlist);
	while (LIST_IB(NB_LIST, 0) == 0)
	{
		TMP_A(1) = TMP_A(0);
		while (LIST_IB(NB_LIST + 1, 0) == 0)
		{
			if (cmp(TMP_I(0, 0), TMP_I(1, 0)) != 0)
			{
				x = TMP_I(0, 0);
				TMP_I(0, 0) = TMP_I(1, 0);
				TMP_I(1, 0) = x;
			}
		}
	}
}

void				add_lstr(t_clist **list, int n_mail, int pos_x, void *src)
{
	int				x;
	t_content		ax;
	t_content		*axx;

	x = 0;
	ax.list = *list;
	axx = &ax;
	LIST_R(0);
	if (n_mail < 0)
	{
		while (LIST_IB(0, 0) == 0)
			x++;
		n_mail = x + n_mail;
		x = 0;
	}
	while (LIST_IB(0, 0) == 0)
	{
		if (x == n_mail)
		{
			VALUE_C(0, pos_x) = src;
			break ;
		}
		x++;
	}
}

void				**list_to_tab(t_content *axx, int n_list,
									int type, int n_content)
{
	void			**tab;
	int				x;

	x = 0;
	TMP_A(0) = LIST_A(n_list);
	LIST_R(NB_LIST);
	while (LIST_IB(NB_LIST, 0) == 0)
		x++;
	tab = (void **)ft_memalloc(sizeof(void *) * x + 1);
	LIST_R(NB_LIST);
	x = 0;
	while (LIST_IB(NB_LIST, 0) == 0)
	{
		if (type == 1)
		{
			tab[x] = ft_strdup(VALUE_C(NB_LIST, n_content));
		}
		x++;
	}
	tab[x] = 0;
	return (tab);
}
