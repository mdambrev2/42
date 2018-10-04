/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nm_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:24:14 by mdambrev          #+#    #+#             */
/*   Updated: 2018/10/04 18:04:44 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

int					put_open_otool_args_fail(char *str)
{
/*	ft_putstr("/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeD");
	ft_putstr("efault.xctoolchain/usr/bin/nm:");
	if (errno == ENOENT)
		ft_printf(" %s: No such file or directory.\n", str);
	if (errno == EACCES)
		ft_printf(" %s: Permission denied.\n", str);
*/	
	str = NULL;
	return (-1);
}

int					put_buff_otool_error(char *str)
{
	ft_putstr("/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeD");
	ft_putstr("efault.xctoolchain/usr/bin/nm:");
	ft_printf(" %s: Is a directory.\n", str);
	return (-1);
}

int				put_type_otool_error(char *str)
{

	ft_printf("%s: is not an object file\n",str);
	return (-1);
}

int				put_corrupted_otool_files(char *str)
{
	ft_putstr("/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeD");
	ft_putstr("efault.xctoolchain/usr/bin/nm:");
	ft_printf("%s: truncated or malformed object\n", str);
	ft_putstr(" (filesize is not equal to the end of the file)\n");
	return (-1);
}

int				put_wrong_command_otool_size(char *str)
{
	ft_putstr("/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeD");
	ft_putstr("efault.xctoolchain/usr/bin/nm:");
	ft_printf("%s: truncated or malformed object", str);
	ft_putstr(" (load command 0 cmdsize not a multiple of 8)\n");
	return (-1);
}
