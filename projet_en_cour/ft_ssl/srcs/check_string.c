/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:53:48 by mdambrev          #+#    #+#             */
/*   Updated: 2019/10/01 13:34:29 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void	print_reverse(char **argv, t_env *env)
{
	get_md5(argv[env->args], env);
	ft_printf(" \"%s\"", argv[env->args]);
}

void	print_normal(char **argv, t_env *env)
{
	if(env->md)
		ft_printf("MD5");
	if(env->sha)
		ft_printf("SHA");
	ft_printf(" (\"%s\") = ", argv[env->args]);
	get_md5(argv[env->args], env);
}

int		check_string(char **argv, t_env *env)
{
	if(env->string)
	{
		if(env->quiet)
			get_md5(argv[env->args], env);
		else if(env->reverse)
			print_reverse(argv, env);
		else
			print_normal(argv, env);
		env->args++;
		ft_printf("\n");
	}
	return(0);
}
