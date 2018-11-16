/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:34:39 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/16 03:40:00 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>

void	usage_client(char *str)
{

	printf("\033[1;33mUsage: %s <address> <port>\033[00m\n", str);
	exit(-1);
}

int		is_localhost(char *str)
{
	if(ft_strcmp(str, "localhost") == 0)
		return(1);
	else
		return(0);
}
int		main(int argc, char **argv)
{
	int port;
	int sock;
	int r;

	if(argc != 3)
		usage_client(argv[0]);
	r = 1;
	if(is_localhost(argv[1]))
		argv[1] = ft_strdup("127.0.0.1");
	port = ft_atoi(argv[2]);
	get_client_infos(2, 1, argv[1]);
	sock = get_server_connection(argv[1], port);
	put_client_connection(sock);
	while(r > 0)
	{
		r = write_server_sock(sock);	
		if(receive_server_instruction(sock) == -1)
			break;
	}
	close(sock);
	return(0);
}
