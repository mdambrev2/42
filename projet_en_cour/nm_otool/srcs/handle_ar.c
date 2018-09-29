/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nm_ar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:01:08 by mdambrev          #+#    #+#             */
/*   Updated: 2018/09/29 20:46:19 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

int		got_double(t_circ * list, uint32_t ran_off)
{
	t_circ *tmp;

	tmp = list->racine->next;
	while(tmp != tmp->racine)
	{
		if(tmp->ran_off == ran_off)
			return(1);
		tmp = tmp->next;
	}
	return(0);
}

t_circ *get_list_position(t_circ * list, uint32_t ran_off)
{
	t_circ *tmp;

	tmp = list->racine->next;
	while(tmp != tmp->racine)
	{
		if(tmp->ran_off > ran_off)
			return(tmp);
		tmp = tmp->next;
	}
	return(tmp);
}

t_circ *get_ar_sorted_list(void *ptr, struct ranlib *array_bin, uint32_t  nb_bin)
{
	uint32_t				cpt;
	struct ar_hdr           *header_ar;
	t_circ					*ret;

	cpt = 0;
	header_ar = (void *)ptr + SARMAG;
	ret = create_circular_list();
	ret->racine->ran_off = 0;
	while (cpt < nb_bin)
	{
		if(ft_strcmp("Singleton.o", header_ar->ar_fmag + 2 ) == 0)
		{
			printf("toto\n");
			exit(1);
		}
		if (((void *)ptr + array_bin[cpt].ran_off) == (void*)header_ar || got_double(ret, array_bin[cpt].ran_off))
		{
			cpt++;
			continue;
		}
			ret = get_list_position(ret, array_bin[cpt].ran_off);
			ret = add_elem_inblock_up(ret);
			ret->ran_off = array_bin[cpt].ran_off;
			ret->ran_cpt = cpt;
		header_ar = (void *)ptr ;
		cpt++;
	}
	ret = ret->racine->next;
	return(ret);
}

void						unzip_ar(void *ptr, void *name,
										int ac, struct stat *buf)
{
	struct ar_hdr			*header_ar;
	struct ranlib			*array_bin;
	uint32_t				nb_bin;
	int						struct_overflow;
	t_circ					*ret;

	ac = 2;
	header_ar = (void *)ptr + SARMAG;
	struct_overflow = ft_atoi(ft_strchr(header_ar->ar_name, '/') + 1);
	nb_bin = *(uint32_t*)((void*)header_ar + sizeof(struct ar_hdr)
								+ struct_overflow) / sizeof(struct ranlib);
	array_bin = (void*)header_ar + sizeof(struct ar_hdr)
								+ struct_overflow + 4;
	ret = get_ar_sorted_list(ptr, array_bin, nb_bin);
	while (ret != ret->racine)
	{
		header_ar = (void *)ptr + array_bin[ret->ran_cpt].ran_off;
		struct_overflow = ft_atoi(ft_strchr(header_ar->ar_name, '/') + 1);
		ft_printf("\n%s(%s):\n", name, header_ar->ar_fmag + 2);
		nm((void *)header_ar + sizeof(struct ar_hdr)
							+ struct_overflow, name, ac, buf);
		ret = ret->next;
	}
	ac = 0;
}

void						unzip_ar_otool(void *ptr, void *name,
											struct stat *buf, int ac)
{
	struct ar_hdr			*header_ar;
	struct ranlib			*array_bin;
	uint32_t				nb_bin;
	int						struct_overflow;
	t_circ					*ret;

	header_ar = (void *)ptr + SARMAG;
	ac = 2;
	struct_overflow = ft_atoi(ft_strchr(header_ar->ar_name, '/') + 1);
	nb_bin = *(uint32_t*)((void*)header_ar + sizeof(struct ar_hdr)
								+ struct_overflow) / sizeof(struct ranlib);
	array_bin = (void*)header_ar + sizeof(struct ar_hdr)
								+ struct_overflow + 4;
	ft_printf("Archive : %s", name);
	ret = get_ar_sorted_list(ptr, array_bin, nb_bin);
	while (ret != ret->racine)
	{
		header_ar = (void *)ptr + array_bin[ret->ran_cpt].ran_off;
		struct_overflow = ft_atoi(ft_strchr(header_ar->ar_name, '/') + 1);
		ft_printf("\n%s(%s):\n", name, header_ar->ar_fmag + 2);
		otool((void *)header_ar + sizeof(struct ar_hdr)
								+ struct_overflow, name, ac, buf);
		ret = ret->next;
	}
	ft_printf("\n");
}
