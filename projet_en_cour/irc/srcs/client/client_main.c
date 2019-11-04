/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:34:39 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/12 14:59:13 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void		usage_client(char *str)
{
	printf("\033[1;33mUsage: %s <address> <port>\033[00m\n", str);
	exit(-1);
}

int			is_localhost(char *str)
{
	if (ft_strcmp(str, "localhost") == 0)
		return (1);
	else
		return (0);
}

void		run_client(int port, char *addr)
{
	t_env	e;

	e.sock = get_server_connection(addr, port);
	init_env(&e, port, addr);
	main_loop(&e);
	close(e.sock);
}

int			main(int argc, char **argv)
{
	int		port;
	char	*addr;

	port = 0;
	addr = NULL;
	addr = get_opt(argc, argv, &port, addr);
	run_client(port, addr);
	return (0);
}
