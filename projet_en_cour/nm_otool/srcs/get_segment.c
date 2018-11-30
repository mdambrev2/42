/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_segment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:59:07 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/30 11:07:15 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

t_circ							*get_sect_64(struct segment_command_64 *seg,
												t_circ *sector)
{
	uint64_t					x;
	struct section_64			*sect;
	t_circ						*tmp;

	sect = (void*)seg + sizeof(struct segment_command_64);
	x = 0;
	sector = sector->racine;
	tmp = sector;
	if ((!check_corrup(seg, NULL) || !check_corrup(sect->sectname, NULL))
				&& put_corrupted_files("files"))
		return (NULL);
	while (x < if_ppc_swap(seg->nsects))
	{
		if ((!check_corrup(seg, NULL) || !check_corrup(sect->sectname, NULL))
				&& put_corrupted_files("files") && free_sector(sector))
			return (NULL);
		tmp = addfin_circ_elem(tmp);
		tmp->sector_name = ft_strdup(sect->sectname);
		sect = (void*)sect + sizeof(struct section_64);
		x++;
	}
	return (tmp);
}

t_circ							*get_seg_64(void *ptr)
{
	struct mach_header_64		*header;
	struct load_command			*lc;
	uint32_t					x;
	t_circ						*sector;
	uint64_t					x_max;

	x = 0;
	sector = create_circular_list();
	header = (struct mach_header_64 *)ptr;
	lc = ptr + sizeof(*header);
	x_max = if_ppc_swap(header->ncmds);
	while (x < x_max)
	{
		if (!check_corrup(lc, NULL))
		{
			put_corrupted_files("files");
			return (NULL);
		}
		if (if_ppc_swap(lc->cmd) == LC_SEGMENT_64)
			sector = get_sect_64((struct segment_command_64*)lc, sector);
		lc = (void*)lc + if_ppc_swap(lc->cmdsize);
		x++;
	}
	return (sector);
}

t_circ							*get_sect_32(struct segment_command *seg,
												t_circ *sector)
{
	uint64_t					x;
	struct section				*sect;
	t_circ						*tmp;

	sect = (void*)seg + sizeof(struct segment_command);
	x = 0;
	sector = sector->racine;
	tmp = sector;
	if ((!check_corrup(seg, NULL) || !check_corrup(sect->sectname, NULL))
				&& put_corrupted_files("files"))
		return (NULL);
	while (x < if_ppc_swap(seg->nsects))
	{
		if ((!check_corrup(seg, NULL) || !check_corrup(sect->sectname, NULL))
				&& put_corrupted_files("files") && free_sector(sector->racine))
			return (NULL);
		tmp = addfin_circ_elem(tmp);
		tmp->sector_name = ft_strdup(sect->sectname);
		sect = (void*)sect + sizeof(struct section);
		x++;
	}
	tmp = tmp->racine->next;
	return (tmp);
}

t_circ							*get_seg_32(void *ptr)
{
	struct mach_header			*header;
	struct load_command			*lc;
	uint32_t					x;
	t_circ						*sector;
	uint32_t					x_max;

	x = 0;
	sector = create_circular_list();
	header = (struct mach_header *)ptr;
	lc = ptr + sizeof(*header);
	x_max = if_ppc_swap(header->ncmds);
	while (x < x_max)
	{
		if (!check_corrup(lc, NULL))
		{
			put_corrupted_files("files");
			return (NULL);
		}
		if (if_ppc_swap(lc->cmd) == LC_SEGMENT)
			sector = get_sect_32((struct segment_command*)lc, sector);
		lc = (void*)lc + if_ppc_swap(lc->cmdsize);
		x++;
	}
	return (sector);
}
