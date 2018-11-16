/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 00:18:04 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/16 07:27:37 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"


int		swap_to_error(int x)
{
	static int ret = 0;

	if(x == 1)
		ret = 1;
	if(x == 2)
		ret = 0;
	return(ret);
}

int			check_args_get(int cs,char *cmd)
{
	int file;
	
	if((file = open(get_occu_by_delim(cmd, ' ', 1),  O_RDONLY)) > 0)
	{
		close(file);
		send_string(cs, "\0");
		return(0);
	}
	else if(get_occu_by_delim(cmd, ' ', 1) == NULL)
	{
		send_string(cs, "\nMissing args - usage: get < file >\n\n");
	}
	else if(get_occu_by_delim(cmd, ' ', 2))
	{
		send_string(cs, "\nToo many args - usage: get < file >\n\n");
	}
	else
	{
		send_string(cs, "\nNo such files - usage: get < file >\n\n");
	}
	swap_to_error(1);
	return(-1);
}	

int			get_file_server(int cs, char *cmd)
{
	char *buf;
	int fd_file;
	int n_octet;

	if(check_args_get(cs, cmd) == -1)
		return(0);
	send_string(cs, get_occu_by_delim(cmd, ' ', 1));
	buf = (char*)malloc(sizeof(char) * (1024));
	fd_file = open(get_occu_by_delim(cmd, ' ', 1), O_RDWR , S_IRWXU);	
	init_connection(cs);
	ft_bzero(buf, 1024);
	while((n_octet = read(fd_file, buf, 1024)) > 0)
	{
		send_data(cs, buf, n_octet);
		ft_bzero(buf, 1024);
	}
	done_connection(cs);
	close(fd_file);
	return(0);
}
