/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_serv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:19:08 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/23 06:39:34 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>

int				receive(int cs, t_message *msg)
{
	int			x;

	x = 0;
	if (msg->messagetype == 0)
	{
		while (msg->messagetype != INIT)
		{
			if (recv(cs, &(*msg), sizeof(struct s_message), 0) <= 0)
				return (-1);
		}
	}
	if (recv(cs, &(*msg), sizeof(struct s_message), 0) <= 0)
		return (-1);
	if (msg->messagetype == DATA)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

char			*read_data(int cs, t_message msg)
{
	char		*buf;
	int			test;

	buf = ft_memalloc(msg.len);
	ft_bzero(buf, msg.len);
	if ((test = recv(cs, buf, msg.len, 0)) <= 0)
	{
		ft_strdel(&buf);
		return (NULL);
	}
	if (buf[msg.len - 1] == '\n')
		buf[msg.len - 1] = '\0';
	else
		buf[msg.len] = '\0';
	return (buf);
}

char			*read_data2(int cs, t_message msg)
{
	char		*buf;

	buf = ft_memalloc(msg.len);
	ft_bzero(buf, msg.len);
	if (recv(cs, buf, msg.len, 0) <= 0)
	{
		ft_strdel(&buf);
		return (NULL);
	}
	return (buf);
}

char			*recv_string(int cs)
{
	t_message	msg;
	char		*buf;

	msg.messagetype = 0;
	buf = NULL;
	while (receive(cs, &msg) == 1)
		buf = read_data(cs, msg);
	return (buf);
}

int				read_instruction(int sock)
{
	char		*line;

	line = NULL;
	while (get_next_line(sock, &line) == 1)
	{
		if (line[0] == EOF)
			break ;
		if (line[0] == -2)
		{
			ft_strdel(&line);
			return (-1);
		}
		ft_putendl(line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (0);
}
