/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_file_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 00:03:37 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/20 20:36:43 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int			check_args_put(int cs,char *cmd)
{
	int file;
	char buf[1024];
	char *tmp;
	char *tmp2;

	if((file = open(get_occu_by_delim(cmd, ' ', 1), O_DIRECTORY | O_RDONLY)) > 0)
	{
		close(file);
		tmp = ft_strjoin(get_occu_by_delim(cmd, ' ', 1)," Is a directory - usage: put < file > \n");
		tmp2 = ft_strjoin("\n", tmp);
		ft_strcpy(buf, tmp2);
		send_string(cs, buf);
	}
	else if((file = open(get_occu_by_delim(cmd, ' ', 1),  O_RDONLY)) > 0)
	{
		close(file);
		printf("\nSucess: Files \"%s\" Send  \n\n", get_occu_by_delim(cmd, ' ', 1));
		send_string(cs, "\0");
		return(0);
	}
	else if(get_occu_by_delim(cmd, ' ', 1) == NULL)
	{
		ft_strcpy(buf, "\nMissing args - usage: put < file >\n"); 
		send_string(cs, buf);
	}
	else if(get_occu_by_delim(cmd, ' ', 2))
	{
		ft_strcpy(buf, "\nToo many args - usage: put < file >\n");
		send_string(cs, buf);
	}
	else
	{
		ft_strcpy(buf,"\nNo such files - usage: put < file >\n");
		send_string(cs, buf);
	}
	printf("%s\n", buf);
	return(-1);
}	

int			put_file_client(int cs)
{
	char *buf;
	int fd_file;
	int n_octet;
	char *cmd;

	cmd = recv_string(cs);
	if(check_args_put(cs, cmd) == -1)
	{
		return(0);
	}
	send_string(cs, get_occu_by_delim(cmd, ' ', 1));
	buf = (char*)malloc(sizeof(char) * (1024));
	fd_file = open(get_occu_by_delim(cmd, ' ', 1), O_RDWR , S_IRWXU);	
	init_connection(cs);
	ft_bzero(buf, 1024);
	while((n_octet = read(fd_file, buf, 1024)) > 0)
	{
		send_data(cs, buf, n_octet);
		ft_bzero(buf, 1024);
	}
	done_connection(cs);
	close(fd_file);
	return(0);
}
