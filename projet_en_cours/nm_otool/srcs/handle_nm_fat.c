/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nm_fat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:01:08 by mdambrev          #+#    #+#             */
/*   Updated: 2018/09/11 17:48:59 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

uint32_t	swap_uint32(uint32_t val)
{
		val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
			return (val << 16) | (val >> 16);
}

void	unzip_fat(void *ptr, void *name, int ac, struct stat *buf)
{
	
	struct	fat_header	*header_fat;
	struct	fat_arch	*header_bin;
	uint32_t 			x;

	header_fat = (struct  fat_header *)ptr;
	header_bin = (struct  fat_arch *)(ptr + sizeof(struct fat_header));

	x = 0;
	while(x < swap_uint32(header_fat->nfat_arch))
	{
		if(swap_uint32(header_bin->cputype) == CPU_TYPE_X86_64)
		{
			nm(ptr + swap_uint32(header_bin->offset), name, ac, buf);
			break;
		}
		header_bin = (void*)header_bin + sizeof(struct  fat_arch); 
		x++;
	}
}

void	unzip_fat_otool(void *ptr, void *name, int ac)
{
	
	struct	fat_header	*header_fat;
	struct	fat_arch	*header_bin;
	uint32_t 			x;

	header_fat = (struct  fat_header *)ptr;
	header_bin = (struct  fat_arch *)(ptr + sizeof(struct fat_header));

	x = 0;
	ft_printf("%s:\n", name);
	while(x < swap_uint32(header_fat->nfat_arch))
	{
		if(swap_uint32(header_bin->cputype) == CPU_TYPE_X86_64)
		{
			otool(ptr + swap_uint32(header_bin->offset), name, ac, 1);
			break;
		}
		header_bin = (void*)header_bin + sizeof(struct  fat_arch); 
		x++;
	}
	printf("\n");
}

