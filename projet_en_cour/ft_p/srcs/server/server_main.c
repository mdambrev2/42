/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:34:39 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/16 05:32:59 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>

void	usage(char *str)
{
	printf("Usage: %s <port>\n", str);
	exit(0);
}

void	wait_child(void)
{
	int				statu;
	struct rusage	rusage;

	wait4(-1, &statu, 0, &rusage);
}

void	send_client_infos(int cs, int  n_client)
{
	char *str;

	str = ft_itoa(n_client);
	init_connection(cs);
	send_data(cs, str, ft_strlen(str));
	done_connection(cs);
}

char		*stock_cwd(int x)
{
	static char *str;

	if(x == 0)
	{
		str = (char *)malloc(sizeof(char) * 1024);
	    str = getcwd(str, 1024);
	}
	return(str);
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
	stock_cwd(0);
	pid = start_multiple_connection(sock, &cs, &n_client, 0);
	send_client_infos(cs, n_client);
	while(client_contact(cs, n_client) != -1)
	{
		recv_string(cs);
		send_string(cs, ft_itoa(swap_to_error(0)));
		swap_to_error(2);
	}
	put_connection_lost(n_client);
	close(cs);
	if(pid == 0)
		close(sock);
	return(0);
}
