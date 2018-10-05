/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nm_fat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:01:08 by mdambrev          #+#    #+#             */
/*   Updated: 2018/10/05 20:02:57 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

uint64_t	if_ppc_swap(uint64_t value)
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

void					print_architecture(char *name, struct fat_arch *header_bin,
											struct fat_header   *header_fat)
{
	if(swap_uint32(header_fat->nfat_arch) == 1)
			ft_printf("%s:\n", name);
	if(swap_uint32(header_bin->cputype) == CPU_TYPE_POWERPC)
	{
		if(swap_uint32(header_fat->nfat_arch) > 1)
			ft_printf("\n%s (for architecture ppc):\n", name);
		static_banner_ppc(32);
	}
	if (swap_uint32(header_bin->cputype) == CPU_TYPE_I386)
	{
		if(swap_uint32(header_fat->nfat_arch) > 1)
			ft_printf("\n%s (for architecture i386):\n", name);
	}
	if (swap_uint32(header_bin->cputype) == CPU_TYPE_POWERPC64)
	{
		static_banner_ppc(64);
		if(swap_uint32(header_fat->nfat_arch) > 1)
			ft_printf("\n%s (for architecture ppc64):\n", name);	
	}
}

void					print_architecture_otool(char *name, struct fat_arch *header_bin,
											struct fat_header   *header_fat)
{
	if(swap_uint32(header_fat->nfat_arch) == 1)
			ft_printf("%s:\n", name);
	if(swap_uint32(header_bin->cputype) == CPU_TYPE_POWERPC)
	{
		if(swap_uint32(header_fat->nfat_arch) > 1)
			ft_printf("%s (architecture ppc):\n", name);
		static_banner_ppc(32);
	}
	if (swap_uint32(header_bin->cputype) == CPU_TYPE_I386)
	{
		if(swap_uint32(header_fat->nfat_arch) > 1)
			ft_printf("%s (architecture i386):\n", name);
	}
	if (swap_uint32(header_bin->cputype) == CPU_TYPE_POWERPC64)
	{
		static_banner_ppc(64);
		if(swap_uint32(header_fat->nfat_arch) > 1)
			ft_printf("%s (architecture ppc64):\n", name);	
	}
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
			print_architecture(name, header_bin, header_fat);
			nm(ptr + swap_uint32(header_bin->offset), name, ac, buf);
		}
		else if (swap_uint32(header_bin->cputype) == CPU_TYPE_I386)
		{
			print_architecture(name, header_bin, header_fat);	
			nm(ptr + swap_uint32(header_bin->offset), name, ac, buf);
		}
		else if (swap_uint32(header_bin->cputype) == CPU_TYPE_POWERPC64)
		{
			print_architecture(name, header_bin, header_fat);
			nm(ptr + swap_uint32(header_bin->offset), name, ac, buf);
		}
		static_banner_ppc(-1);
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
		if(x != 0)
			ft_printf("\n");
		if (swap_uint32(header_bin->cputype) == CPU_TYPE_POWERPC)
		{	
			print_architecture_otool(name, header_bin, header_fat);
			otool(ptr + swap_uint32(header_bin->offset), name, ac, buf);
		}
		if (swap_uint32(header_bin->cputype) == CPU_TYPE_I386)
		{
			print_architecture_otool(name, header_bin, header_fat);
			otool(ptr + swap_uint32(header_bin->offset), name, ac, buf);
		}
		if (swap_uint32(header_bin->cputype) == CPU_TYPE_POWERPC64)
		{
			print_architecture_otool(name, header_bin, header_fat);
			otool(ptr + swap_uint32(header_bin->offset), name, ac, buf);
		}
		static_banner_ppc(-1);
		header_bin = (void*)header_bin + sizeof(struct fat_arch);
		x++;
	}
	ft_printf("\n");
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
