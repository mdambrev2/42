/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_connection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:05:07 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/08 21:28:10 by mdambrev         ###   ########.fr       */
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
	return(sock);
}

pid_t	start_multiple_connection(int sock, int *cs, int *n_client)
{
	unsigned int cslen;
	struct sockaddr_in csin;
	pid_t				pid;

	
	*cs = accept(sock, (struct sockaddr*)&csin, &cslen);
	*n_client = put_new_connection();
	pid = fork();
	if(pid == 0)
		start_multiple_connection(sock, cs, n_client);
	else if(pid > 0)
		return(pid);
	return(*cs);
}

int		client_contact(int cs, int n_client)
{
	t_message 	msg;
	char		*buf;
	int			x;
	char		racine_serv[1024];

	msg.messagetype = 0;
	getcwd(racine_serv, 1024);
	while((x = receive(cs, &msg)) == 1)
	{
		if((buf = read_data(cs, msg)) == NULL)
			return(-1);
		client_reply(cs, buf, n_client, racine_serv);
	}
	if(x == -1)
		return(-1);
	return(0);
}

