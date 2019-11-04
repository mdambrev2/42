/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:23:41 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/13 15:02:03 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int			close_server(t_env *e)
{
	char	buf[BUF_SIZE];

	buf[0] = 127;
	buf[1] = '\0';
	send(e->sock, buf, 2, 0);
	return (0);
}

void		main_loop(t_env *e)
{
	int		ret;

	ret = 0;
	while (1)
	{
		init_fd(e);
		do_select(e);
		if (check_fd(e))
		{
			clean_fd(e, e->sock);
			close_server(e);
			run_client(e->fds[e->sock].new_port, e->fds[e->sock].new_addr);
			break ;
		}
	}
}
