/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_data_32.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:45:02 by mdambrev          #+#    #+#             */
/*   Updated: 2018/10/05 19:59:05 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

char				*get_value_64(uint64_t value, char c)
{
	char			*ret;
	char			*tojoin;
	char			*tmp;
	int				strlen;
	int				x;

	x = 0;
	tojoin = NULL;
	if (value == 0 && c != 'T' && c != 't' && c != 'A')
		return (ft_strdup("                "));
	if (value == 0 && (c == 'T' || c == 't' || c == 'A'))
		return (ft_strdup("0000000000000000"));
	tmp = ft_convert_base_max(value, 16);
	strlen = 16 - ft_strlen(tmp);
	ret = tmp;
	if (strlen > 1)
	{
		tojoin = (char*)ft_memalloc(sizeof(char) * strlen + 1);
		while (x < strlen)
			tojoin[x++] = '0';
		tojoin[x] = '\0';
		ret = ft_strjoin(tojoin, tmp);
		ft_memdel((void *)&tojoin);
		ft_memdel((void *)&tmp);
	}
	return (ret);
}

static char			compare_sect(struct nlist_64 *array, t_circ *sector)
{
	int				cpt;

	cpt = 0;
	sector = sector->racine->next;
	while (sector != sector->racine)
	{
		cpt++;
		if (cpt == array->n_sect)
		{
			if (!ft_strncmp(sector->sector_name, SECT_DATA, 16))
				return ('d');
			else if (!ft_strncmp(sector->sector_name, SECT_BSS, 16))
				return ('b');
			else if (!ft_strncmp(sector->sector_name, SECT_TEXT, 16))
				return ('t');
		}
		sector = sector->next;
	}
	return ('s');
}

char				get_type_64(void *array, t_circ *sector)
{
	uint8_t			type;
	char			ret;

	type = ((struct nlist_64*)array)->n_type & N_TYPE;
	if (type == N_SECT)
		ret = compare_sect((struct nlist_64 *)array, sector);
	else if (type == N_UNDF)
	{
		if (((struct nlist_64*)array)->n_value == 0)
			ret = 'u';
		else
			ret = 'c';
	}
	else if (type == N_PBUD)
		ret = 'u';
	else if (type == N_ABS)
		ret = 'a';
	else if (type == N_INDR)
		ret = 'i';
	else
		ret = '?';
	if (((struct nlist_64 *)array)->n_type & N_EXT && type != '?')
		return (ft_toupper(ret));
	else
		return (ret);
}

int					get_priority_64(char *str)
{
	int				x;

	x = 0;
	while (str[x] && str[x] == '_')
		x++;
	return (x);
}

void				set_data_64(t_circ *elem, struct nlist_64 *array,
								char *stringtable, int type)
{
	elem->function_name = ft_strdup(stringtable + if_ppc_swap(array->n_un.n_strx));
	elem->type = get_type_64(array, (t_circ*)elem->racine->sector);
	elem->value = get_value_64(if_ppc_swap(array->n_value), elem->type);
	elem->n_value = if_ppc_swap(array->n_value);
	elem->n_desc = if_ppc_swap(array->n_desc);
	elem->priority = get_priority_64(elem->function_name);
	if (type == 64)
	{
		elem->is_64 = 1;
		elem->racine->is_64 = 1;
	}
}
