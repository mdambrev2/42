/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nm_64.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:31:49 by mdambrev          #+#    #+#             */
/*   Updated: 2018/10/08 07:57:36 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

uint64_t					swap_uint64(uint64_t n)
{
	n = ((n << 8) & 0xFF00FF00FF00FF00ULL) \
		| ((n >> 8) & 0x00FF00FF00FF00FFULL);
	n = ((n << 16) & 0xFFFF0000FFFF0000ULL) \
		| ((n >> 16) & 0x0000FFFF0000FFFFULL);
	return ((n << 32) | (n >> 32));
}

void						set_data_list_64(t_circ *ret, int nsyms,
								int symoff, int stroff)
{
	char					*stringtable;
	struct nlist_64			*array;
	int						i;
	uint8_t					check1;
	uint8_t					check2;

	array = (void*)ret->racine->ptr + symoff;
	stringtable = (void*)ret->racine->ptr + stroff;
	i = 0;
	while (i < (int)nsyms)
	{
		check1 = array[i].n_type & N_TYPE;
		check2 = array[i].n_type & N_EXT;
		while (check2 == 0 && (check1 == N_UNDF || check1 == N_PBUD))
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
	n_cmd = if_ppc_swap(header->ncmds);
	lc = ptr + sizeof(*header);
	ret->racine->ptr = ptr;
	while (x < n_cmd)
	{
		if (if_ppc_swap(lc->cmd) == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			set_data_list_64(ret, if_ppc_swap(sym->nsyms),
							if_ppc_swap(sym->symoff),
							if_ppc_swap(sym->stroff));
		}
		lc = (void*)lc + if_ppc_swap(lc->cmdsize);
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
