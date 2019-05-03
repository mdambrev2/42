/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_add_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 13:24:57 by mdambrev          #+#    #+#             */
/*   Updated: 2018/10/19 18:27:42 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_circ		*add_elem_inblock_down(t_circ *ret)
{
	t_circ	*new;
	t_circ	*elem;

	elem = ret;
	if (!ret)
		ft_putstr("Error ret = NULL\n");
	new = (t_circ *)ft_memalloc(sizeof(t_circ));
	if (ret->next == ret->racine && ret->prev == ret->racine
								&& ret == ret->racine)
	{
		new->next = ret->racine;
		new->prev = ret->racine;
		new->racine = ret->racine;
		ret->next = new;
		ret->prev = new;
		return (new);
	}
	new->prev = elem;
	new->next = elem->next;
	elem->next->prev = new;
	elem->next = new;
	new->racine = ret->racine;
	new->ptr = new->racine->ptr;
	return (new);
}

t_circ		*add_elem_inblock_up(t_circ *ret)
{
	t_circ	*new;
	t_circ	*prev;
	t_circ	*next;

	next = ret;
	prev = ret->prev;
	if (!ret)
		ft_putstr("Error ret = NULL\n");
	new = (t_circ *)ft_memalloc(sizeof(t_circ));
	if (ret == ret->racine && ret->prev == ret->racine
							&& ret->next == ret->racine)
	{
		new->next = ret->racine;
		new->prev = ret->racine;
		new->racine = ret->racine;
		ret->next = new;
		ret->prev = new;
	}
	prev->next = new;
	next->prev = new;
	new->prev = prev;
	new->next = next;
	new->racine = ret->racine;
	new->ptr = new->racine->ptr;
	return (new);
}
