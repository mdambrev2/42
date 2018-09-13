/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_otool_64.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:31:49 by mdambrev          #+#    #+#             */
/*   Updated: 2018/09/13 18:07:33 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

char 					*add_octet_otool(char *str, int strlen, int n_ret)
{
	int n_octet;
	char	*ret;
	int 	cpt;
	int 	i;

	cpt = 0;
	n_octet = n_ret - strlen;
	ret = ft_strnew(n_ret + 1);
	i = 0;
	while(cpt < n_octet)
	{
		ret[cpt] = '0';
		cpt++;
	}
	while(str[i])
	{
		ret[cpt] = str[i];
		cpt++;
		i++;
	}
	free(str);
	return(ret);
}


void		*put_addres_otool(void *addr)
{
	char	*str1;


	str1 = ft_convert_base_max((uintmax_t )addr, 16);
	str1 = add_octet_otool(str1, ft_strlen(str1), 16);
	ft_printf("%s\t", str1);
	free(str1);
	addr = addr + 16;
	return(addr);
}

void	print_data_text( struct section_64 *sec, void *ptr, char *name, int ar)
{
	uint64_t cpt;
	char *str;
	char *str1;
	void *addr;

	cpt = 0;
	str = (char *)ptr + sec->offset;
	addr = (void *)sec->addr;
	if(ar == 0 )
		ft_printf("%s:\nContents of (__TEXT,__text) section\n",name);
	else
		ft_printf("Contents of (__TEXT,__text) section\n",name);
	while(cpt < sec->size)
	{
		if(cpt % 16 == 0 || cpt == 0)
			addr = put_addres_otool(addr);
		str1 = ft_convertn_base_max(str[cpt], 16, 2);
		ft_printf("%s ", str1);
		free(str1);	
		cpt++;
		if(cpt % 16 == 0 && cpt != sec->size)
			ft_printf("\n");
	}
	if(ar == 0)
		ft_printf("\n");
}


void					find__text( struct segment_command_64 *seg,
											void *ptr,char *name, int ar)
{
	int cpt;
	int x;
	struct section_64 *sec;

	cpt = seg->nsects;
	sec = (void*)seg + sizeof(struct segment_command_64);
	x = 0;
	while(x < cpt)
	{
		if(ft_strcmp(sec->sectname, "__text") == 0)
			print_data_text(sec, ptr, name, ar);
		sec = (void*)sec + sizeof(struct section_64);
		x++;	
	}
}

t_circ					*otool_x64_bin(void *ptr, char *name, int ar)
{
	struct mach_header_64	*header;
	struct load_command		*lc;
	int						n_cmd;
	int							x;
	struct segment_command_64	*seg;

	x = 0;
	header = (struct mach_header_64 *)ptr;
	n_cmd = header->ncmds;
	lc = ptr + sizeof(struct mach_header_64);
	while(x < n_cmd)
	{
		if(lc->cmd == LC_SEGMENT_64 )
		{
			seg = (struct segment_command_64*)lc;
			find__text(seg, ptr, name, ar);
		}
		lc = (void *)lc + lc->cmdsize ;
		x++;
	}
	return(NULL);
}

