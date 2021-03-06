/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nm_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:24:14 by mdambrev          #+#    #+#             */
/*   Updated: 2018/09/11 17:39:04 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

void				put_open_args_fail(char *str)
{
	ft_putstr("/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeD");
	ft_putstr("efault.xctoolchain/usr/bin/nm:");
	if(errno == ENOENT)
		ft_printf(" %s: No such file or directory.\n",str);
	if(errno == EACCES)
		ft_printf(" %s: Permission denied.\n",str);

}

void				put_buff_error(char *str)
{
		ft_putstr("/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeD");
		ft_putstr("efault.xctoolchain/usr/bin/nm:");
		ft_printf(" %s: Is a directory.\n",str);
}

void				put_type_error(char *str)
{
		ft_putstr("/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeD");
		ft_putstr("efault.xctoolchain/usr/bin/nm:");
		ft_printf(" %s: The file was not recognized as a valid object file\n",str);
}
