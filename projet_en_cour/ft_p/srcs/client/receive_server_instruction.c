/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_server_instruction.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 20:08:35 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/23 05:51:57 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

char			*read_server(int cs, t_message msg)
{
	char		*buf;

	buf = ft_memalloc(msg.len);
	ft_bzero(buf, msg.len);
	recv(cs, buf, msg.len, 0);
	buf[msg.len - 1] = '\0';
	return (buf);
}

void			put_server_message(int sock)
{
	char		*buf;

	buf = recv_string(sock);
	if (buf[0] == '1')
		printf("\033[1;31m[Server return : Error]\033[00m\n\n");
	else
		printf("\033[1;32m[Server return : Sucess]\033[00m\n\n");
	ft_strdel(&buf);
}

int				is_builtin_cmd(int sock, char *str)
{
	if (ft_strcmp(str, "GOOD BUILTINS") == 0)
	{
		if (read_instruction(sock) == -1)
		{
			ft_strdel(&str);
			return (-1);
		}
	}
	else if (ft_strcmp(str, "GET") == 0)
		get_file_client(sock);
	else if (ft_strcmp(str, "PUT") == 0)
		put_file_client(sock);
	else
		printf("error recieve server\n");
	return (0);
}

int				receive_server_instruction(int sock)
{
	char		*str;

	str = recv_string(sock);
	if (str == NULL)
	{
		printf("\n\033[1;31mServer : Offline\033[00m\n\n");
		ft_strdel(&str);
		return (-1);
	}
	if (ft_strcmp(str, "GOOD CMD") == 0)
	{
		read_instruction(sock);
		printf("\n");
	}
	else if (ft_strcmp(str, "BAD CMD") == 0)
		printf("\n\033[1;33mServer -- command not found\033[00m\n\n");
	else if (is_builtin_cmd(sock, str) == -1)
		return (-1);
	ft_strdel(&str);
	send_string(sock, "tempo");
	put_server_message(sock);
	return (0);
}
