/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nm_ar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:01:08 by mdambrev          #+#    #+#             */
/*   Updated: 2019/04/09 16:56:39 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

int							got_double(t_circ *list, uint32_t ran_off)
{
	t_circ					*tmp;

	tmp = list->racine->next;
	while (tmp != tmp->racine)
	{
		if (tmp->ran_off == ran_off)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

char						*ar_norm(void *name, char *ar_name, int nm)
{
	if (nm)
	{
		ft_printf("\n%s(%s):\n", name, ar_name);
		ar_name = ft_strend(ar_name);
	}
	else
	{
		if (if_sector_empty_banners(0) != 1)
			ft_printf("\n");
		else
			if_sector_empty_banners(-1);
		ft_printf("%s(%s):\n", name, ar_name);
		ar_name = ft_strend(ar_name);
	}
	return (ar_name);
}

void						unzip_ar(void *ptr, void *name,
							int ac, struct stat *buf)
{
	struct ar_hdr			*header_ar;
	void					*tmp;
	char					*ar_name;

	ac = 2;
	tmp = ptr + SARMAG;
	header_ar = (struct ar_hdr *)tmp;
	tmp += ft_atoi(header_ar->ar_size) + sizeof(struct ar_hdr);
	while (tmp != ptr + buf->st_size
			&& ((char *)tmp)[0] != '!' && ((char *)tmp)[0] != 0)
	{
		header_ar = (struct ar_hdr *)tmp;
		ar_name = tmp + sizeof(struct ar_hdr);
		ar_name = ar_norm(name, ar_name, 1);
		while (*ar_name == 0)
			ar_name++;
		nm(ar_name, name, ac, buf);
		tmp += ft_atoi(header_ar->ar_size) + sizeof(struct ar_hdr);
	}
}

void						unzip_ar_otool(void *ptr, void *name,
		struct stat *buf, int ac)
{
	struct ar_hdr			*header_ar;
	void					*tmp;
	char					*ar_name;

	if (ac == 3)
		if_sector_empty_banners(2);
	tmp = ptr + SARMAG;
	header_ar = (struct ar_hdr *)tmp;
	tmp += ft_atoi(header_ar->ar_size) + sizeof(struct ar_hdr);
	ft_printf("Archive : %s", name);
	while (tmp != ptr + buf->st_size
			&& ((char *)tmp)[0] != '!' && ((char *)tmp)[0] != 0)
	{
		header_ar = (struct ar_hdr *)tmp;
		ar_name = tmp + sizeof(struct ar_hdr);
		ar_name = ar_norm(name, ar_name, 0);
		while (*ar_name == 0)
			ar_name++;
		otool(ar_name, name, 2, buf);
		tmp += ft_atoi(header_ar->ar_size) + sizeof(struct ar_hdr);
	}
	ft_printf("\n");
}
