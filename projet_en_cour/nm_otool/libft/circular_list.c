/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:39:34 by mdambrev          #+#    #+#             */
/*   Updated: 2018/09/26 17:17:53 by mdambrev         ###   ########.fr       */
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
	t_circ			*next;

	if (racine == NULL)
		return (NULL);
	new = (t_circ *)ft_memalloc(sizeof(t_circ ));
	if(racine->next == racine->racine && racine->prev == racine->racine && racine == racine->racine)
	{
		new->next = racine->racine;
		new->prev = racine->racine;
		new->racine = racine->racine;
		racine->next = new;
		racine->prev = new;
		return (new);
	}
	next = racine->racine;
	prev = racine->racine->prev;
	prev->next = new;
	next->prev = new;
	new->prev = prev;
	new->next = next;
	new->racine = racine->racine;
	new->ptr = new->racine->ptr;
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
