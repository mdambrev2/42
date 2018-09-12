/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corrupted_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:04:51 by mdambrev          #+#    #+#             */
/*   Updated: 2018/09/11 19:00:45 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>
/*
int					checkeur(unsigned char *offset_to_check, void *file,
									off_t size_file)
{
	if (offset_to_check < (unsigned char *)file)
		return (1);
	if (offset_to_check > (unsigned char *)((unsigned char *)file + size))
		return (1);
	return (0);
}

int 				check_load_command_corrupt()
{

}

int					check_segment_corrupt()
{

}

int					check_data_corrupt()
{
	
}
*/

int					if_equal(void *ptr, struct segment_command_64* seg, struct stat *buf)
{
	void				 	*data_end;
	void					*seg_data_end;

	data_end = ptr + buf->st_size;
	seg_data_end = ptr + seg->fileoff + seg->filesize ;
	if(seg_data_end != data_end)
		return(0);
	return(1);
}
int					check_size_corrupt(void *ptr, struct stat *buf)
{
	struct mach_header_64	*header;
	struct load_command		*lc;
	int							x;
	int 					ncmd;
	int						check;

	x = 0;
	check = 0;
	header = (struct mach_header_64 *)ptr;
	ncmd = header->ncmds;
	lc = ptr + sizeof(struct mach_header_64);
	while(x < ncmd)
	{
		if(lc->cmd == LC_SEGMENT_64)
		{
			check = if_equal(ptr, (struct segment_command_64* )lc, buf);			
		}
		lc = (void *)lc + lc->cmdsize ;
		x++;
	}
	if(check == 0)
		printf("corrompu \n");
	else
		printf("pas corrompu\n");
	return(1);
}

int					check_x64_corrupt(void *ptr, struct stat *buf)
{
	printf("1\n");
	check_size_corrupt(ptr, buf);
	printf("2\n");
	return(0);
}
