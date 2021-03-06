/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corrupted_file_ar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:01:08 by mdambrev          #+#    #+#             */
/*   Updated: 2019/04/04 19:23:25 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

int						if_equal_ar(void *ptr, off_t offset_end,
												struct stat *buf)
{
	void				*data_end;
	void				*ar_end;

	data_end = ptr + buf->st_size;
	ar_end = ptr + offset_end;
	if (ar_end != data_end)
		return (1);
	return (0);
}

int						offset_norm(char *ptr, struct ar_hdr *header_ar)
{
	return (((void *)header_ar + sizeof(struct ar_hdr)
				+ ft_atoi(ft_strchr(header_ar->ar_name, '/')))
			+ ft_atoi(header_ar->ar_size) - (void*)ptr);
}

off_t					get_all_binary_size(char *ptr, struct stat *buf,
											struct ar_hdr *header_ar)
{
	struct ranlib		*array_bin;
	uint32_t			nb_bin;
	int					offset;
	uint32_t			cpt;

	cpt = 0;
	offset = ft_atoi(ft_strchr(header_ar->ar_name, '/') + 1);
	nb_bin = *(uint32_t*)((void*)header_ar + sizeof(struct ar_hdr)
	+ offset) / sizeof(struct ranlib);
	array_bin = (void*)header_ar + sizeof(struct ar_hdr) + offset + 4;
	while (cpt < nb_bin)
	{
		if (((void *)ptr + array_bin[cpt].ran_off) == (void*)header_ar)
		{
			cpt++;
			continue;
		}
		offset = offset_norm(ptr, header_ar);
		if (if_equal_ar(ptr, offset, buf) == 0)
			return (0);
		header_ar = (void *)ptr + array_bin[cpt].ran_off;
		cpt++;
	}
	return (offset_norm(ptr, header_ar));
}

int						check_ar_corrupt(void *ptr, struct stat *buf,
											char *str)
{
	off_t				offset;
	int					ret;
	struct ar_hdr		*header_ar;

	ret = 0;
	header_ar = (void *)ptr + SARMAG;
	offset = get_all_binary_size(ptr, buf, header_ar);
	ret = if_equal_ar(ptr, offset, buf);
	if (ret == 1 && offset != 0)
		put_corrupted_files(str);
	if (offset == 0)
		ret = 0;
	return (ret);
}
