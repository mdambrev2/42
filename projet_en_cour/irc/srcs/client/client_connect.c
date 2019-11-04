/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_connect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 14:46:43 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/13 12:05:00 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	cmp_addr_port(t_env *e)
{
	if (ft_strcmp(e->fds[e->sock].new_addr, "localhost") == 0)
	{
		free(e->fds[e->sock].new_addr);
		e->fds[e->sock].new_addr = ft_strdup("127.0.0.1");
	}
	return (0);
}

int	client_connect(t_env *e)
{
	char	*port;
	char	*addr;

	if ((addr = get_occu_by_delim(e->fds[e->sock].buf_write, ' ', 2)) == NULL
	|| (port = get_occu_by_delim(e->fds[e->sock].buf_write, ' ', 3)) != NULL)
		printf("Error /connect Usage : /connect <Addr> <Port>\n");
	else
	{
		port = dup_occu_by_delim(e->fds[e->sock].buf_write, ' ', 2);
		addr = dup_occu_by_delim(e->fds[e->sock].buf_write, ' ', 1);
		e->fds[e->sock].new_port = ft_atoi(port);
		if (e->fds[e->sock].new_addr)
			free(e->fds[e->sock].new_addr);
		e->fds[e->sock].new_addr = addr;
		cmp_addr_port(e);
		free(port);
		return (1);
	}
	return (0);
}
