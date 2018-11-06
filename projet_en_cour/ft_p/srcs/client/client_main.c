/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:34:39 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/06 21:40:31 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>

void	usage_client(char *str)
{
	printf("Usage: %s <address> <port>\n", str);
	exit(-1);
}

int		main(int argc, char **argv)
{
	int port;
	int sock;
	int r;
	
	if(argc != 3)
		usage_client(argv[0]);
	r = 1;
	port = ft_atoi(argv[2]);	
	sock = get_server_connection(argv[1], port);
	put_client_connection(sock);
	while(r > 0)
	{
		r = write_server_sock(sock);
		receive_server_instruction(sock);
	}
	close(sock);
	return(0);
}
