/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_otool_64.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:31:49 by mdambrev          #+#    #+#             */
/*   Updated: 2018/10/08 08:12:59 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

void							*put_addres_otool(void *addr)
{
	char						*str1;

	str1 = ft_convert_base_max((uintmax_t)addr, 16);
	str1 = add_octet_otool_32(str1, ft_strlen(str1), 16);
	ft_printf("%s\t", str1);
	free(str1);
	addr = addr + 16;
	return (addr);
}

void							otool_put_name_norm(char *name, int ar)
{
	if (ar == 0 || ar == 5)
		ft_printf("%s:\nContents of (__TEXT,__text) section\n", name);
	else
		ft_printf("Contents of (__TEXT,__text) section\n", name);
}

void							print_data_text(struct section_64 *sec,
										void *ptr, char *name, int ar)
{
	uint64_t					cpt;
	char						*str;
	char						*str1;
	void						*addr;

	cpt = 0;
	str = (char *)ptr + if_ppc_swap(sec->offset);
	addr = (void *)sec->addr;
	otool_put_name_norm(name, ar);
	while (cpt < if_ppc_swap(sec->size))
	{
		if (cpt % 16 == 0 || cpt == 0)
			addr = put_addres_otool(addr);
		str1 = ft_convertn_base_max(str[cpt], 16, 2);
		ft_printf("%s ", str1);
		free(str1);
		cpt++;
		if (cpt % 16 == 0 && cpt != if_ppc_swap(sec->size) && cpt != 0)
			ft_printf("\n");
	}
	if (cpt == 0)
		if_sector_empty_banners(1);
	if ((ar == 5 || ar == 0))
		ft_printf("\n");
}

void							find__text(struct segment_command_64 *seg,
											void *ptr, char *name, int ar)
{
	int							cpt;
	int							x;
	struct section_64			*sec;

	cpt = if_ppc_swap(seg->nsects);
	sec = (void*)seg + sizeof(struct segment_command_64);
	x = 0;
	while (x < cpt)
	{
		if (ft_strcmp(sec->sectname, "__text") == 0)
			print_data_text(sec, ptr, name, ar);
		sec = (void*)sec + sizeof(struct section_64);
		x++;
	}
}

t_circ							*otool_x64_bin(void *ptr, char *name, int ar)
{
	struct mach_header_64		*header;
	struct load_command			*lc;
	int							n_cmd;
	int							x;
	struct segment_command_64	*seg;

	x = 0;
	header = (struct mach_header_64 *)ptr;
	n_cmd = if_ppc_swap(header->ncmds);
	lc = ptr + sizeof(struct mach_header_64);
	while (x < n_cmd)
	{
		if (if_ppc_swap(lc->cmd) == LC_SEGMENT_64)
		{
			seg = (struct segment_command_64*)lc;
			find__text(seg, ptr, name, ar);
		}
		lc = (void *)lc + if_ppc_swap(lc->cmdsize);
		x++;
	}
	if (ar == 3 && if_sector_empty_banners(0) != 1)
		printf("\n");
	return (NULL);
}
