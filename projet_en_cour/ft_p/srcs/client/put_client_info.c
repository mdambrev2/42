/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_server_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:09:55 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/23 05:36:22 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>

char				*get_client_infos(int x, int ret, char *str)
{
	static char		*n_client = NULL;
	static char		*addr = NULL;

	if (x == 1)
	{
		if (ret == 1)
			n_client = ft_strdup(str);
		else
			return (n_client);
	}
	if (x == 2)
	{
		if (ret == 1)
			addr = ft_strdup(str);
		else
			return (addr);
	}
	if (x == -1)
	{
		ft_strdel(&n_client);
		ft_strdel(&addr);
	}
	return (NULL);
}

int					put_client_connection(int cs)
{
	t_message		msg;
	char			*buf;
	char			*folder_name;
	char			*command;

	msg.messagetype = 0;
	while (receive(cs, &msg) == 1)
	{
		buf = read_data(cs, msg);
		get_client_infos(1, 1, buf);
		folder_name = ft_strjoin("client", buf);
		command = ft_strjoin("mkdir -p ", folder_name);
		get_fork(command);
		printf("\033[1;32mClient%s : Is Now Connect\033[00m\n\n", buf);
		ft_strdel(&buf);
		ft_strdel(&folder_name);
		ft_strdel(&command);
	}
	return (0);
}
