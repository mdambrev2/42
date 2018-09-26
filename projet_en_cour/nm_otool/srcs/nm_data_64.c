/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_data_64.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:45:02 by mdambrev          #+#    #+#             */
/*   Updated: 2018/09/26 17:38:41 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

char 	*get_value(uint64_t value, char c)
{
	char *ret;
	char *tojoin;
	char *tmp;
	int	 strlen;
	int  x;

	x = 0;
	tojoin = NULL;
	if(value == 0 && c != 'T')
		return(ft_strdup("                "));
	if(value == 0 && c == 'T')
		return(ft_strdup("0000000000000000"));
	tmp = ft_convert_base_max(value, 16);
	strlen = 16 - ft_strlen(tmp);
	ret = tmp;
	if(strlen > 1)
	{
		tojoin = (char*)ft_memalloc(sizeof(char) * strlen + 1);
		while(x < strlen)
			tojoin[x++] = '0';	
		tojoin[x] = '\0';
		ret = ft_strjoin(tojoin, tmp);
	}
	return(ret);
}



static char	compare_sect(struct nlist_64 *array, t_circ *sector)
{
	int cpt;

	cpt = 0;
	sector = sector->racine->next;
	while(sector != sector->racine)
	{

		cpt++;
		if(cpt == array->n_sect)
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
	return('s');
}

char	get_type_64(struct nlist_64 *array, t_circ *sector)
{
	uint8_t type;
	char ret;

	type = array->n_type & N_TYPE;
	if (type == N_SECT)
		ret = compare_sect(array, sector);
	else if (type == N_UNDF)
		ret = 'u';
	else if (type == N_PBUD)
		ret = 'u';
	else if (type == N_ABS)
		ret = 'a';
	else if (type == N_INDR)
		ret = 'i';
	else
		ret = '?';
	if (array->n_type & N_EXT && type != '?')
		return(ft_toupper(ret));
	else
		return (ret);
}

int		 get_priority(char *str)
{
	int	x;

	x = 0;
	while(str[x] && str[x] == '_')
		x++;
	return(x);
}

void	set_data_64(t_circ *elem, struct nlist_64 *array,											char *stringtable, int type)
{
	elem->function_name = ft_strdup(stringtable + array->n_un.n_strx);
	elem->type = get_type_64(array, (t_circ*)elem->racine->sector);	
	elem->value = get_value(array->n_value, elem->type);
	elem->n_desc = array->n_desc;
	elem->priority = get_priority(elem->function_name);
	if(type == 64)
	{
		elem->is_64 = 1;
		elem->racine->is_64 = 1;
	}
}
