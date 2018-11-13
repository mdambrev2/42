/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_connection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:05:07 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/14 00:00:42 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>

int		get_server_connection(char *addr, int port)
{
	int	sock;
	struct protoent *proto;
	struct sockaddr_in sin;

	if(!(proto = getprotobyname("tcp")))
	{
		printf("Proto error\n");
		exit(-1);
	}
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);	
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if(connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		printf("Connect Error \n");
		exit(-1);
	}
	return(sock);
}

int		write_server_sock(int cs)
{
	int r;
	char buf[1024];

	ft_bzero(buf, 1024);
	ft_putstr("Prompt de test --> ");
	r = read(STDIN_FILENO, buf, 1023);
	buf[1023] = '\0';
	init_connection(cs);
	if(send_data(cs, buf, ft_strlen(buf)) == -1)
		exit(0);
	done_connection(cs);
	return(r);
}
