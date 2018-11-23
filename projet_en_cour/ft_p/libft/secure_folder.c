/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure_folder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 18:05:15 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/23 07:17:19 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char		*get_absolute_path_ls(const char *path, char **pwd)
{
	char	*tmp;
	char	*tmp2;

	*pwd = (char *)malloc(sizeof(char) * 1024);
	*pwd = getcwd(*pwd, 1024);
	tmp = ft_strjoin(*pwd, "/");
	tmp2 = ft_strjoin(tmp, path);
	ft_strdel(&tmp);
	return (tmp2);
}

int			norm_test_path(char **tmp, char **buf1)
{
	static_error(1);
	if (static_error(4))
		printf("\033[1;33mServer -- Permission Denied : %s \033[00m\n", *tmp);
	static_error(5);
	ft_strdel(tmp);
	ft_strdel(buf1);
	return (0);
}

int			test_path_ls(char *racine, char *line)
{
	char	*buf1;
	int		x;
	char	*tmp;

	tmp = dup_occu_by_delim(line, ' ', 0);
	buf1 = (char *)malloc(sizeof(char) * 1024);
	buf1 = getcwd(buf1, 1024);
	x = 0;
	if (ft_strstr(buf1, racine) == NULL)
	{
		while (line[x] != ' ' && line[x] != '\0')
		{
			line[x] = ' ';
			x++;
		}
		norm_test_path(&tmp, &buf1);
		return (-1);
	}
	ft_strdel(&tmp);
	ft_strdel(&buf1);
	return (1);
}

int			special_error(char *str, char *line)
{
	int		x;

	x = 0;
	if (str[0] == '/' || str[0] == '~')
	{
		while (str[x] == '/')
			x++;
		if (str[x] == '\0' || str[0] == '~')
		{
			x = 0;
			while (line[x] != ' ' && line[x] != '\0')
			{
				line[x] = ' ';
				x++;
			}
			static_error(1);
			if (static_error(4))
				printf("\033[1;33mServer -- Permission Denied : %s \033[00m\n"
						, str);
			return (-1);
		}
	}
	return (0);
}

int			secure_folder(char *racine, char *str, char *occu, int *x)
{
	char	*path;
	char	*pwd;
	int		test;

	path = get_absolute_path_ls(str, &pwd);
	if ((test = special_error(str, occu)) == -1)
		*x = *x - 1;
	else if (chdir(path) >= 0)
	{
		if ((test = test_path_ls(racine, occu)) == -1)
			*x = *x - 1;
		chdir(pwd);
	}
	else if (chdir(str) >= 0)
	{
		if ((test = test_path_ls(racine, occu)) == -1)
			*x = *x - 1;
		chdir(pwd);
	}
	ft_strdel(&pwd);
	ft_strdel(&path);
	return (test);
}
