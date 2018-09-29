/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:44:51 by mdambrev          #+#    #+#             */
/*   Updated: 2018/09/29 19:41:29 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <libft.h>
# include <stdarg.h>
# include <wchar.h>

void		init(t_circ *elem);
void		set_flag(t_circ *elem, char *str, int *x);
int			ft_printf(char *str, ...);
void		set_type_args(va_list *ap, t_circ *elem);
int			find_flags(t_circ *elem, char *str, int *x);
int			find_len(t_circ *elem, char *str, int *x);
int			find_flag_conv(t_circ *elem, char *str, int *x);
int			find_conv(t_circ *elem, char *str, int *x);
void		set_content(va_list *ap, t_circ *elem);
t_circ		*find_arg(char *str, t_circ *racine, int *x, int error);
void		init(t_circ *elem);
void		ret_int(va_list *ap, t_circ *elem);
void		ret_uint(va_list *ap, t_circ *elem);
void		ret_adress(va_list *ap, t_circ *elem);
void		ret_string(va_list *ap, t_circ *elem);
void		ret_char(va_list *ap, t_circ *elem);
void		content_transform(t_circ *elem);
void		transform_space(t_circ *elem);
void		transform_wspace(t_circ *elem);
char		*set_str_space(char c, int size);
wchar_t		*set_wstr_space(wchar_t c, int size);
void		join_space(t_circ *elem, char *sub);
void		join_wspace(t_circ *elem, wchar_t *sub);
void		ret_int(va_list *ap, t_circ *elem);
void		ret_uint(va_list *ap, t_circ *elem);
void		convert_uint(t_circ *elem, void *ret);
char		*noconv(t_circ *elem);
void		transform_zero(t_circ *elem, char *sub, int size);
int			find_precision(t_circ *elem, char *str, int *x);
void		put_content(t_circ *elem, int *ret, int error);
int			put_before(char *str, int start, int stop, int erreur);
void		addint_prescision(t_circ *elem);
void		ret_wchar(va_list *ap, t_circ *elem);
void		ret_wstring(va_list *ap, t_circ *elem);
t_circ		*add_elem_inblock_down(t_circ *ret);
char		get_type_64(void *array, t_circ *sector);

#endif
