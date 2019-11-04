/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:50:39 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/13 14:31:59 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "client.h"

void	clean_fd(t_env *e, int cs)
{
	e->fds[cs].type = FD_FREE;
	e->fds[cs].fct_read = NULL;
	e->fds[cs].fct_write = NULL;
	ft_memset(e->fds[cs].buf_write, 0, BUF_SIZE + 1);
	ft_memset(e->fds[cs].buf_read, 0, BUF_SIZE + 1);
}
