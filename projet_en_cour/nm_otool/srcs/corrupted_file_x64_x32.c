/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corrupted_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:04:51 by mdambrev          #+#    #+#             */
/*   Updated: 2018/09/13 17:26:54 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

int					if_equal_x32(void *ptr, struct segment_command* seg, struct stat *buf)
{
	void				 	*data_end;
	void					*seg_data_end;

	data_end = ptr + buf->st_size;
	seg_data_end = ptr + seg->fileoff + seg->filesize ;
	if(seg_data_end != data_end)
		return(0);
	return(1);
}
int					check_size_corrupt_x32(void *ptr, struct stat *buf, int y)
{
	struct mach_header	*header;
	struct load_command		*lc;
	int							x;
	int 					ncmd;
	int						check;

	x = 0;
	check = 0;
	if(y != 2)
		return(0);
	header = (struct mach_header *)ptr;
	ncmd = header->ncmds;
	lc = ptr + sizeof(struct mach_header);
	while(x < ncmd)
	{
		if(lc->cmdsize % 4 != 0)
			return(2);
		if(lc->cmd == LC_SEGMENT)
			check = if_equal_x32(ptr, (struct segment_command* )lc, buf);			
		lc = (void *)lc + lc->cmdsize ;
		x++;
	}
	if(check == 0)
		return(1);
	return(0);
}

int					if_equal_x64(void *ptr, struct segment_command_64* seg, struct stat *buf)
{
	void				 	*data_end;
	void					*seg_data_end;

	data_end = ptr + buf->st_size;
	seg_data_end = ptr + seg->fileoff + seg->filesize ;
	if(seg_data_end != data_end)
		return(0);
	return(1);
}
int					check_size_corrupt_x64(void *ptr, struct stat *buf, int y)
{
	struct mach_header_64	*header;
	struct load_command		*lc;
	int							x;
	int 					ncmd;
	int						check;

	x = 0;
	check = 0;
	if(y != 1)
		return(0);
	header = (struct mach_header_64 *)ptr;
	ncmd = header->ncmds;
	lc = ptr + sizeof(struct mach_header_64);
	while(x < ncmd)
	{
		if(lc->cmdsize % 4 != 0)
			return(2);
		if(lc->cmd == LC_SEGMENT_64)
			check = if_equal_x64(ptr, (struct segment_command_64* )lc, buf);			
		lc = (void *)lc + lc->cmdsize ;
		x++;
	}
	if(check == 0)
		return(1);
	return(0);
}



int					check_x32_x64_corrupt(void *ptr, struct stat *buf, char *str, int x)
{
	if(check_size_corrupt_x64(ptr, buf, x) == 1 || check_size_corrupt_x32(ptr, buf, x) == 1 )
	{
		put_corrupted_files(str);
		return(1);
	}
	if(check_size_corrupt_x64(ptr, buf, x) == 2 || check_size_corrupt_x32(ptr, buf, x) == 2)
	{
		put_wrong_command_size(str);
		return(1);
	}
	return(0);

}
