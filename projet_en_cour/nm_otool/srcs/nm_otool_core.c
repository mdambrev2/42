/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_otool_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:25:51 by mdambrev          #+#    #+#             */
/*   Updated: 2018/10/04 20:45:26 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

int						map(char *str, int ac, int set)
{
	struct stat			buf;
	void				*ptr;
	int					fd;

	if ((fd = open(str, O_RDONLY)) < 0)
		return (put_open_args_fail(str));
	fstat(fd, &buf);
	if (S_ISDIR(buf.st_mode) == 1)
		return (put_buff_error(str));
	ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (set == 0 && ac <= 2)
		nm(ptr, str, 0, &buf);
	else if (set == 0 && ac > 2)
		nm(ptr, str, 5, &buf);
	else if (set == 1 && ac <= 2)
		return (otool(ptr, str, 0, &buf));
	else if (set == 1 && ac > 2)
		return (otool(ptr, str, 5, &buf));
	munmap(ptr, buf.st_size);
	return (0);
}

void					put_list(t_circ *ret, char *name, int ac)
{
	ret = ret->racine->next;
	if (ac > 2 && ac != 5)
		ft_printf("\n%s\n", name);
	else if (ac == 5)
		ft_printf("\n%s:\n", name);
	if (ret->type == 'T' && ret->value[0] == '_')
	{
		ft_memdel((void*)&ret->value);
		ft_memdel((void*)&ret->function_name);
	}
	while (ret != ret->racine)
	{
		ft_printf("%s %c %s\n", ret->value, ret->type, ret->function_name);
		ft_memdel((void*)&ret->value);
		ft_memdel((void*)&ret->function_name);
		ret = ret->next;
	}
	free_circ(ret->racine);
}

int						nm(void *ptr, char *str, int ac, struct stat *buf)
{
	unsigned int		magic_number;
	t_circ				*to_put;

	magic_number = *(int *)ptr;
	to_put = NULL;

	if (magic_number == MH_MAGIC_64 || magic_number == MH_CIGAM_64)
	{
		if (ac != 2 && check_x32_x64_corrupt(ptr, buf, str, 1) == 1)
			return (0);
		to_put = nm_x64_bin(ptr);
	}
	else if (magic_number == MH_MAGIC || magic_number == MH_CIGAM)
	{
		if (ac != 2 && check_x32_x64_corrupt(ptr, buf, str, 2) == 1)
			return (0);
		to_put = nm_x32_bin(ptr);
	}
	else if (magic_number == FAT_MAGIC || magic_number == FAT_CIGAM)
	{
		if (check_fat_corrupt(ptr, buf, str) == 1)
			return (0);
		unzip_fat(ptr, str, ac, buf);
		return (0);
	}
	else if ((*(uint64_t *)ptr) == AR_MAGIC || (*(uint64_t *)ptr) == AR_CIGAM)
	{
		if (ac != 2 && check_ar_corrupt(ptr, buf, str) == 1)
			return (0);
		unzip_ar(ptr, str, ac, buf);
		return (0);
	}
	else
		return (put_type_error(str));
	put_list(to_put, str, ac);
	return (0);
}

int						otool(void *ptr, char *str, int ac, struct stat *buf)
{
	unsigned int		magic_number;
	t_circ				*to_put;

	magic_number = *(int *)ptr;
	to_put = NULL;
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
	else if (magic_number == FAT_MAGIC || magic_number == FAT_CIGAM)
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
	else if(magic_number != DS_STORE)
		return (put_type_otool_error(str));
	return (0);
}
