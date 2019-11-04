/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:12:43 by mdambrev          #+#    #+#             */
/*   Updated: 2019/10/01 13:35:37 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

char	*set_file(char **argv, t_env *env)
{
	int fd;
	char buf[4096];
	char *ret;
	char *tmp;

	ret = ft_strdup("\0");
	fd = open(argv[env->args], O_RDWR);
	while(read(fd, buf, 4096))
	{
		tmp = ret;
		ret = ft_strjoin(ret, buf);
		free(tmp);
	}
	close(fd);
	return(ret);
}

void    print_file_reverse(char **argv, t_env *env)
{
	get_md5(env->message, env);
	ft_printf(" \"%s\"", argv[env->args]);
}

void    print_file_normal(char **argv, t_env *env)
{
	if(env->md)
		ft_printf("MD5");
	if(env->sha)
		ft_printf("SHA");
	printf(" (\"%s\") = ", argv[env->args]);
	get_md5(env->message, env);
}

int print_file_error(char **argv, t_env *env)
{
	(void)argv;
	(void)env;
	if(errno == ENOENT)
		ft_printf("ft_ssl: md5: %s: No such file or directory\n", argv[env->args]);
	else if(errno == EACCES)
		ft_printf("ft_ssl: md5: %s: Permission denied\n", argv[env->args]);
	return(1);
}

int		check_file(char **argv, t_env *env)
{

	while(argv[env->args] != 0)
	{
		if(open(argv[env->args], O_RDWR) == -1)
		{
			print_file_error(argv, env);
			env->args++;		
			continue;
		}
		else
			env->message = set_file(argv, env);
		if(env->quiet)
			get_md5(env->message, env);
		else if(env->reverse)
			print_file_reverse(argv, env);
		else
			print_file_normal(argv, env);
		ft_printf("\n");
		env->args++;
	}
	return(0);
}
