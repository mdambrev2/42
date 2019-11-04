/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:01:41 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/13 12:24:05 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "client.h"

void	client_write(t_env *e, int cs)
{
	send(cs, e->fds[cs].buf_write, ft_strlen(e->fds[cs].buf_write), 0);
	ft_bzero(e->fds[cs].buf_write, BUF_SIZE);
}
