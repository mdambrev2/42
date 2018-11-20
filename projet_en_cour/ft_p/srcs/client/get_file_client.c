/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 00:03:37 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/20 00:24:03 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int		get_file_client(int cs)
{
	char *buf;
	char *file_name;
	int			fd_file;
	t_message   msg;


	buf = recv_string(cs);
	if(buf != NULL)
	{
		printf("%s\n", buf);
		return(0);
	}
	file_name = recv_string(cs);
	printf("\nSucess: Files \"%s\" Received  \n\n", file_name);
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
