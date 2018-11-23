/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_connection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:05:07 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/23 05:34:55 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>

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
	return (sock);
}

int						write_server_sock(int cs)
{
	int					r;
	char				buf[1024];

	ft_bzero(buf, 1024);
	ft_putstr("\033[1;36mClient");
	ft_putstr(get_client_infos(1, 0, NULL));
	ft_putstr(" -- ");
	ft_putstr(get_client_infos(2, 0, NULL));
	ft_putstr("\033[00m $>\033[1;34m / : \033[00m");
	r = read(STDIN_FILENO, buf, 1023);
	buf[1023] = '\0';
	send_string(cs, buf);
	return (r);
}
