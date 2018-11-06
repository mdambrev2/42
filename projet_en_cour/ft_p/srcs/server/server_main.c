/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:34:39 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/06 21:58:03 by mdambrev         ###   ########.fr       */
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

void	send_client_infos(int cs, int  n_client)
{
	char *str;

	str = ft_itoa(n_client);
	init_connection(cs);
	send_data(cs, str, ft_strlen(str));
	done_connection(cs);
}

int		main(int argc, char **argv)
{
	int sock;
	int cs;
	pid_t pid;
	int	n_client;

	if(argc != 2)
		usage(argv[0]);
	sock = create_server(ft_atoi(argv[1]));
	pid = start_multiple_connection(sock, &cs, &n_client);
	send_client_infos(cs, n_client);
	while(client_contact(cs, n_client) != -1)
		;
	put_connection_lost(n_client);
	wait_child();
	close(cs);
	if(pid > 0)
		close(sock);
	return(0);
}
