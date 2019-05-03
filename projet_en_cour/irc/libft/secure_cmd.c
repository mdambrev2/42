/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure_ls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:45:56 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/23 07:07:05 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char			*raise_file_path(char *path)
{
	char		*tmp;
	int			size_path;
	int			x;

	x = 0;
	size_path = ft_strlen(path);
	tmp = get_str_end(path);
	while (*tmp != '/' && x < size_path)
	{
		*tmp = '\0';
		tmp--;
		x++;
	}
	return (path);
}

int				secure_files(char *racine, char *str, char *occu, int *x)
{
	char		*path;
	char		*pwd;

	str = raise_file_path(str);
	path = get_absolute_path_ls(str, &pwd);
	secure_folder(racine, str, occu, x);
	ft_strdel(&path);
	ft_strdel(&pwd);
	return (-1);
}

int				raise_end_space(char *str)
{
	int			x;

	x = 0;
	while (str[x] != '\0')
		x++;
	x--;
	while (x >= 0 && str[x] == ' ')
	{
		str[x] = '\0';
		x--;
	}
	return (0);
}

int				norm_secure_cmd(char **str)
{
	char		*tmp;

	tmp = *str;
	*str = ft_strjoin("/Users/mdambrev", *str + 1);
	ft_strdel(&tmp);
	return (0);
}

int				secure_cmd(char *cmd, char *racine_serv, int aff)
{
	char		*str;
	int			x;
	char		*occu;

	if (aff == 0)
		static_error(3);
	x = static_error(2);
	while ((str = dup_occu_by_delim(cmd, ' ', x)) != NULL)
	{
		if (str[0] == '~')
			norm_secure_cmd(&str);
		if (str[0] == '-')
		{
			x++;
			ft_strdel(&str);
			continue ;
		}
		occu = get_occu_by_delim(cmd, ' ', x);
		if ((secure_folder(racine_serv, str, occu, &x)) == 0)
			secure_files(racine_serv, str, occu, &x);
		ft_strdel(&str);
		x++;
	}
	raise_end_space(cmd);
	return (static_error(0));
}
