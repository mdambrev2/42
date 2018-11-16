/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_serv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:19:08 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/16 05:12:51 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>

int    init_connection(int cs)
{
	t_message msg;

	msg.messagetype = INIT;
	if(send(cs, &msg, sizeof(struct s_message), 0) == -1)
		return(-1);
	return(0);
}

int    send_data(int cs, void *buf, int len)
{
	t_message msg;
	int test;

	msg.messagetype = DATA;
	msg.len = len;
	if(send(cs, &msg, sizeof(struct s_message), 0) == -1)
		return(-1);
	if((test = send(cs, buf, len, 0)) == -1)
		return(-1);
	return(test);
}

int    done_connection(int cs)
{
	t_message msg;

	msg.messagetype = DONE;
	if(send(cs, &msg, sizeof(struct s_message), 0) == -1)
		return(-1);
	return(0);
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

char	*read_data2(int cs, t_message msg)
{
	char *buf;

	buf = ft_memalloc(msg.len);
	ft_bzero(buf, msg.len);
	if(recv(cs, buf, msg.len, 0) <= 0)
		return(NULL);
	return(buf);
}



int		send_all(int cs, char *str, int cpt)
{
	init_connection(cs);
	send_data(cs, str, cpt);
	done_connection(cs);
	return(0);
}


int		send_string(int cs, char *str)
{
	int ret;

	init_connection(cs);
	ret = send_data(cs, str, ft_strlen(str));
	done_connection(cs);
	return(ret);
}

char 	*recv_string(int cs)
{
	t_message   msg;
	char        *buf;

	msg.messagetype = 0;
	while(receive(cs, &msg) == 1)
		buf = read_data(cs, msg);
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
		ft_putendl(line);
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


