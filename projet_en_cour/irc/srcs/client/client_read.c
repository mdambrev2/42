/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:00:43 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/13 14:32:53 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include "client.h"

int				circular_buffer(t_env *e, int cs, int r)
{
	char		*tmp;
	static int	x = 0;

	tmp = e->fds[cs].buf_read;
	if (tmp[ft_strlen(tmp) - 1] == '\n' && x == 0)
		return (r);
	else if (tmp[r - 1] != '\n')
	{
		ft_strcat(e->fds[cs].buf, e->fds[cs].buf_read);
		x = 1;
		return (0);
	}
	else if (tmp[r - 1] == '\n' && x == 1)
	{
		ft_strcat(e->fds[cs].buf, e->fds[cs].buf_read);
		ft_memcpy(e->fds[cs].buf_read, e->fds[cs].buf, BUF_SIZE);
		ft_memset(e->fds[cs].buf, 0, BUF_SIZE);
		x = 0;
		return (ft_strlen(e->fds[cs].buf_read));
	}
	return (0);
}

void			client_read(t_env *e, int cs)
{
	int			r;

	ft_bzero(e->fds[cs].buf_read, BUF_SIZE);
	r = recv(cs, e->fds[cs].buf_read, BUF_SIZE, 0);
	if (r <= 0)
	{
		close(cs);
		clean_fd(e, cs);
		printf("Serveur #%d gone away\n", cs);
		exit(0);
	}
	else
	{
		if ((r = circular_buffer(e, cs, r)) == 0)
			return ;
		ft_putstr(e->fds[cs].buf_read);
	}
}
