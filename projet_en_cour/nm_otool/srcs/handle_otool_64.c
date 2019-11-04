/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_otool_64.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:31:49 by mdambrev          #+#    #+#             */
/*   Updated: 2019/04/04 19:27:11 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

void								arm_otool(uint64_t cpt, uint64_t *addr,
												char *str)
{
	char							*str1;
	static	char					ret[9];
	static	int						x = 0;

	str1 = NULL;
	ret[8] = '0';
	if (cpt % 16 == 0 || cpt == 0)
		*addr = put_addres_otool(*addr);
	str1 = ft_convertn_base_max(str[cpt], 16, 2);
	ret[x] = str1[0];
	ret[x + 1] = str1[1];
	x += 2;
	if ((cpt + 1) % 4 == 0)
	{
		x = 7;
		while (x >= 0)
		{
			ft_putchar(ret[x - 1]);
			ft_putchar(ret[x]);
			x -= 2;
		}
		ft_printf(" ", ret);
		x = 0;
	}
	free(str1);
}

void								select_ppc_or_x64(uint64_t cpt,
								uint64_t *addr, char *str)
{
	char *str1;

	str1 = NULL;
	if (static_banner_ppc(0) == 0)
	{
		if (cpt % 16 == 0 || cpt == 0)
			*addr = put_addres_otool(*addr);
		str1 = ft_convertn_base_max(str[cpt], 16, 2);
		ft_printf("%s ", str1);
		free(str1);
	}
	if (static_banner_ppc(0) == 32)
	{
		if (cpt % 16 == 0 || cpt == 0)
			*addr = put_addres_otool(*addr);
		str1 = ft_convertn_base_max(str[cpt], 16, 2);
		ft_printf("%s", str1);
		if ((cpt + 1) % 4 == 0)
			ft_printf(" ", cpt);
		free(str1);
	}
	if (static_banner_ppc(0) == 128)
		arm_otool(cpt, addr, str);
}

void								print_data_text(struct section_64 *sec,
										void *ptr, char *name, int ar)
{
	uint64_t						cpt;
	char							*str;
	uint64_t						addr;

	cpt = 0;
	str = (char *)ptr + if_ppc_swap(sec->offset);
	addr = sec->addr;
	otool_put_name_norm(name, ar);
	while (cpt < if_ppc_swap(sec->size))
	{
		select_ppc_or_x64(cpt, &addr, str);
		cpt++;
		if (cpt % 16 == 0 && cpt != if_ppc_swap(sec->size) && cpt != 0)
			ft_printf("\n");
	}
	if (cpt == 0)
		if_sector_empty_banners(1);
	if ((ar == 5 || ar == 0))
		ft_printf("\n");
}

void								find__text(struct segment_command_64 *seg,
											void *ptr, char *name, int ar)
{
	int								cpt;
	int								x;
	struct section_64				*sec;

	if ((!check_corrup(seg, NULL))
			&& put_corrupted_files("files"))
		return ;
	cpt = if_ppc_swap(seg->nsects);
	sec = (void*)seg + sizeof(struct segment_command_64);
	x = 0;
	while (x < cpt)
	{
		if ((!check_corrup(sec, NULL))
				&& put_corrupted_files("files"))
			return ;
		if (ft_strcmp(sec->sectname, "__text") == 0)
			print_data_text(sec, ptr, name, ar);
		sec = (void*)sec + sizeof(struct section_64);
		x++;
	}
}

t_circ								*otool_x64_bin(void *ptr,
													char *name, int ar)
{
	struct mach_header_64			*header;
	struct load_command				*lc;
	int								n_cmd;
	int								x;
	struct segment_command_64		*seg;

	x = 0;
	header = (struct mach_header_64 *)ptr;
	n_cmd = if_ppc_swap(header->ncmds);
	lc = ptr + sizeof(struct mach_header_64);
	while (x++ < n_cmd)
	{
		if ((!check_corrup(lc, NULL)) && put_corrupted_files("files"))
			return (NULL);
		if (if_ppc_swap(lc->cmd) == LC_SEGMENT_64)
		{
			seg = (struct segment_command_64*)lc;
			find__text(seg, ptr, name, ar);
		}
		lc = (void *)lc + if_ppc_swap(lc->cmdsize);
	}
	if (ar == 3 && if_sector_empty_banners(0) != 1)
		ft_printf("\n");
	return (NULL);
}
