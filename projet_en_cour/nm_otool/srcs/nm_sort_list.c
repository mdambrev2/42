/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 13:16:35 by mdambrev          #+#    #+#             */
/*   Updated: 2018/09/29 20:20:08 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

t_circ					*sort_by_desc_32(t_circ *ret, struct nlist *array,
											char *stringtable)
{
	t_circ				*tmp;

	tmp = ret->racine->next;
	while (tmp != ret->racine)
	{
		if (ft_strcmp(stringtable + array->n_un.n_strx, tmp->function_name) < 0)
			return (tmp);
		tmp = tmp->next;
	}
	if (tmp == tmp->racine)
		return (ret->racine);
	return (tmp);
}

t_circ					*sort_by_desc_64(t_circ *ret, struct nlist_64 *array,
											char *stringtable)
{
	t_circ				*tmp;

	tmp = ret->racine->next;
	while (tmp != ret->racine)
	{
		if (ft_strcmp(stringtable + array->n_un.n_strx, tmp->function_name) < 0)
			return (tmp);
		tmp = tmp->next;
	}
	if (tmp == tmp->racine)
		return (ret->racine);
	return (tmp);
}

void					set_info_list_order(t_circ *ret, void *array,
											char *stringtable, int type)
{
	t_circ				*prev_elem;
	t_circ				*elem;
	struct nlist		*array32;
	struct nlist_64		*array64;

	array32 = (struct nlist*)array;
	array64 = (struct nlist_64*)array;
	elem = NULL;
	if (type == 64 && get_type_64(array, (t_circ*)ret->racine->sector) != '?'
		&& ((char *)stringtable + array64->n_un.n_strx)[0] != 0)
	{
		prev_elem = sort_by_desc_64(ret, array64, stringtable);
		elem = add_elem_inblock_up(prev_elem);
		set_data_64(elem, array64, stringtable, type);
	}
	if (type == 32 && get_type_64(array, (t_circ*)ret->racine->sector) != '?' 
		&& ((char *)stringtable + array64->n_un.n_strx)[0] != 0 )
	{
		prev_elem = sort_by_desc_32(ret, array32, stringtable);
		elem = add_elem_inblock_up(prev_elem);
		set_data_32(elem, array32, stringtable, type);
	}
}
