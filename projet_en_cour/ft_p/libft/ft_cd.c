/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 19:04:00 by mdambrev          #+#    #+#             */
/*   Updated: 2018/10/24 21:24:43 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "includes/libft.h"

int	put_error(int error)
{
	if(error == -1 )
		printf("Out Of Range\n");
	if(error == -2)
		printf("No such Files or Directory\n");
	if(error == -3)
		printf("Unknown option\n");
	return(-1);
}

char *get_absolute_path(const char *path, char **pwd)
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

int	test_path(const char *path, char *absolute_path, char *pwd)
{
	static char start[1024] = "\0";
	static char *buf1;
	
	if(start[0] == 0)
		ft_memcpy(start, pwd, ft_strlen(pwd));
	buf1 = (char *)malloc(sizeof(char) * 1024);	
	if(chdir(absolute_path) < 0)
		return(-2);
	buf1 = getcwd(buf1, 1024);
	if(ft_strstr(buf1, start) == NULL)
	{
		chdir(start);
		return(-1);
	}
	chdir(pwd);
	return(0);
}

int	set_old_pwd(char *old_pwd, char *pwd, const char *path)
{
	char *test;

	test = malloc(300);
	if(old_pwd[0] == '0')
		return(-2);
	if(path[0] == '-' && path[1] != '\0')
		return(-3);
	chdir(old_pwd);
	ft_bzero(old_pwd, 1024);
	ft_memcpy(old_pwd, pwd, ft_strlen(pwd));
	test = getcwd(test, 300);	
	printf("Sucess\n");
	return(0);
}

int ft_cd(const char *path, int sec)
{
	char *absolute_path;
	char *pwd;
	int	 error;
	static	char old_pwd[1024] = "0";

	absolute_path = get_absolute_path(path, &pwd);
	if(path[0] != '-' && path[1] != '\0')
	{
		if(sec == 1)
			if((error = test_path(path, absolute_path, pwd)) < 0)
				return(put_error(error));
		printf("Sucess\n");
		chdir(absolute_path);
		ft_bzero(old_pwd, ft_strlen(absolute_path));
		ft_memcpy(old_pwd, pwd, ft_strlen(absolute_path));
	}
	else
		if((error = set_old_pwd(old_pwd, pwd, path)) < 0)
			return(put_error(error));
	return(0);
}
