/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nm_64.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:31:49 by mdambrev          #+#    #+#             */
/*   Updated: 2018/09/30 20:13:09 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

void						set_data_list_64(t_circ *ret, int nsyms,
								int symoff, int stroff, void *ptr)
{
	char					*stringtable;
	struct nlist_64			*array;
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
		set_info_list_order(ret, &array[i], stringtable, 64);
		i++;
		}
}

void						get_function_name_64(t_circ *ret, void *ptr)
{
	struct mach_header_64	*header;
	struct load_command		*lc;
	int						n_cmd;
	int						x;
	struct symtab_command	*sym;

	x = 0;
	header = (struct mach_header_64 *)ptr;
	n_cmd = header->ncmds;
	lc = ptr + sizeof(*header);
	while (x < n_cmd)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			set_data_list_64(ret, sym->nsyms, sym->symoff, sym->stroff, ptr);
		}
		lc = (void*)lc + lc->cmdsize;
		x++;
	}
	ret = NULL;
}

t_circ						*nm_x64_bin(void *ptr)
{
	t_circ					*ret;

	ret = create_circular_list();
	ret->ptr = ptr;
	ret->sector = (void*)get_seg_64(ptr);
	get_function_name_64(ret, ptr);
	free_sector(ret->sector);
	return (ret);
}
