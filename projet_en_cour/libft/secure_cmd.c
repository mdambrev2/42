/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure_ls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:45:56 by mdambrev          #+#    #+#             */
/*   Updated: 2018/10/29 16:12:09 by mdambrev         ###   ########.fr       */
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

int		*secure_files(char *racine, char *str, char *occu, int *x)
{
	char *path;
	char *pwd;
	char *tmp;
	
	str = raise_file_path(str);
	path = get_absolute_path_ls(str, &pwd);
	secure_folder(racine, str, occu, x);
	return(0);
}

int	secure_cmd(char *cmd)
{
	char *str;
	char racine_serv[1024] = "/Users/mdambrev/42/projet_en_cour/libft";
	int		x;
	int test;
	char *occu;

	x = 0;
	while((str = dup_occu_by_delim(cmd, ' ', x)) != NULL)
	{
		if(str[0] == '~')
			str = ft_strjoin("/Users/mdambrev", str + 1 );
		if(str[0] == '-')
		{
			x++;
			continue;
		}
		occu = get_occu_by_delim(cmd, ' ', x);
		if(secure_folder(racine_serv, str, occu, &x) == 0)
			secure_files(racine_serv, str, occu, &x);
		x++;
	}
	printf("%s\n", cmd);
	return(0);
}
