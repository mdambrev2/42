/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_connection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:05:07 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/16 03:24:24 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>

int		create_server(int port)
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
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if(bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		printf("Bind Error \n");
		exit(-1);
	}
	listen(sock, 42);
	get_fork("mkdir -p R_server");
	chdir("./R_server");
	return(sock);
}

pid_t	start_multiple_connection(int sock, int *cs, int *n_client, int x)
{
	unsigned int cslen;
	struct sockaddr_in csin;
	pid_t				pid;

	*cs = accept(sock, (struct sockaddr*)&csin, &cslen);
	*n_client = put_new_connection();
	pid = fork();
	if(pid == 0)
		return(pid);
	signal(SIGCHLD, SIG_IGN);
	start_multiple_connection(sock, cs, n_client, pid);
	return(x);
}

int		client_contact(int cs, int n_client)
{
	t_message 	msg;
	char		*buf;

	msg.messagetype = 0;
	buf = recv_string(cs);
	if(client_reply(cs, buf, n_client, stock_cwd(1)) == -1)
		return(-1);
	return(0);
}
