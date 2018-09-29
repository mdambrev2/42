/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_segment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:59:07 by mdambrev          #+#    #+#             */
/*   Updated: 2018/09/29 16:00:02 by mdambrev         ###   ########.fr       */
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
	while (x < seg->nsects)
	{
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
	struct segment_command_64	*seg;
	t_circ						*sector;

	x = 0;
	sector = create_circular_list();
	header = (struct mach_header_64 *)ptr;
	lc = ptr + sizeof(*header);
	while (x < header->ncmds)
	{
		if (lc->cmd == LC_SEGMENT_64)
		{
			seg = (struct segment_command_64*)lc;
			sector = get_sect_64(seg, sector);
		}
		lc = (void*)lc + lc->cmdsize;
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
	while (x < seg->nsects)
	{
		tmp = addfin_circ_elem(tmp);
		tmp->sector_name = ft_strdup(sect->sectname);
		sect = (void*)sect + sizeof(struct section);
		x++;
	}
	return (tmp);
}

t_circ							*get_seg_32(void *ptr)
{
	struct mach_header			*header;
	struct load_command			*lc;
	uint32_t					x;
	struct segment_command		*seg;
	t_circ						*sector;

	x = 0;
	sector = create_circular_list();
	header = (struct mach_header *)ptr;
	lc = ptr + sizeof(*header);
	while (x < header->ncmds)
	{
		if (lc->cmd == LC_SEGMENT)
		{
			seg = (struct segment_command*)lc;
			sector = get_sect_32(seg, sector);
		}
		lc = (void*)lc + lc->cmdsize;
		x++;
	}
	return (sector);
}
