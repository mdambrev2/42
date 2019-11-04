/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:06:08 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/13 13:48:32 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <sys/select.h>
#include "client.h"

void	init_fd(t_env *e)
{
	e->max = 0;
	FD_ZERO(&e->fd_read);
	FD_ZERO(&e->fd_write);
	FD_SET(e->sock, &e->fd_read);
	FD_SET(STDIN_FILENO, &e->fd_read);
	if (ft_strlen(e->fds[e->sock].buf_write) > 0)
	{
		FD_SET(e->sock, &e->fd_write);
	}
}
