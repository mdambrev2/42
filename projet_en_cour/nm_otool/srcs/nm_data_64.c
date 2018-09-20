/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_data_64.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:45:02 by mdambrev          #+#    #+#             */
/*   Updated: 2018/09/20 16:59:13 by mdambrev         ###   ########.fr       */
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

/*

static uint8_t	compare_sect(struct section_64 *sect)
{
	if (sect && !(ft_strncmp(SECT_TEXT, sect->sectname, 16)))
		return ((uint8_t)'T');
	else if (sect && !(ft_strncmp(SECT_DATA, sect->sectname, 16)))
		return ((uint8_t)'D');
	else if (sect && !(ft_strncmp(SECT_BSS, sect->sectname, 16)))
		return ((uint8_t)'B');
	else
c		return ((uint8_t)'S');
}
*/

char	get_sect(struct nlist_64 *array, struct segment_command_64 *seg)
{
	

	int cpt;
	uint64_t x;
	struct section_64 *sect;

	array++;
	array--;
	cpt = array->n_sect;
	sect = (void*)seg + sizeof(struct segment_command_64);
	x = 0;
	printf("\n-\n");
	while(x < seg->nsects)
	{
		printf("%s\n", sect->sectname);
/*		if(array->n_sect == x)
		{
			if (!ft_strncmp(sect->sectname, SECT_DATA, 16))
		return ('d');
	else if (!ft_strncmp(sect->sectname, SECT_BSS, 16))
		return ('b');
	else if (!ft_strncmp(sect->sectname, SECT_TEXT, 16))
		return ('t');
			
		}*/
		sect = (void*)sect + sizeof(struct section_64);
		x++;
	}
	return(0);
}


char get_seg(struct nlist_64 *array, void *ptr)
{
	struct mach_header_64	*header;
	struct load_command		*lc;
	int						n_cmd;
	int							x;
	char						ret;
	struct segment_command_64	*seg;

	x = 0;
	ret = 0;
	header = (struct mach_header_64 *)ptr;
	n_cmd = header->ncmds;
	lc = ptr + sizeof(*header);
	while(x < n_cmd)
	{
		if(lc->cmd == LC_SEGMENT_64 )
		{
			seg = (struct segment_command_64*)lc;
			
			if((ret = get_sect(array, seg)) == 0)
				break;
		}
		lc += lc->cmdsize / sizeof(void *);
		x++;
	}
	if(ret == 0)
		ret = 's';
	return(ret);
}

char	get_type(struct nlist_64 *array, void *ptr)
{
	uint8_t type;
	char ret;

	type = array->n_type & N_TYPE;
	if (type == N_SECT)
		ret = get_seg(array, ptr);
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
	elem->type = get_type(array, elem->ptr);	
	elem->value = get_value(array->n_value, elem->type);
	elem->n_desc = array->n_desc;
	elem->priority = get_priority(elem->function_name);
	if(type == 64)
	{
		elem->is_64 = 1;
		elem->racine->is_64 = 1;
	}
}
