/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 13:01:50 by mdambrev          #+#    #+#             */
/*   Updated: 2019/10/01 13:30:03 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

int		check_args(char **argv, t_env *env)
{
	if(env->string == 1 && argv[env->args] == 0)
		return(print_string_error());
	return(0);
}

int		set_mode(char **argv, t_env *env)
{
	if(argv[1] == 0)
		return(print_digest_error());
	if (ft_strcmp(argv[1], "sha256") == 0)
		env->sha = 1;
	else if (ft_strcmp(argv[1], "md5") == 0)
		env->md = 1;
	else
		return(print_digest_error());
	return (0);
}

int	set_flags(int argc, char **argv, t_env *env)
{
	int i;

	i = 2;
	while(i < argc && argv[i][0] == '-')
	{
		if(!ft_strcmp(argv[i] + 1, "p"))
			env->echo = 1;
		else if(!ft_strcmp(argv[i] + 1, "q"))
			env->quiet = 1;
		else if(!ft_strcmp(argv[i] + 1, "r"))
			env->reverse = 1;
		else if(!ft_strcmp(argv[i] + 1, "s"))
			env->string = 1;
		else
			return(print_illegal_option(argv, i));
			
		i++;
	}
	env->args = i;
	return(0);
}

int	parsing_argv(int argc, char **argv, t_env *env)
{
		
	if(set_mode(argv, env))
		return(1);
	if(set_flags(argc, argv, env))
		return(1);
	if(check_args(argv, env))
		return(1);
	return(0);
}
