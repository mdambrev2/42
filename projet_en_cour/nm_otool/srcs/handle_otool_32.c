/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_otool_32.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:31:49 by mdambrev          #+#    #+#             */
/*   Updated: 2018/10/04 21:45:06 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

char								*add_octet_otool_32(char *str,
													int strlen, int n_ret)
{
	int								n_octet;
	char							*ret;
	int								cpt;
	int								i;

	cpt = 0;
	n_octet = n_ret - strlen;
	ret = ft_strnew(n_ret + 1);
	i = 0;
	while (cpt < n_octet)
	{
		ret[cpt] = '0';
		cpt++;
	}
	while (str[i])
	{
		ret[cpt] = str[i];
		cpt++;
		i++;
	}
	free(str);
	return (ret);
}

uint32_t							put_addres_otool_32(uint32_t addr)
{
	char							*str1;

	str1 = ft_convert_base_max((uint64_t)addr, 16);
	str1 = add_octet_otool_32(str1, ft_strlen(str1), 8);
	ft_printf("%s\t", str1);
	free(str1);
	addr = addr + 16;
	return (addr);
}

void								print_data_text_32(struct section *sec,
												void *ptr, char *name, int ar)
{
	uint64_t						cpt;
	char							*str;
	char							*str1;
	uint32_t						addr;

	cpt = 0;
	str = (char *)ptr + if_ppc_swap(sec->offset);
	addr = if_ppc_swap(sec->addr);
	if (ar == 0 || ar == 5)
		ft_printf("%s:\nContents of (__TEXT,__text) section\n", name);
	else
		ft_printf("Contents of (__TEXT,__text) section\n", name);
	while (cpt < if_ppc_swap(sec->size))
	{
		if (cpt % 16 == 0 || cpt == 0)
			addr = put_addres_otool_32(addr);
		str1 = ft_convertn_base_max(str[cpt], 16, 2);
		ft_printf("%s ", str1);
		free(str1);
		cpt++;
		if (cpt % 16 == 0 && cpt != if_ppc_swap(sec->size))
			ft_printf("\n");
	}
	if (ar == 0 || ar == 5)
		ft_printf("\n");
}

void								find_text_32(struct segment_command *seg,
											void *ptr, char *name, int ar)
{
	int								cpt;
	int								x;
	struct section					*sec;

	cpt = if_ppc_swap(seg->nsects);
	sec = (void*)seg + sizeof(struct segment_command);
	x = 0;
	while (x < cpt)
	{
		if (ft_strcmp(sec->sectname, "__text") == 0)
		{
			print_data_text_32(sec, ptr, name, ar);
		}
		sec = (void*)sec + sizeof(struct section);
		x++;
	}
}

t_circ								*otool_x32_bin(void *ptr,
													char *name, int ar)
{
	struct mach_header				*header;
	struct load_command				*lc;
	int								n_cmd;
	int								x;
	struct segment_command			*seg;

	x = 0;
	header = (struct mach_header *)ptr;
	n_cmd = if_ppc_swap(header->ncmds);
	lc = ptr + sizeof(struct mach_header);
	while (x < n_cmd)
	{
		if (if_ppc_swap(lc->cmd) == LC_SEGMENT)
		{
			seg = (struct segment_command*)lc;
			find_text_32(seg, ptr, name, ar);
		}
		lc = (void *)lc + if_ppc_swap(lc->cmdsize);
		x++;
	}
	return (NULL);
}
