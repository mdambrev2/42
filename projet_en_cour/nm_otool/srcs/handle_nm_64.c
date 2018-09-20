/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nm_64.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:31:49 by mdambrev          #+#    #+#             */
/*   Updated: 2018/09/19 12:59:27 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>



void					set_data_list_64(t_circ *ret, int nsyms, int symoff, int stroff 
												,void *ptr)
{
	char	*stringtable;
	struct  nlist_64 *array;
	int i;

	array = (void*)ptr + symoff;
	stringtable  = (void*)ptr + stroff;
	i = 0 ;
	while(array[i].n_type > 15)
		i++;
	while(i < (int)nsyms)
	{
		set_info_list_order(ret, &array[i], stringtable, 64);
		i++;
	}
}

void					get_function_name_64(t_circ *ret, void *ptr)
{
	struct mach_header_64	*header;
	struct load_command		*lc;
	int						n_cmd;
	int							x;
	struct symtab_command	*sym;


	x = 0;
	header = (struct mach_header_64 *)ptr;
	n_cmd = header->ncmds;
	lc = ptr + sizeof(*header);	
	while(x < n_cmd)
	{
		if(lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			set_data_list_64(ret, sym->nsyms, sym->symoff, sym->stroff, ptr);
		}
		lc = (void*)lc + lc->cmdsize;
		x++;
	}
	ret = NULL;
}

t_circ					*nm_x64_bin(void *ptr)
{
	t_circ *ret;

	ret = create_circular_list();
	ret->ptr = ptr;
	get_function_name_64(ret, ptr);
	ret = ret->racine->next;
	return(ret);
}
