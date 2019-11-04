/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:22:17 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/12 16:31:51 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/resource.h>
#include "serveur.h"

void				init_env(t_env *e)
{
	int				i;
	struct rlimit	rlp;

	getrlimit(RLIMIT_NOFILE, &rlp);
	e->maxfd = rlp.rlim_cur;
	e->fds = (t_fd*)malloc(sizeof(*e->fds) * e->maxfd);
	i = 0;
	while (i < e->maxfd)
	{
		clean_fd(&e->fds[i]);
		e->fds[i].set_buf = 0;
		i++;
	}
}
