/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:34:39 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/05 20:00:02 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>

void	usage(char *str)
{
	printf("Usage: %s <port>\n", str);
	exit(-1);
}

void	wait_child(void)
{
	int				statu;
	struct rusage	rusage;

	wait4(0, &statu, 0, &rusage);
}

int		main(int argc, char **argv)
{
	int sock;
	int cs;
	pid_t pid;
	int	n_client;
	char *str;

	if(argc != 2)
		usage(argv[0]);
	sock = create_server(ft_atoi(argv[1]));
	pid = start_multiple_connection(sock, &cs, &n_client);	
	str = "start value";
	while(str != NULL)
	{
		str = read_client(&cs);
		client_reply(cs, str, n_client);
	}
	put_connection_lost(n_client);
	wait_child();
	close(cs);
	if(pid > 0)
		close(sock);
	return(0);
}
