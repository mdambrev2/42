/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_otool_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:25:51 by mdambrev          #+#    #+#             */
/*   Updated: 2019/04/09 16:57:43 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

int						nm_arch(void *ptr, char *str, int ac, struct stat *buf)
{
	unsigned int		magic_number;

	magic_number = *(int *)ptr;
	if (magic_number == FAT_MAGIC || magic_number == FAT_CIGAM)
	{
		if (check_fat_corrupt(ptr, buf, str) == 1)
			return (-1);
		unzip_fat(ptr, str, ac, buf);
		return (0);
	}
	else if ((*(uint64_t *)ptr) == AR_MAGIC || (*(uint64_t *)ptr) == AR_CIGAM)
	{
		if (ac != 2 && check_ar_corrupt(ptr, buf, str) == 1)
			return (-1);
		unzip_ar(ptr, str, ac, buf);
		return (0);
	}
	else
		return (put_type_error(str));
}

int						nm(void *ptr, char *str, int ac, struct stat *buf)
{
	unsigned int		magic_number;
	t_circ				*to_put;
printf("bob\n");

	magic_number = *(int *)ptr;
	to_put = NULL;
	printf("bob\n");

	get_name(1, str);
	set_ppc_type(str, ptr, ac);
	
	printf("bob\n");
	if (magic_number == MH_MAGIC_64 || magic_number == MH_CIGAM_64)
	{
		if ((ac != 2 && check_x32_x64_corrupt(ptr, buf, str, 1) == 1)
				|| (to_put = nm_x64_bin(ptr)) == NULL)
			return (-1);
		put_list(to_put, str, ac);
		return (0);
	}
	else if (magic_number == MH_MAGIC || magic_number == MH_CIGAM)
	{
		if (ac != 2 && check_x32_x64_corrupt(ptr, buf, str, 2) == 1)
			return (-1);
		if ((to_put = nm_x32_bin(ptr)) == NULL)
			return (-1);
		put_list(to_put, str, ac);
		return (0);
	}
	return (nm_arch(ptr, str, ac, buf));
}

int						otool_arch(void *ptr, char *str,
									int ac, struct stat *buf)
{
	unsigned int		magic_number;

	magic_number = *(int *)ptr;
	if (magic_number == FAT_MAGIC || magic_number == FAT_CIGAM)
	{
		if (check_fat_corrupt(ptr, buf, str) == 1)
			return (-1);
		unzip_fat_otool(ptr, str, ac, buf);
	}
	else if ((*(uint64_t *)ptr) == AR_MAGIC || (*(uint64_t *)ptr) == AR_CIGAM)
	{
		if (ac != 3 && check_ar_corrupt(ptr, buf, str) == 1)
			return (-1);
		unzip_ar_otool(ptr, str, buf, ac);
	}
	else if (magic_number != DS_STORE)
		return (put_type_otool_error(str));
	return (0);
}

char					*get_name(int x, char *str)
{
	static char *ret = NULL;

	if (x == 1)
		ret = str;
	return (ret);
}

int						otool(void *ptr, char *str, int ac, struct stat *buf)
{
	unsigned int		magic_number;
	t_circ				*to_put;

	magic_number = *(int *)ptr;
	to_put = NULL;
	get_name(1, str);
	set_ppc_type(str, ptr, ac);
	if (magic_number == MH_MAGIC_64 || magic_number == MH_CIGAM_64)
	{
		if (ac != 2 && ac != 3 && check_x32_x64_corrupt(ptr, buf, str, 3) == 1)
			return (-1);
		otool_x64_bin(ptr, str, ac);
		return (0);
	}
	else if (magic_number == MH_MAGIC || magic_number == MH_CIGAM)
	{
		if (ac != 2 && ac != 3 && check_x32_x64_corrupt(ptr, buf, str, 4) == 1)
			return (-1);
		otool_x32_bin(ptr, str, ac);
		return (0);
	}
	return (otool_arch(ptr, str, ac, buf));
}
