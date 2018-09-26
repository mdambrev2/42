/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nm_ar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:01:08 by mdambrev          #+#    #+#             */
/*   Updated: 2018/09/26 19:10:31 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

void						unzip_ar(void *ptr, void *name, int ac, struct stat *buf)
{
	
	struct		ar_hdr		*header_ar;
	struct 		ranlib		*array_bin;
	uint32_t 				nb_bin;
	int						struct_overflow;
	uint32_t				cpt;

	ac = 2;
	header_ar = (void *)ptr + SARMAG ;
	cpt = 0;
	struct_overflow = ft_atoi(ft_strchr(header_ar->ar_name, '/') + 1 );
	nb_bin = *(uint32_t*)((void*)header_ar + sizeof(struct ar_hdr) 
								  + struct_overflow) / sizeof(struct ranlib);
	array_bin = (void*)header_ar + sizeof(struct ar_hdr) 
								  + struct_overflow + 4;
	while(cpt < nb_bin)
	{
		if(((void *)ptr + array_bin[cpt].ran_off)  == (void*)header_ar)
		{
			cpt++;
			continue;
		}
		header_ar = (void *)ptr + array_bin[cpt].ran_off;
		struct_overflow = ft_atoi(ft_strchr(header_ar->ar_name, '/') + 1);
		ft_printf("\n%s(%s):\n", name, header_ar->ar_fmag + 2);
		nm((void *)header_ar + sizeof(struct ar_hdr) + struct_overflow, name , ac, buf);
		cpt++;
	}
	ac = 0;
}

void						unzip_ar_otool(void *ptr, void *name, struct stat *buf, int ac)
{
	
	struct		ar_hdr		*header_ar;
	struct 		ranlib		*array_bin;
	uint32_t 				nb_bin;
	int						struct_overflow;
	uint32_t				cpt;

	header_ar = (void *)ptr + SARMAG ;
	ac = 2;
	cpt = 0;
	struct_overflow = ft_atoi(ft_strchr(header_ar->ar_name, '/') + 1 );
	nb_bin = *(uint32_t*)((void*)header_ar + sizeof(struct ar_hdr) 
								  + struct_overflow) / sizeof(struct ranlib);
	array_bin = (void*)header_ar + sizeof(struct ar_hdr) 
								  + struct_overflow + 4;
	ft_printf("Archive : %s", name);
	while(cpt < nb_bin)
	{
		if(((void *)ptr + array_bin[cpt].ran_off)  == (void*)header_ar)
		{
			cpt++;
			continue;
		}
		header_ar = (void *)ptr + array_bin[cpt].ran_off;
		struct_overflow = ft_atoi(ft_strchr(header_ar->ar_name, '/') + 1);
		ft_printf("\n%s(%s):\n", name, header_ar->ar_fmag + 2);
		otool((void *)header_ar + sizeof(struct ar_hdr) + struct_overflow, name , ac, buf);
		cpt++;
	}
	
	ft_printf("\n");
}
