/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_server_instruction.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 20:08:35 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/06 20:21:00 by mdambrev         ###   ########.fr       */
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


int		receive_server_instruction(int sock)
{
	t_message   msg;
	char        *buf;

	msg.messagetype = 0;
	while(receive(sock, &msg) == 1)
	{
		buf = read_data(sock, msg);
		printf("receive to server --> %s\n", buf);
	}
	return(0);
}
