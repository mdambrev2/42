/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_server_instruction.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 20:08:35 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/14 00:44:45 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"


char    *read_server(int cs, t_message msg)
{
	char *buf;

	buf = ft_memalloc(msg.len);
	ft_bzero(buf, msg.len);
	recv(cs, buf, msg.len, 0);
	buf[msg.len - 1] = '\0';
	return(buf);
}


int		read_instruction(int sock)
{
	char		*line;

	while(get_next_line(sock, &line) == 1)
	{
		if(line[0] == EOF)
			break;
		if(line[0] == -2)
			return(-1);
		printf("%s\n", line);
	}
	return(0);
}


char 			*recv_instruction(int sock)
{
	t_message   msg;
	char        *buf;

	msg.messagetype = 0;
	while(receive(sock, &msg) == 1)
		buf = read_data(sock, msg);
	return(buf);
}



int		receive_server_instruction(int sock)
{
	char *str;

	str = recv_instruction(sock);
	if(str == NULL)
		return(-1);
	if(ft_strcmp(str, "GOOD CMD") == 0)
	{
		read_instruction(sock);
	}
	else if(ft_strcmp(str, "BAD CMD") == 0)
	{
		printf("BAD CMD\n");
	}
	else if(ft_strcmp(str, "GOOD BUILTINS") == 0)
	{
		if(read_instruction(sock) == -1)
			return(-1);
	}
	else if(ft_strcmp(str, "GET") == 0)
	{
		get_file_client(sock);
	}
	else if(ft_strcmp(str, "PUT") == 0)
	{
		put_file_client(sock);
	}
	else
	{
		printf("error recieve server\n");
	}
	return(0);
}
