/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nm_fat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:01:08 by mdambrev          #+#    #+#             */
/*   Updated: 2019/04/04 18:22:30 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

void					print_arm_architecture(char *name,
				struct fat_arch *header_bin, struct fat_header *header_fat)
{
	if (swap_uint32(header_bin->cputype) == CPU_TYPE_ARM)
	{
		if (swap_uint32(header_fat->nfat_arch) > 1
				&& swap_uint32(header_bin->cpusubtype) == CPU_SUBTYPE_ARM_V7S)
			ft_printf("\n%s (for architecture armv7s):\n", name);
		if (swap_uint32(header_fat->nfat_arch) > 1
				&& swap_uint32(header_bin->cpusubtype) == CPU_SUBTYPE_ARM_V7)
			ft_printf("\n%s (for architecture armv7):\n", name);
	}
	else if (swap_uint32(header_bin->cputype) == CPU_TYPE_ARM64)
	{
		if (swap_uint32(header_fat->nfat_arch) > 1)
			ft_printf("\n%s (for architecture arm64):\n", name);
	}
}

void					print_architecture(char *name,
				struct fat_arch *header_bin, struct fat_header *header_fat)
{
	if (swap_uint32(header_fat->nfat_arch) == 1)
		ft_printf("%s:\n", name);
	if (swap_uint32(header_bin->cputype) == CPU_TYPE_POWERPC)
	{
		if (swap_uint32(header_fat->nfat_arch) > 1)
			ft_printf("\n%s (for architecture ppc):\n", name);
		static_banner_ppc(32);
	}
	if (swap_uint32(header_bin->cputype) == CPU_TYPE_I386)
	{
		if (swap_uint32(header_fat->nfat_arch) > 1)
			ft_printf("\n%s (for architecture i386):\n", name);
	}
	if (swap_uint32(header_bin->cputype) == CPU_TYPE_POWERPC64)
	{
		static_banner_ppc(64);
		if (swap_uint32(header_fat->nfat_arch) > 1)
			ft_printf("\n%s (for architecture ppc64):\n", name);
	}
	if (swap_uint32(header_bin->cputype) == CPU_TYPE_ARM
			|| swap_uint32(header_bin->cputype) == CPU_TYPE_ARM64)
		print_arm_architecture(name, header_bin, header_fat);
}

void					get_all_architecture(void *ptr, void *name,
						struct fat_header *header_fat, struct stat *buf)
{
	struct fat_arch		*header_bin;
	uint32_t			x;

	header_bin = (struct fat_arch *)(ptr + sizeof(struct fat_header));
	x = 0;
	while (x++ < swap_uint32(header_fat->nfat_arch))
	{
		if (swap_uint32(header_bin->cputype) == CPU_TYPE_POWERPC
				|| swap_uint32(header_bin->cputype) == CPU_TYPE_ARM
					|| swap_uint32(header_bin->cputype) == CPU_TYPE_ARM64)
		{
			print_architecture(name, header_bin, header_fat);
			nm(ptr + swap_uint32(header_bin->offset), name, 2, buf);
		}
		else if (swap_uint32(header_bin->cputype) == CPU_TYPE_I386
				|| swap_uint32(header_bin->cputype) == CPU_TYPE_POWERPC64)
		{
			print_architecture(name, header_bin, header_fat);
			nm(ptr + swap_uint32(header_bin->offset), name, 2, buf);
		}
		static_banner_ppc(-1);
		header_bin = (void*)header_bin + sizeof(struct fat_arch);
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
	get_all_architecture(ptr, name, header_fat, buf);
}
