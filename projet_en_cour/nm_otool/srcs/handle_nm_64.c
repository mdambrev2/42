/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nm_64.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:31:49 by mdambrev          #+#    #+#             */
/*   Updated: 2019/04/01 20:01:10 by mdambrev         ###   ########.fr       */
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

int							set_data_list_64(t_circ *ret, int nsyms,
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
		if (set_info_list_order(ret, &array[i], stringtable, 64) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int							get_function_name_64(t_circ *ret, void *ptr)
{
	struct mach_header_64	*header;
	struct load_command		*lc;
	int						x;
	struct symtab_command	*sym;

	x = 0;
	header = (struct mach_header_64 *)ptr;
	lc = ptr + sizeof(*header);
	ret->racine->ptr = ptr;
	while (x < (int)if_ppc_swap(header->ncmds))
	{
		if (!check_corrup(lc, NULL))
			return (put_corrupted_files("files"));
		if (if_ppc_swap(lc->cmd) == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			if (set_data_list_64(ret, if_ppc_swap(sym->nsyms),
				if_ppc_swap(sym->symoff), if_ppc_swap(sym->stroff)) == -1)
				return (-1);
		}
		lc = (void*)lc + if_ppc_swap(lc->cmdsize);
		x++;
	}
	ret = NULL;
	return (0);
}

t_circ						*nm_x64_bin(void *ptr)
{
	t_circ					*ret;

	ret = create_circular_list();
	ret->ptr = ptr;
	if ((ret->sector = (void*)get_seg_64(ptr)) == NULL)
	{
		free_sector(ret);
		return (NULL);
	}
	if (get_function_name_64(ret, ptr) == -1)
	{
		free_sector(ret->sector);
		free_sector(ret);
		return (NULL);
	}
	free_sector(ret->sector);
	return (ret);
}
