/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_data_32.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:45:02 by mdambrev          #+#    #+#             */
/*   Updated: 2018/09/20 16:17:36 by mdambrev         ###   ########.fr       */
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
	}
	return(ret);
}

char	get_sect_32(struct nlist *array, struct segment_command *seg, t_circ *elem)
{
	
	int cpt;
	int x;
	struct section *sect;

	cpt = array->n_sect;
	sect = (void*)seg + sizeof(struct segment_command);
	x = 0;
	while(x < cpt)
	{
		sect = (void*)sect + 2;
		x++;
	}
	if(ft_strcmp("_g_choose", elem->function_name) == 0)
	{
		printf("%s %s\n", sect->segname, sect->sectname);
	}
	elem++;
	elem--;
	if (!ft_strncmp(sect->sectname, SECT_DATA, 16))
		return ('d');
	else if (!ft_strncmp(sect->sectname, SECT_BSS, 16))
		return ('b');
	else if (!ft_strncmp(sect->sectname, SECT_TEXT, 16))
		return ('t');
	return ('s');
}


char get_seg_32(struct nlist *array, t_circ *elem)
{
	struct mach_header	*header;
	struct load_command		*lc;
	int						n_cmd;
	int							x;
	char						ret;
	struct segment_command	*seg;

	x = 0;
	ret = 0;
	header = (struct mach_header*)elem->ptr;
	n_cmd = header->ncmds;
	lc = elem->ptr + sizeof(struct mach_header);
	while(x < n_cmd)
	{
		if(lc->cmd == LC_SEGMENT)
		{
			seg = (struct segment_command*)lc;	
			if((ret = get_sect_32(array, seg, elem)) != 's')
				break;
		}
		lc = (void*)lc + lc->cmdsize;
		x++;
	}
	return(ret);
}

char	get_type_32(struct nlist *array, t_circ *elem)
{
	uint8_t type;
	char ret;


	type = array->n_type & N_TYPE;
	if (type == N_SECT)
		ret = get_seg_32(array, elem);
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

int      get_priority_32(char *str)
{
	int x;

	x = 0;
	while(str[x] && str[x] == '_')
		x++;
	return(x);
}

void	set_data_32(t_circ *elem, struct nlist *array,											char *stringtable, int type)
{

	elem->function_name = ft_strdup(stringtable + array->n_un.n_strx);
	elem->type = get_type_32(array, elem);
	elem->value = get_value_32(array->n_value, elem->type);
	elem->n_desc = array->n_desc;
	elem->priority = get_priority_32(elem->function_name);
	type = 32;
	elem->is_32 = 1;
	elem->racine->is_32 = 1;
}

