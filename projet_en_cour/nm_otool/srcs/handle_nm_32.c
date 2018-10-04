/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nm_32.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:31:49 by mdambrev          #+#    #+#             */
/*   Updated: 2018/10/04 15:59:00 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

void						set_data_list_32(t_circ *ret, int nsyms,
		int symoff, int stroff, void *ptr)
{
	char					*stringtable;
	struct nlist			*array;
	int						i;
	uint8_t					check1;
	uint8_t					check2;


	array = (void*)ptr + symoff;
	stringtable = (void*)ptr + stroff;
	i = 0;
	while (i < (int)nsyms)
	{
		check1 = array[i].n_type & N_TYPE;
		check2 = array[i].n_type & N_EXT;
		while(check2 == 0 && (check1 == N_UNDF || check1 == N_PBUD))
		{
			i++;
			check1 = array[i].n_type & N_TYPE;
			check2 = array[i].n_type & N_EXT;
		}
		set_info_list_order(ret, &array[i], stringtable, 32);
		i++;
	}

}

void						get_function_name_32(t_circ *ret, void *ptr)
{
	struct mach_header		*header;
	struct load_command		*lc;
	int						n_cmd;
	int						x;
	struct symtab_command	*sym;

	x = 0;
	header = (struct mach_header *)ptr;
	n_cmd = if_ppc_swap(header->ncmds);
	lc = ptr + sizeof(*header);
	while (x < n_cmd)
	{
		if (if_ppc_swap(lc->cmd) == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			set_data_list_32(ret, if_ppc_swap(sym->nsyms), 
					if_ppc_swap(sym->symoff), if_ppc_swap(sym->stroff), ptr);
		}
		lc = (void*)lc + if_ppc_swap(lc->cmdsize);
		x++;
	}
	ret = NULL;
}

t_circ						*nm_x32_bin(void *ptr)
{
	t_circ					*ret;

	ret = create_circular_list();
	ret->ptr = ptr;
	ret->sector = (void*)get_seg_32(ptr);
	get_function_name_32(ret, ptr);
	free_sector(ret->sector);
	return (ret);
}
