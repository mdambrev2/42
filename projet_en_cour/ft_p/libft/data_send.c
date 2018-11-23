/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_send.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 02:26:53 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/23 06:41:45 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>

int				init_connection(int cs)
{
	t_message	msg;

	msg.messagetype = INIT;
	msg.len = 0;
	if (send(cs, &msg, sizeof(struct s_message), 0) == -1)
		return (-1);
	return (0);
}

int				send_data(int cs, void *buf, int len)
{
	t_message	msg;
	int			test;

	msg.messagetype = DATA;
	msg.len = len;
	if (send(cs, &msg, sizeof(struct s_message), 0) == -1)
		return (-1);
	if ((test = send(cs, buf, len, 0)) == -1)
		return (-1);
	return (test);
}

int				done_connection(int cs)
{
	t_message	msg;

	msg.messagetype = DONE;
	msg.len = 0;
	if (send(cs, &msg, sizeof(struct s_message), 0) == -1)
		return (-1);
	return (0);
}

int				send_all(int cs, char *str, int cpt)
{
	init_connection(cs);
	send_data(cs, str, cpt);
	done_connection(cs);
	return (0);
}

int				send_string(int cs, char *str)
{
	int			ret;

	init_connection(cs);
	ret = send_data(cs, str, ft_strlen(str));
	done_connection(cs);
	return (ret);
}
