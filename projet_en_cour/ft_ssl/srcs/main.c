/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 12:17:30 by mdambrev          #+#    #+#             */
/*   Updated: 2019/09/02 13:08:40 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

int main(int argc, char **argv)
{
	t_env		env;

	(void)argc;
	if (parsing_argv(argc, argv, &env))
		return(0);
	if(check_stdin(argc, argv, &env))
		return(0);
	if(check_string(argv, &env))
		return(0);
	if(check_file(argv, &env))
		return(0);
	return(0);
}
