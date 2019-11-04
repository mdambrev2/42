/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:05:42 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/13 13:36:23 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/resource.h>
#include "client.h"

void		init_env(t_env *e, int port, char *addr)
{
	struct rlimit	rlp;

	getrlimit(RLIMIT_NOFILE, &rlp);
	e->maxfd = rlp.rlim_cur;
	e->fds = (t_fd*)malloc(sizeof(*e->fds) * e->maxfd);
	clean_fd(e, e->sock);
	clean_fd(e, 1);
	e->fds[e->sock].fct_write = client_write;
	e->fds[e->sock].fct_read = client_read;
	e->fds[e->sock].new_addr = ft_strdup(addr);
	e->fds[e->sock].new_port = port;
}
