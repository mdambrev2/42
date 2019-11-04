/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:45:53 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/13 15:27:43 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "serveur.h"

void	write_all_client_with_cs(t_env *e, char *message, int len)
{
	int i;

	i = 0;
	while (i < e->maxfd)
	{
		if (e->fds[i].type == FD_CLIENT)
		{
			ft_memcpy(e->fds[i].buf_write
					+ ft_strlen(e->fds[i].buf_write), message, len);
		}
		i++;
	}
	free(message);
}

void	write_all_client_in_chan(t_env *e, int cs, char *message, int len)
{
	int i;

	i = 0;
	while (i < e->maxfd)
	{
		if (e->fds[i].type == FD_CLIENT
				&& (i != cs)
				&& ft_strcmp(e->fds[i].chan, e->fds[cs].chan) == 0)
		{
			ft_memcpy(e->fds[i].buf_write
					+ ft_strlen(e->fds[i].buf_write), message, len);
		}
		i++;
	}
	free(message);
}

void	write_all_client_in_chan_with_cs(t_env *e, int cs,
											char *message, int len)
{
	int i;

	i = 0;
	while (i < e->maxfd)
	{
		if (e->fds[i].type == FD_CLIENT
				&& ft_strcmp(e->fds[i].chan, e->fds[cs].chan) == 0)
		{
			ft_memcpy(e->fds[i].buf_write
					+ ft_strlen(e->fds[i].buf_write), message, len);
		}
		i++;
	}
	free(message);
}

void	write_cs(t_env *e, int cs, char *message, int len)
{
	int i;

	i = 0;
	while (i < e->maxfd)
	{
		if (e->fds[i].type == FD_CLIENT
				&& (i == cs))
		{
			ft_memcpy(e->fds[i].buf_write
					+ ft_strlen(e->fds[i].buf_write), message, len);
			break ;
		}
		i++;
	}
	free(message);
}

void	client_write(t_env *e, int cs)
{
	send(cs, e->fds[cs].buf_write, ft_strlen(e->fds[cs].buf_write), 0);
	ft_bzero(e->fds[cs].buf_write, BUF_SIZE);
}
