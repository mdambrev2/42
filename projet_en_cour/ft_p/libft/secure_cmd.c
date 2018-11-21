/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure_ls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:45:56 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/21 22:44:58 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*raise_file_path(char *path)
{
	char *tmp;
	int  size_path;
	int  x;
	
	x = 0;
	size_path = ft_strlen(path);	
	tmp = get_str_end(path);
	while(*tmp != '/' && x < size_path)
	{
		*tmp = '\0';
		tmp--;
		x++;
	}
	return(path);
}

int		secure_files(char *racine, char *str, char *occu, int *x)
{
	char *path;
	char *pwd;
	
	str = raise_file_path(str);
	path = get_absolute_path_ls(str, &pwd);
	secure_folder(racine, str, occu, x);	
	ft_strdel(&path);	
	ft_strdel(&pwd);
	return(-1);
}

int	secure_cmd(char *cmd, char *racine_serv, int aff)
{
	char *str;
	int		x;
	char *occu;
	char *tmp;

	x = 0;
	if(aff == 0)
		static_error(3);
	static_error(2);
	while((str = dup_occu_by_delim(cmd, ' ', x)) != NULL)
	{
		if(str[0] == '~')
		{
			tmp = str;
			str = ft_strjoin("/Users/mdambrev", str + 1 );
			ft_strdel(&tmp);
		}
		if(str[0] == '-')
		{
			x++;
			ft_strdel(&str);
			continue;
		}
		occu = get_occu_by_delim(cmd, ' ', x);
		if((secure_folder(racine_serv, str, occu, &x)) == 0)
			secure_files(racine_serv, str, occu, &x);
		ft_strdel(&str);
		x++;
	}
	return(static_error(0));
}
