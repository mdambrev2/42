/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure_folder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 18:05:15 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/08 21:27:35 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char *get_absolute_path_ls(const char *path, char **pwd)
{
	char *tmp;
	char *tmp2;

	*pwd = (char *)malloc(sizeof(char) * 1024);
	*pwd = getcwd(*pwd, 1024);
	tmp = ft_strjoin(*pwd, "/");
	tmp2 = ft_strjoin(tmp, path);
	free(tmp);
	return(tmp2);
}

int	test_path_ls(char *racine, char *line)
{
	static char *buf1;
	int x;
	char *tmp;

	tmp = dup_occu_by_delim(line, ' ', 0);
	buf1 = (char *)malloc(sizeof(char) * 1024);
	buf1 = getcwd(buf1, 1024);
	x = 0;
	if(ft_strstr(buf1, racine) == NULL)
	{
		while(line[x] != ' ' && line[x] != '\0')
		{
			line[x] = ' ';
			x++;
		}
		printf("Server -- Permission Denied : %s \n", tmp);
		free(tmp);
		return(-1);
	}
	return(1);
}


int special_error(char *str, char *line)
{
	int x;

	x = 0;
	if(str[0] == '/' || str[0] == '~')
	{
		while(str[x] == '/')
			x++;
		if(str[x] == '\0' || str[0] == '~')
		{
			x = 0;
			while(line[x] != ' ' && line[x] != '\0')
			{
				line[x] = ' ';
				x++;
			}
			printf("Server -- Permission Denied : %s \n", str);
			return(-1);
		}
	}
	return(0);
}

int secure_folder(char *racine, char *str, char *occu, int *x)
{
	char *path;
	char *pwd;
	int	 test;
	
	path = get_absolute_path_ls(str, &pwd);
	test = 0;
	if((test = special_error(str, occu)) == -1)
			*x = *x - 1;	
	else if(chdir(path) >= 0)
	{
		if((test = test_path_ls(racine, occu)) == -1)
			*x = *x - 1;
		chdir(pwd);
	}
	else if(chdir(str) >= 0)
	{
		if((test = test_path_ls(racine, occu)) == -1)
			*x = *x - 1;
		chdir(pwd);
	}
	return(test);
}
