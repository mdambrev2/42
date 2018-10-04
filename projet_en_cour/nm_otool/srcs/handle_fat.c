/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nm_fat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:01:08 by mdambrev          #+#    #+#             */
/*   Updated: 2018/10/04 21:20:54 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

uint32_t	if_ppc_swap(uint32_t value)
{
	if(static_banner_ppc(0) == 32)
		return(swap_uint32(value));
	else if(static_banner_ppc(0) == 64)
		return(swap_uint64(value));
	else
		return(value);
}

int			static_banner_ppc(int modifier)
{
	static int		x = 0;

	if(modifier == 32)
		x = 32;
	if(modifier == 64)
		x = 64;
	if(modifier == -1)
		x = 0;
	return(x);
}

uint32_t				swap_uint32(uint32_t val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return (val << 16) | (val >> 16);
}

void					get_all_architecture(void *ptr, void *name, int ac,
													struct stat *buf)
{
	struct fat_header	*header_fat;
	struct fat_arch		*header_bin;
	uint32_t			x;

	header_fat = (struct fat_header *)ptr;
	header_bin = (struct fat_arch *)(ptr + sizeof(struct fat_header));
	x = 0;
	ac = 2;
	while (x < swap_uint32(header_fat->nfat_arch))
	{
		if (swap_uint32(header_bin->cputype) == CPU_TYPE_POWERPC)
		{
			ft_printf("\n%s (for architecture ppc):\n", name);
			static_banner_ppc(32);
			nm(ptr + swap_uint32(header_bin->offset), name, ac, buf);
			static_banner_ppc(-1);
		}
		if (swap_uint32(header_bin->cputype) == CPU_TYPE_I386)
		{
			ft_printf("\n%s (for architecture i386):\n", name);
			nm(ptr + swap_uint32(header_bin->offset), name, ac, buf);
		}
		if (swap_uint32(header_bin->cputype) == CPU_TYPE_POWERPC64)
		{
			static_banner_ppc(64);
			ft_printf("\n%s (for architecture i386):\n", name);
			nm(ptr + swap_uint32(header_bin->offset), name, ac, buf);
			static_banner_ppc(-1);
		}
		header_bin = (void*)header_bin + sizeof(struct fat_arch);
		x++;
	}
}

void					get_all_architecture_otool(void *ptr, void *name, int ac,
													struct stat *buf)
{
	struct fat_header	*header_fat;
	struct fat_arch		*header_bin;
	uint32_t			x;

	header_fat = (struct fat_header *)ptr;
	header_bin = (struct fat_arch *)(ptr + sizeof(struct fat_header));
	x = 0;
	ac = 2;
	while (x < swap_uint32(header_fat->nfat_arch))
	{
		if (swap_uint32(header_bin->cputype) == CPU_TYPE_POWERPC)
		{
			ft_printf("\n%s (for architecture ppc):\n", name);
			static_banner_ppc(32);
			otool(ptr + swap_uint32(header_bin->offset), name, ac, buf);
			static_banner_ppc(-1);
		}
		if (swap_uint32(header_bin->cputype) == CPU_TYPE_I386)
		{
			ft_printf("\n%s (for architecture i386):\n", name);
			otool(ptr + swap_uint32(header_bin->offset), name, ac, buf);
		}
		if (swap_uint32(header_bin->cputype) == CPU_TYPE_POWERPC64)
		{
			static_banner_ppc(64);
			ft_printf("\n%s (for architecture ppc64):\n", name);
			otool(ptr + swap_uint32(header_bin->offset), name, ac, buf);
			static_banner_ppc(-1);
		}
		header_bin = (void*)header_bin + sizeof(struct fat_arch);
		x++;
	}
}


void					unzip_fat(void *ptr, void *name, int ac,
											struct stat *buf)
{
	struct fat_header	*header_fat;
	struct fat_arch		*header_bin;
	uint32_t			x;

	header_fat = (struct fat_header *)ptr;
	header_bin = (struct fat_arch *)(ptr + sizeof(struct fat_header));
	x = 0;
	ac = 2;
	while (x < swap_uint32(header_fat->nfat_arch))
	{
		if (swap_uint32(header_bin->cputype) == CPU_TYPE_X86_64)
		{
			nm(ptr + swap_uint32(header_bin->offset), name, ac, buf);
			return ;
		}
		header_bin = (void*)header_bin + sizeof(struct fat_arch);
		x++;
	}
	get_all_architecture(ptr, name, ac, buf);
}

void					unzip_fat_otool(void *ptr, void *name,
										int ac, struct stat *buf)
{
	struct fat_header	*header_fat;
	struct fat_arch		*header_bin;
	uint32_t			x;

	header_fat = (struct fat_header *)ptr;
	header_bin = (struct fat_arch *)(ptr + sizeof(struct fat_header));
	x = 0;
	ac = 1;
	while (x < swap_uint32(header_fat->nfat_arch))
	{
		if (swap_uint32(header_bin->cputype) == CPU_TYPE_X86_64)
		{
			if(*(uint64_t *)(ptr + swap_uint32(header_bin->offset)) != AR_MAGIC
				&& *(uint64_t *)(ptr + swap_uint32(header_bin->offset)) != AR_CIGAM)
					ft_printf("%s:\n", name);
			otool(ptr + swap_uint32(header_bin->offset), name, 3, buf);
			return;
		}
		header_bin = (void*)header_bin + sizeof(struct fat_arch);
		x++;
	}
	get_all_architecture_otool(ptr, name, ac, buf);
}
