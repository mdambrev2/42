/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:35:08 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/13 15:56:00 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include "serveur.h"
#include <string.h>
#include <stdlib.h>

int			add_name(t_env *e, int cs)
{
	char	*str;
	int		ret;
	char	tmp[BUF_SIZE];

	ft_memset(tmp, 0, BUF_SIZE);
	ft_memcpy(tmp, e->fds[cs].buf_read, BUF_SIZE);
	ft_memset(e->fds[cs].buf_read, 0, BUF_SIZE);
	str = get_client_name(e, cs);
	ft_strcat(e->fds[cs].buf_read, str);
	ft_strcat(e->fds[cs].buf_read, ": ");
	ft_strcat(e->fds[cs].buf_read, tmp);
	ret = ft_strlen(str);
	free(str);
	return (ret + 2);
}

int			add_name_circular_buf(t_env *e, int cs)
{
	char	*str;
	int		ret;
	char	tmp[BUF_SIZE];

	ft_memset(tmp, 0, BUF_SIZE);
	ft_memcpy(tmp, e->fds[cs].buf, BUF_SIZE);
	ft_memset(e->fds[cs].buf, 0, BUF_SIZE);
	str = get_client_name(e, cs);
	ft_strcat(e->fds[cs].buf, str);
	ft_strcat(e->fds[cs].buf, ": ");
	ft_strcat(e->fds[cs].buf, tmp);
	ret = ft_strlen(str);
	free(str);
	return (ret + 2);
}

void		rase_infos(t_env *e, int cs)
{
	ft_memset(e->fds[cs].buf_read, 0, BUF_SIZE);
	ft_memset(e->fds[cs].buf_write, 0, BUF_SIZE);
	free(e->fds[cs].name);
	free(e->fds[cs].chan);
	e->fds[cs].name = NULL;
}

void		close_client(t_env *e, int cs)
{
	char *str;

	str = client_leave_message(e, cs);
	write_all_client_in_chan(e, cs, str, ft_strlen(str));
	rase_infos(e, cs);
	close(cs);
	clean_fd(&e->fds[cs]);
}

void		client_read(t_env *e, int cs)
{
	int		r;

	ft_memset(e->fds[cs].buf_read, 0, BUF_SIZE);
	r = recv(cs, e->fds[cs].buf_read, BUF_SIZE, 0);
	if (r <= 0 || e->fds[cs].buf_read[0] == 127)
		close_client(e, cs);
	else
	{
		if ((r = circular_buffer(e, cs, r)) == 0)
			return ;
		if (e->fds[cs].buf_read[0] != '/' && ft_strlen(e->fds[cs].buf) == 0)
		{
			r += add_name(e, cs);
			write_all_client_in_chan(e, cs, ft_strdup(e->fds[cs].buf_read), r);
		}
		else if (e->fds[cs].buf_read[0] != '/' && ft_strlen(e->fds[cs].buf) > 0)
		{
			r += add_name_circular_buf(e, cs);
			write_all_client_in_chan(e, cs, ft_strdup(e->fds[cs].buf), r);
			ft_memset(e->fds[cs].buf, 0, BUF_SIZE);
		}
		else
			go_cmd(e, cs);
	}
}
