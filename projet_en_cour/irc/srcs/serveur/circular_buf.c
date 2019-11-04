/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_buf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:40:30 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/13 15:55:57 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int			circular_buffer(t_env *e, int cs, int r)
{
	char	*tmp;

	tmp = e->fds[cs].buf_read;
	if (tmp[r - 1] == '\n' && e->fds[cs].set_buf == 0)
		return (r);
	else if (tmp[r - 1] != '\n')
	{
		ft_strcat(e->fds[cs].buf, e->fds[cs].buf_read);
		e->fds[cs].set_buf = 1;
		return (0);
	}
	else if (tmp[r - 1] == '\n' && e->fds[cs].set_buf == 1)
	{
		ft_strcat(e->fds[cs].buf, e->fds[cs].buf_read);
		ft_memcpy(e->fds[cs].buf_read, e->fds[cs].buf, BUF_SIZE);
		e->fds[cs].set_buf = 0;
		return (ft_strlen(e->fds[cs].buf_read));
	}
	return (0);
}
