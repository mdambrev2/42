/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:08:23 by mdambrev          #+#    #+#             */
/*   Updated: 2019/10/01 13:32:04 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

int		check_stdin(int argc, char **argv, t_env *env)
{
	char *line;

	line = NULL;
	(void)argc;
	if(env->echo == 1 || argv[env->args] == 0)
	{
		get_next_line(0, &line);
		if(line[0] == '\0')
			return(print_stdin_error());
	
		if(env->echo)
			ft_printf("%s\n", line);
	}
	return(0);
}

