/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_connection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:05:07 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/13 15:28:14 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int						get_server_connection(char *addr, int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	if (!(proto = getprotobyname("tcp")))
	{
		exit(-1);
	}
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		printf("\033[1;31mServer : Connection Error \033[00m\n");
		exit(-1);
	}
	printf("- Connected to %s:%d in channel <default irc>\n", addr, port);
	return (sock);
}
