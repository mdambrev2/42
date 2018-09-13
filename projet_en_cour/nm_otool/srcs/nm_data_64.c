/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_data_64.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:45:02 by mdambrev          #+#    #+#             */
/*   Updated: 2018/09/13 18:50:15 by mdambrev         ###   ########.fr       */
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

char	get_type(struct nlist_64 *array)
{
	int value;
	int section;

	value = array->n_type;
	section = array->n_sect;

	if(value == 1)
		return('U');
	else if(value == 15 && section > 1)
	{
		printf("%llu\n", array->n_value);
		return('S');
	}
	else if(value == 15 && section == 1)
		return('T');
	else if(value == 14 &&	section > 1)
		return('b');
	else if(value == 14 && section == 1)
		return('t');
	return('0');
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
	elem->type = get_type(array);	
	elem->value = get_value(array->n_value, elem->type);
	elem->n_desc = array->n_desc;
	elem->priority = get_priority(elem->function_name);
	if(type == 64)
	{
		elem->is_64 = 1;
		elem->racine->is_64 = 1;
	}
}

