/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_data_32.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:45:02 by mdambrev          #+#    #+#             */
/*   Updated: 2018/05/29 15:42:25 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

char 	*get_value_32(uint64_t value, char c)
{
	char *ret;
	char *tojoin;
	char *tmp;
	int	 strlen;
	int  x;

	x = 0;
	tojoin = NULL;
	if(value == 0 && c != 'T')
		return(ft_strdup("        "));
	if(value == 0 && c == 'T')
		return(ft_strdup("00000000"));
	tmp = ft_convert_base_max(value, 16);
	strlen = 8 - ft_strlen(tmp);
	ret = tmp;
	if(strlen > 1)
	{
		tojoin = (char*)ft_memalloc(sizeof(char) * strlen + 1);
		while(x < strlen)
			tojoin[x++] = '0';	
		tojoin[x] = '\0';
		ret = ft_strjoin(tojoin, tmp);
//		free(tmp);
//		free(tojoin);
	}
	return(ret);
}

char	get_type_32(struct nlist *array)
{
	int value;
	int section;

	value = array->n_type;
	section = array->n_sect;

	if(value == 1)
		return('U');
	else if(value == 15 && section > 1)
		return('S');
	else if(value == 15 && section == 1)
		return('T');
	else if(value == 14 && section == 11)
		return('s');
	else if(value == 14 &&	section > 1)
		return('b');
	else if((value == 14 || value == 30) && section == 1)
		return('t');
	else if(value == 30 && section > 1)
		return('s');
	return('0');
}

int		 get_priority_32(char *str)
{
	int	x;

	x = 0;
	while(str[x] && str[x] == '_')
		x++;
	return(x);
}

void	set_data_32(t_circ *elem, struct nlist *array,											char *stringtable, int type)
{

	elem->function_name = ft_strdup(stringtable + array->n_un.n_strx);	
	elem->type = get_type_32(array);
	elem->value = get_value_32(array->n_value, elem->type);
	elem->n_desc = array->n_desc;
	elem->priority = get_priority_32(elem->function_name);
	type = 32;
	elem->is_32 = 1;
	elem->racine->is_32 = 1;
}

