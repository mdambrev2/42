/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:49:00 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/12 14:49:55 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		check_fd(t_env *e)
{
	if (e->r > 0)
	{
		if (FD_ISSET(e->sock, &e->fd_read))
			e->fds[e->sock].fct_read(e, e->sock);
		if (FD_ISSET(e->sock, &e->fd_write))
			e->fds[e->sock].fct_write(e, e->sock);
		if (FD_ISSET(STDIN_FILENO, &e->fd_read))
		{
			ft_bzero(e->fds[e->sock].buf_write, BUF_SIZE);
			read(STDIN_FILENO, e->fds[e->sock].buf_write, BUF_SIZE);
			if (ft_strncmp("/connect ", e->fds[e->sock].buf_write, 9) == 0
			|| ft_strncmp("/connect\n", e->fds[e->sock].buf_write, 9) == 0)
			{
				if (client_connect(e))
					return (1);
				ft_bzero(e->fds[e->sock].buf_write, BUF_SIZE);
			}
			else
				e->fds[e->sock].fct_write(e, e->sock);
		}
	}
	return (0);
}
