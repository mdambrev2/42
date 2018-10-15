/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nm_fat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:01:08 by mdambrev          #+#    #+#             */
/*   Updated: 2018/10/08 07:48:59 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

void					print_architecture_otool(char *name,
				struct fat_arch *header_bin, struct fat_header *header_fat)
{
	if (swap_uint32(header_fat->nfat_arch) == 1)
		ft_printf("%s:\n", name);
	if (swap_uint32(header_bin->cputype) == CPU_TYPE_POWERPC)
	{
		if (swap_uint32(header_fat->nfat_arch) > 1)
			ft_printf("%s (architecture ppc):\n", name);
		static_banner_ppc(32);
	}
	if (swap_uint32(header_bin->cputype) == CPU_TYPE_I386)
	{
		if (swap_uint32(header_fat->nfat_arch) > 1)
			ft_printf("%s (architecture i386):\n", name);
	}
	if (swap_uint32(header_bin->cputype) == CPU_TYPE_POWERPC64)
	{
		static_banner_ppc(64);
		if (swap_uint32(header_fat->nfat_arch) > 1)
			ft_printf("%s (architecture ppc64):\n", name);
	}
}

void					get_otool_norm(void **norm,
		struct fat_header *header_fat, struct stat *buf,
		struct fat_arch *header_bin)
{
	if (swap_uint32(header_bin->cputype) == CPU_TYPE_POWERPC)
	{
		print_architecture_otool((norm[0]), header_bin, header_fat);
		otool(norm[1] + swap_uint32(header_bin->offset), norm[0], 2, buf);
	}
	if (swap_uint32(header_bin->cputype) == CPU_TYPE_I386)
	{
		print_architecture_otool(norm[0], header_bin, header_fat);
		otool(norm[1] + swap_uint32(header_bin->offset), norm[0], 2, buf);
	}
	if (swap_uint32(header_bin->cputype) == CPU_TYPE_POWERPC64)
	{
		print_architecture_otool(norm[0], header_bin, header_fat);
		otool(norm[1] + swap_uint32(header_bin->offset), norm[0], 2, buf);
	}
}

void					get_all_architecture_otool(void *ptr, void *name,
		struct fat_header *header_fat, struct stat *buf)
{
	struct fat_arch		*header_bin;
	uint32_t			x;
	void				*norm[2];

	header_bin = (struct fat_arch *)(ptr + sizeof(struct fat_header));
	x = -1;
	norm[0] = name;
	norm[1] = ptr;
	while (++x < swap_uint32(header_fat->nfat_arch))
	{
		if (x != 0)
			ft_printf("\n");
		get_otool_norm(norm, header_fat, buf, header_bin);
		static_banner_ppc(-1);
		header_bin = (void*)header_bin + sizeof(struct fat_arch);
	}
	ft_printf("\n");
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
			if (*(uint64_t *)(ptr + swap_uint32(header_bin->offset)) != AR_MAGIC
			&& *(uint64_t *)(ptr + swap_uint32(header_bin->offset)) != AR_CIGAM)
				ft_printf("%s:\n", name);
			otool(ptr + swap_uint32(header_bin->offset), name, 3, buf);
			return ;
		}
		header_bin = (void*)header_bin + sizeof(struct fat_arch);
		x++;
	}
	get_all_architecture_otool(ptr, name, header_fat, buf);
}
