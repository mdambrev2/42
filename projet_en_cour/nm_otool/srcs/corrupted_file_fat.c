/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corrupted_file_fat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 15:31:56 by mdambrev          #+#    #+#             */
/*   Updated: 2018/09/13 13:41:06 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

int					if_equal_fat(void *ptr, off_t offset_end, struct stat *buf)
{
	void				 	*data_end;
	void					*fat_end;

	data_end = ptr + buf->st_size;
	fat_end = ptr + offset_end ;
	if(fat_end != data_end)
		return(0);
	return(1);
}


uint32_t	swap_uint32_f(uint32_t val)
{
		val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
			return (val << 16) | (val >> 16);
}


int			check_fat_corrupt(void *ptr, struct stat *buf, char *str)
{
	struct	fat_header	*header_fat;
	struct	fat_arch	*header_bin;
	uint32_t 			x;
	off_t				offset;

	header_fat = (struct  fat_header *)ptr;
	header_bin = (struct  fat_arch *)(ptr + sizeof(struct fat_header));

	x = 0;
	offset = sizeof(struct fat_header);
	while(x < swap_uint32_f(header_fat->nfat_arch))
	{
		if(swap_uint32_f(header_bin->cputype) == CPU_TYPE_X86_64)
		{
			offset  = swap_uint32_f(header_bin->offset);
			offset += swap_uint32_f(header_bin->size);	
			if_equal_fat(ptr, offset, buf);
		}
		header_bin = (void*)header_bin + sizeof(struct  fat_arch); 
		x++;
	}
	if(if_equal_fat(ptr, offset, buf) == 0)
	{
		put_corrupted_files(str);
		return(1);
	}
	return(0);
}
