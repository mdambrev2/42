/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nm_32.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:31:49 by mdambrev          #+#    #+#             */
/*   Updated: 2018/09/20 15:33:58 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>



void					set_data_list_32(t_circ *ret, int nsyms, int symoff, int stroff 
												,void *ptr)
{
	char	*stringtable;
	struct  nlist *array;
	int i;

	array = (void*)ptr + symoff;
	stringtable  = (void*)ptr + stroff;
	i = 0 ;
	while(array[i].n_type > 30)
		i++;
	while(i < (int)nsyms)
	{
		set_info_list_order(ret, &array[i], stringtable, 32);
		i++;
	}
}

void					get_function_name_32(t_circ *ret, void *ptr)
{
	struct mach_header	*header;
	struct load_command		*lc;
	int						n_cmd;
	int							x;
	struct symtab_command	*sym;


	x = 0;
	header = (struct mach_header *)ptr;
	n_cmd = header->ncmds;
	lc = ptr + sizeof(*header);	
	while(x < n_cmd)
	{
		if(lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			set_data_list_32(ret, sym->nsyms, sym->symoff, sym->stroff, ptr);
		}
		lc = (void*)lc + lc->cmdsize;
		x++;
	}
	ret = NULL;
}

t_circ					*nm_x32_bin(void *ptr)
{
	t_circ *ret;
	
	ret = create_circular_list();
	ret->ptr = ptr;
	get_function_name_32(ret, ptr);
	ret = ret->racine->next;
//	get_symbol_type(ret);
//	get_value(ret);
	return(ret);
}

