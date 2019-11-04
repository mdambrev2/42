/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_otool_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:24:14 by mdambrev          #+#    #+#             */
/*   Updated: 2019/04/04 19:50:59 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

int					put_open_otool_args_fail(char *str)
{
	ft_putstr_fd("/Applications/Xcode.app/Contents/Developer", 2);
	ft_putstr_fd("/Toolchains/XcodeDefault.xctoolchain/usr/bin/otool: ", 2);
	if (errno == ENOENT)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": No such file or directory.\n", 2);
	}
	if (errno == EACCES)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": Permission denied.\n", 2);
	}
	return (-1);
}

int					put_buff_otool_error(char *str)
{
	ft_putstr_fd("/Applications/Xcode.app/Contents/Developer", 2);
	ft_putstr_fd("/Toolchains/XcodeDefault.xctoolchain/usr/bin/otool: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": Is a directory.\n", 2);
	return (-1);
}

int					put_type_otool_error(char *str)
{
	ft_putstr_fd("/Applications/Xcode.app/Contents/Developer", 2);
	ft_putstr_fd("/Toolchains/XcodeDefault.xctoolchain/usr/bin/otool: ", 2);
	ft_putstr_fd(str, 2);
	ft_printf(": is not an object file\n");
	return (0);
}

int					put_corrupted_otool_files(char *str)
{
	ft_putstr_fd("/Applications/Xcode.app/Contents/Developer", 2);
	ft_putstr_fd("/Toolchains/XcodeDefault.xctoolchain/usr/bin/otool: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": truncated or malformed object\n", 2);
	ft_putstr_fd(" (filesize is not equal to the end of the file)\n", 2);
	return (-1);
}

int					put_wrong_command_otool_size(char *str)
{
	ft_putstr_fd("/Applications/Xcode.app/Contents/Developer", 2);
	ft_putstr_fd("/Toolchains/XcodeDefault.xctoolchain/usr/bin/otool:", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": truncated or malformed object", 2);
	ft_putstr_fd(" (load command 0 cmdsize not a multiple of 8)\n", 2);
	return (-1);
}
