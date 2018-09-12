/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:39:34 by mdambrev          #+#    #+#             */
/*   Updated: 2018/05/23 17:13:23 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_list.h"

t_circ				*create_circular_list(void)
{
	t_circ			*racine;

	racine = (t_circ*)ft_memalloc(sizeof(t_circ));
	if (racine)
	{
		racine->next = racine;
		racine->prev = racine;
		racine->racine = racine;
		racine->content = NULL;
	}
	return (racine);
}

t_circ				*addfin_circ_elem(t_circ *racine)
{
	t_circ			*new;
	t_circ			*prev;

	if (racine == NULL)
	{
		ft_putstr("Error : Racine = NULL\n");
		return (NULL);
	}
	new = (t_circ *)ft_memalloc(sizeof(t_circ ));
	if (racine->prev == racine)
	{
		racine->next = new;
		racine->prev = new;
	}
	prev = racine->prev;
	prev->next = new;
	new->prev = prev;

	racine->prev = new;
	new->next = racine;
	new->racine = racine;
	return (new);
}

void				free_racine(t_circ *racine, t_circ *elem)
{
	if (racine)
	{
		if (racine->content)
			ft_memdel((void*)&racine->content);
		ft_memdel((void*)&racine->content);
	}
	if (elem)
	{
		if (elem->content)
			ft_memdel((void*)&elem->content);
		ft_memdel((void*)&elem);
	}
}

void				free_circ(t_circ *racine)
{
	t_circ *elem;
	t_circ *tmp;

	tmp = NULL;
	if (racine->next != racine)
		elem = racine->next;
	else
	{
		if (racine->content)
			ft_memdel((void*)&racine->content);
		free(racine);
		return ;
	}
	while (elem != racine)
	{
		if (elem->content)
			ft_memdel((void*)&elem->content);
		tmp = elem->next;
		ft_memdel((void*)&elem);
		elem = tmp;
	}
	if (racine || elem)
		free_racine(racine, elem);
}
