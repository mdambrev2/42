/*e************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:44:51 by mdambrev          #+#    #+#             */
/*   Updated: 2018/10/08 09:38:21 by mdambrev         ###   ########.fr       */
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
# define DS_STORE 16777216

void					test(void);
char					**check_args(int ac, char **av);
int						put_args_missing(char *str);
int						put_open_args_fail(char *str);
int	                	put_buff_error(char *str);
int						put_type_error(char *str);
t_circ					*nm_x64_bin(void *ptr);
t_circ					*nm_x32_bin(void *ptr);
void					set_info_list_order(t_circ *ret, void *array,											char *stringtable, int type);
t_circ					*add_elem_inblock_up(t_circ *ret);
void					set_data_64(t_circ *elem, struct nlist_64 *array,
								char *stringtable, int type);
void					set_data_32(t_circ *elem, struct nlist *array,
								char *stringtable, int type);
void					unzip_fat(void *ptr, void *name, int ac, struct stat *buf);
int						nm(void *ptr, char *str, int ac, struct stat *buf);
void					unzip_ar(void *ptr, void *name, int ac, struct stat *buf);
void					unzip_ar_otool(void *ptr, void *name, struct stat *buf, int ac);
t_circ                  *otool_x64_bin(void *ptr, char *name, int ar);
t_circ                  *otool_x32_bin(void *ptr, char *name, int ar);
int						otool(void *ptr, char *str, int ac, struct stat *buf);
int	                	map(char * ptr, int ac, int set);
void					unzip_fat_otool(void *ptr, void *name, int ac, struct stat *buf);
int						check_x32_x64_corrupt(void *ptr, struct stat *buf, char *str, int x);
int						put_corrupted_files(char *str);
int						put_wrong_command_size(char *str);
int						check_fat_corrupt(void *ptr, struct stat *buf, char *str);
int						check_ar_corrupt(void *ptr, struct stat *buf, char *str);
t_circ					*get_seg_64(void *ptr);
t_circ                  *get_seg_32(void *ptr);
void					free_sector(t_circ *sector);
void					free_main_list(t_circ *ret);
void					free_tab(char **tab);
uint32_t                swap_uint32(uint32_t val);
int						static_banner_ppc(int modifier);
uint64_t				if_ppc_swap(uint64_t value);
char					get_type_32(struct nlist *array, t_circ *sector);
uint64_t				swap_uint64(uint64_t n);
int						put_wrong_command_otool_size(char *str);
int						put_corrupted_otool_files(char *str);
int						put_type_otool_error(char *str);
int						put_open_otool_args_fail(char *str);
int						if_sector_empty_banners(int x);
char					*add_octet_otool_32(char *str, int strlen, int n_ret);
void                    put_list(t_circ *ret, char *name, int ac);

#endif
