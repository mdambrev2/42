/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_connection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:05:07 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/05 19:26:50 by mdambrev         ###   ########.fr       */
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

char	*read_client(int *cs)
{
	char buf[1024];
	int	r;


	ft_bzero(buf, 1024);
	r = recv(*cs, buf, 1023, 0);
	if(r != 0)
		buf[r - 1] = '\0';
	if(r <= 0)
		return(NULL);
	return(ft_strdup(buf));
}
