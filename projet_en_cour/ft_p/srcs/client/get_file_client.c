/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 00:03:37 by mdambrev          #+#    #+#             */
/*   Updated: 2019/04/11 17:28:41 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

char			*rase_path(char *str)
{
	int			x;
	char		*ret;

	ret = NULL;
	x = 0;
	while (str[x] != '\0')
		x++;
	while (str[x] != '/')
		x--;
	return (str + x + 1);
}

char			*name_nopath(char *str)
{
	int			x;

	x = 0;
	while (str[x])
	{
		if (str[x] == '/')
			return (rase_path(str));
		x++;
	}
	return (str);
}

char			*get_pwd_client(char *file_name)
{
	char		*tmp1;
	char		*tmp2;
	char		*tmp3;

	tmp1 = ft_strjoin("client", get_client_infos(1, 0, NULL));
	tmp2 = ft_strjoin(tmp1, "/");
	tmp3 = ft_strjoin(tmp2, file_name);
	ft_strdel(&tmp1);
	ft_strdel(&tmp2);
	return (tmp3);
}

int				check_error(int cs)
{
	char		*buf;

	buf = recv_string(cs);
	if (buf != NULL)
	{
		printf("%s\n", buf);
		ft_strdel(&buf);
		return (1);
	}
	return (0);
}

int				get_file_client(int cs)
{
	char		*buf;
	char		*file_name;
	int			fd_file;
	t_message	msg;

	if (check_error(cs))
		return (0);
	buf = recv_string(cs);
	file_name = name_nopath(buf);
	printf("\nSucess: Files \"%s\" Received  \n\n", file_name);
	file_name = get_pwd_client(file_name);
	ft_strdel(&buf);
	fd_file = open(file_name, O_TRUNC | O_RDWR | O_CREAT, S_IRWXU);
	ft_strdel(&file_name);
	msg.messagetype = 0;
	while (receive(cs, &msg) == 1)
	{
		buf = read_data2(cs, msg);
		write(fd_file, buf, msg.len);
		ft_strdel(&buf);
	}
	close(fd_file);
	return (0);
}
