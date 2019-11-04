/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:30:24 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/13 12:25:25 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	check_fd(t_env *e)
{
	int	i;

	i = 0;
	while ((i < e->max + 1) && (e->r > 0))
	{
		if (FD_ISSET(i, &e->fd_read))
		{
			e->fds[i].fct_read(e, i);
		}
		if (FD_ISSET(i, &e->fd_write))
		{
			e->fds[i].fct_write(e, i);
		}
		if (FD_ISSET(i, &e->fd_read) ||
				FD_ISSET(i, &e->fd_write))
			e->r--;
		i++;
	}
}
