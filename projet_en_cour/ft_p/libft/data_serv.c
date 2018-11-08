/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_serv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:19:08 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/07 23:02:58 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <stdio.h>

void    init_connection(int cs)
{
	t_message msg;

	msg.messagetype = INIT;
	send(cs, &msg, sizeof(struct s_message), 0);
}

void    send_data(int cs, void *buf, int len)
{
	t_message msg;

	msg.messagetype = DATA;
	msg.len = len;
	send(cs, &msg, sizeof(struct s_message), 0);
	send(cs, buf, len, 0);

}

void    done_connection(int cs)
{
	t_message msg;

	msg.messagetype = DONE;
	send(cs, &msg, sizeof(struct s_message), 0);
}

int             receive(int cs, t_message *msg)
{
	int x;

	x = 0;
	if(msg->messagetype == 0)
	{
		while(msg->messagetype != INIT)
		{
			if(recv(cs, &(*msg), sizeof(struct s_message), 0) <= 0)
				return(-1);
		}
	}
	if(recv(cs, &(*msg), sizeof(struct s_message), 0) <= 0)
		return(-1);
	if(msg->messagetype == DATA)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

char	*read_data(int cs, t_message msg)
{
	char *buf;

	buf = ft_memalloc(msg.len);
	ft_bzero(buf, msg.len);
	if(recv(cs, buf, msg.len, 0) <= 0)
		return(NULL);
	if(buf[msg.len - 1] == '\n')
		buf[msg.len - 1] = '\0';
	else
		buf[msg.len] = '\0';
	return(buf);
}

int		send_string(int cs, char *str)
{
	init_connection(cs);
	send_data(cs, str, ft_strlen(str));
	done_connection(cs);
	return(0);
}

char 	*recv_string(int cs)
{
	t_message   msg;
	char        *buf;

	msg.messagetype = 0;
	while(receive(cs, &msg) == 1)
	{
		buf = read_data(cs, msg);
	}
	return(buf);
}
