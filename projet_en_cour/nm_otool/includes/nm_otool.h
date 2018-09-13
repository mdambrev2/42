/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:44:51 by mdambrev          #+#    #+#             */
/*   Updated: 2018/09/13 17:10:35 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_OTOOL_H
# define NM_OTOOL_H
# include <stdio.h>
# include "../libft/includes/libft.h"
# include "ft_printf.h"
# include <errno.h>
# include <fcntl.h>
# include <ar.h>
# include <mach-o/ranlib.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>


# define AR_MAGIC 0x213c617263683e0a
# define AR_CIGAM 0x0a3e686372613c21

void					test(void);
char					**check_args(int ac, char **av);
void					put_args_missing(char *str);
void					put_open_args_fail(char *str);
void                	put_buff_error(char *str);
void					put_type_error(char *str);
t_circ					*nm_x64_bin(void *ptr);
t_circ					*nm_x32_bin(void *ptr);
void					set_info_list_order(t_circ *ret, void *array,											char *stringtable, int type);
t_circ					*add_elem_inblock_up(t_circ *ret);
void					set_data_64(t_circ *elem, struct nlist_64 *array,
								char *stringtable, int type);
void					set_data_32(t_circ *elem, struct nlist *array,
								char *stringtable, int type);
void					unzip_fat(void *ptr, void *name, int ac, struct stat *buf);
void					nm(void *ptr, char *str, int ac, struct stat *buf);
void					unzip_ar(void *ptr, void *name, int ac, struct stat *buf);
void					unzip_ar_otool(void *ptr, void *name, int ac, struct stat *buf);
t_circ                  *otool_x64_bin(void *ptr, char *name, int ar);
t_circ                  *otool_x32_bin(void *ptr, char *name, int ar);
void					otool(void *ptr, char *str, int ac, struct stat *buf);
void                	map(char * ptr, int ac, int set);
void					unzip_fat_otool(void *ptr, void *name, int ac, struct stat *buf);
int						check_x32_x64_corrupt(void *ptr, struct stat *buf, char *str, int x);
void					put_corrupted_files(char *str);
void					put_wrong_command_size(char *str);
int						check_fat_corrupt(void *ptr, struct stat *buf, char *str);
int						check_ar_corrupt(void *ptr, struct stat *buf, char *str);
#endif
