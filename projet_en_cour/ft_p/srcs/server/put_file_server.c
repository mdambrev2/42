/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_file_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 00:18:04 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/20 02:00:39 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

char *rase_path(char *str)
{
	int x;
	char *ret;

	ret = NULL;
	x = 0;
	while(str[x] != '\0')
		x++;
	while(str[x] != '/')
		x--;
	return(str + x + 1);
}

char		*name_nopath(char *str)
{
	int x;

	x = 0;
	while(str[x])
	{
		if(str[x] == '/')
			return(rase_path(str));
		x++;
	}
	return(str);
}

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
	file_name = ft_strdup(name_nopath(recv_string(cs)));
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
