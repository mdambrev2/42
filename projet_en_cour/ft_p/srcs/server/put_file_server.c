/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_file_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 00:18:04 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/16 03:01:27 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"


int		put_file_server(int cs, char *cmd)
{
	char *buf;
	char *file_name;
	int			fd_file;
	t_message   msg;

	send_string(cs, cmd);
	buf = recv_string(cs);
	if(buf != NULL)
	{
		swap_to_error(1);
		return(0);
	}
	file_name = recv_string(cs);
	fd_file = open(file_name, O_TRUNC | O_RDWR | O_CREAT , S_IRWXU);
	msg.messagetype = 0;
	while(receive(cs, &msg) == 1)
	{
		buf = read_data2(cs, msg);
		write(fd_file, buf, msg.len);
	}
	close(fd_file);
	return(0);
}
