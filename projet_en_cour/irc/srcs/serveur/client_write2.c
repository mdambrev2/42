/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_write2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:25:37 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/13 15:27:14 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>

void	write_all_client(t_env *e, int cs, char *message, int len)
{
	int i;

	i = 0;
	while (i < e->maxfd)
	{
		if ((e->fds[i].type == FD_CLIENT) &&
				(i != cs))
		{
			ft_memcpy(e->fds[i].buf_write
					+ ft_strlen(e->fds[i].buf_write), message, len);
		}
		i++;
	}
	free(message);
}
